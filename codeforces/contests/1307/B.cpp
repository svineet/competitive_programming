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

        int left = x;
        int jumps = 0, i=0;
        while (left > 0 && i < n) {
            // Use this element as much as possible
            int use = left/arr[i];
            cout << arr[i] << " " << use << endl;

            if (use == 0) {
                // We can just use this twice to reach now.
                jumps += 2; break;
            } else {
                left -= use*arr[i];
                jumps += use;
            }

            i++;
        }

        cout << "J " << jumps << endl;
    }

    return 0;
}

