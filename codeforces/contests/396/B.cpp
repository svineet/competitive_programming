#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    int arr[n];
    for (int i=0; i<n; i++)
        cin >> arr[i];

    sort (arr, arr+n);
    for (int i=1; i<n-1; i++) {
        int fnd = arr[i]+arr[i-1];
        int dex = lower_bound(arr, arr+n,
                              fnd)-arr-1;
        if (dex>i) {
            cout << "YES" << endl;
            return 0;
        }
    }
    cout << "NO" << endl;

    return 0;
}
