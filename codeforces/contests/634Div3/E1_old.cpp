#include <bits/stdc++.h>
using namespace std;


int main(int argc, char **argv) {
    ios::sync_with_stdio(false);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        int arr[n];
        for (int i=0; i<n; i++) cin >> arr[i];

        int dpB[n][n][27]; // (start, end, character)
        int dpA[n][n][27]; // Same structure

        for (int i=0; i<n; i++)
            for (int j=0; j<n; j++)
                for (int k=0; k<27; k++)
                    dpA[i][j][k] = dpB[i][j][k] = 0;

        // Cover length 1 B type palindromes
        for (int i=0; i<n; i++) {
            for (int j=1; j<27; j++) {
                if (i-1>0) {
                    dpB[i][i-1][j] = 0; // Zero length palin base case
                }

                dpB[i][i][j] = (arr[i] == j)? 1: 0; // 1 length palins
            }
        }

        for (int length=2; length<=n; length++) {
            for (int start=0; start<n; start++) {
                // Length palin starting at i: [i, i+length-1]
                int end = start+length-1;
                // cout << start <<  " " << end << endl << flush;
                if (end >= n) break;

                for (int num=1; num<27; num++) {
                    dpB[start][end][num] = max(dpB[start+1][end][num], dpB[start][end-1][num]);
                }

                // cout << start <<  " " << end << endl << flush;
                // cout << arr[start] << endl << flush;
                if (arr[start] == arr[end]) {
                    // cout << arr[start] << endl << flush;
                    dpB[start][end][arr[start]] += 2;
                }
            }
        }

        cout << dpB[3][4][2] << endl;
        cout << dpB[3][4][3] << endl;
        /*
        for (int i=1; i<27; i++)
            cout << i << " " << dpB[0][n-1][i] << endl;
        */


        for (int length=2; length<=n; length++) {
            for (int start=0; start<n; start++) {
                // Length palin starting at i: [i, i+length-1]
                int end = start+length-1;
                // cout << start <<  " " << end << endl << flush;
                if (end >= n) break;

                for (int num=1; num<27; num++) {
                    dpA[start][end][num] = max(dpA[start+1][end][num], dpB[start][end-1][num]);
                    dpA[start][end][num] = max(dpA[start][end][num], max(dpA[start][end-1][num], dpB[start+1][end][num]));
                }

                // cout << start <<  " " << end << endl << flush;
                // cout << arr[start] << endl << flush;
                if (arr[start] == arr[end]) {
                    // cout << arr[start] << endl << flush;
                    // Best number dpB from prev
                    int pmax = dpB[start+1][end-1][1];
                    for (int num=2; num<27; num++) {
                        if (num != arr[start]) pmax = max(pmax, dpB[start+1][end-1][num]);
                    }

                    dpA[start][end][arr[start]] = 2+max(dpA[start+1][end-1][arr[start]], pmax);
                } else {
                }
            }
        }

        int mex = dpA[0][n-1][1];
        for (int num=2; num<27; num++) mex = max(mex, dpA[0][n-1][num]);
        cout << mex << endl;
    }

    return 0;
}

