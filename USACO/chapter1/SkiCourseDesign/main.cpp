/*
ID: saivine1
PROG: skidesign
LANG: C++11
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("skidesign.in", "r", stdin);
    freopen("skidesign.out", "w", stdout);

    int n; cin >> n;
    int arr[n];
    for (int i=0; i<n; i++) cin >> arr[i];

    long long best = 1e18;
    for (int i=0; i<=100; i++) {
        // Considering i..i+17 to be the mountain range.
        long long cnt = 0;
        for (int j=0; j<n; j++) {
            if (arr[j]>=i && arr[j]<=i+17) {
                cnt += 0;
                // Just for representation
            } else if (i+17<arr[j]) {
                cnt += (arr[j]-i-17)*(arr[j]-i-17);
            } else if (i>arr[j]) {
                cnt += (arr[j]-i)*(arr[j]-i);
            }
        }
        best = min(best, cnt);
    }
    cout << best << endl;

    return 0;
}
