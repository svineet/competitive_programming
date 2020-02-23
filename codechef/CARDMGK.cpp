#include <bits/stdc++.h>
using namespace std;

int arr[100200];

int main(int argc, char **argv) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        for (int i=0; i<n; i++)
            cin >> arr[i];

        bool inc[n], dec[n];
        int lmin[n], rmax[n];
        inc[0] = true; // arr[0..0] is increasing by definition
        lmin[0] = arr[0];
        for (int i=1; i<n; i++) {
            inc[i] = inc[i-1] && (arr[i] >= arr[i-1]);
            lmin[i] = min(lmin[i-1], arr[i]);
        }

        dec[n-1] = true;
        rmax[n-1] = arr[n-1];
        for (int i=n-2; i>=0; i--) {
            dec[i] = dec[i+1] && (arr[i+1] >= arr[i]);
            rmax[i] = max(rmax[i+1], arr[i]);
        }

        bool done = false;
        for (int i=0; i<n-1 && !done; i++) {
            //cout << inc[i] << " " << dec[i+1] << endl;
            //cout << rmax[i+1] << " " << lmin[i] << endl;
            if (inc[i] && dec[i+1] && rmax[i+1] <= lmin[i]) {
                cout << "YES" << endl;
                done = true;
            }
        }

        if (!done) {
            if (inc[n-1]) {
                cout << "YES\n";
                // cout << "burh\n";
            } else {
                cout << "NO\n";
            }
        }
    }

    return 0;
}
