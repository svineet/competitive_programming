#include <bits/stdc++.h>
using namespace std;

int main(int argc, char **argv) {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        long long arr[n];
        for (int i=0; i<n; i++)
            cin >> arr[i];

        int mex = 0;
        for (int i=1; i<n; i++) {
            if (arr[i] < arr[i-1]) {
                // Change this number in one of the seconds
                long long cpy = arr[i-1]-arr[i];
                for (int j=0; j<35; j++)
                    if ((cpy >> j) & 1) mex = max(mex, j+1);

                arr[i] = arr[i-1];
            }
        }

        cout << mex << endl;
    }

    return 0;
}

