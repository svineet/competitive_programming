#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    long long arr[n];
    for (int i=0; i<n; i++) cin >> arr[i];

    long long  mx = *max_element(arr, arr+n);
    long long cnt = 0;
    for (int i=0; i<n; i++) {
        if (arr[i]<mx) cnt += mx-arr[i];
    }
    cout << cnt << endl;

    return 0;
}
