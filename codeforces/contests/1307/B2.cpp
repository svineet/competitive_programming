#include <bits/stdc++.h>
using namespace std;

int main(int argc, char **argv) {
    int t; cin >> t;
    while (t--) {
        int n, x; cin >> n >> x;
        int arr[n];
        for (int i=0; i<n; i++)
            cin >> arr[i];

        sort (arr, arr+n, greater<int>());
        int m = arr[0];

        bool there = false;
        for (int i=0; i<n; i++) {
            there = (there || (arr[i] == x));
            // cout << arr[i];
        }

        if (there) {
            cout << 1 << endl;
            continue;
        }

        cout << max(2, (x+m-1)/m) << endl;
    }

    return 0;
}

