#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    pair<int, int> arr[n];
    for (int i=0; i<n; i++)
        cin >> arr[i].first >> arr[i].second;
    sort (arr, arr+n);

    int mx = arr[0].second;
    for (int i=0; i<n; i++) {
        if (mx > arr[i].second) {
            cout << "Happy Alex" << endl;
            return 0;
        }
        mx = max(mx, arr[i].second);
    }

    cout << "Poor Alex" << endl;

    return 0;
}
