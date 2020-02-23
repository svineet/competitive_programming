#include <bits/stdc++.h>
using namespace std;

int main(int argc, char **argv) {
    int t; cin >> t;
    while (t--) {
        int n, d; cin >> n >> d;

        int arr[n];
        for (int i=0; i<n; i++)
            cin >> arr[i];

        int ans = arr[0];
        for (int i=1; i<n; i++) {
            if (d) {
                // Will take i days
                int x = min(d/i, arr[i]); // Max that can be taken
                ans += x;
                d -= i*x;
                // cout << "X" << " " << x << endl;
            } else {
                break;
            }
        }

        cout << ans << endl;
    }

    return 0;
}
