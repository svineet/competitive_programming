#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, l, r, ql, qr;
    cin >> n >> l >> r >> ql >> qr;
    int W[n];
    for (int i=0; i<n; i++) cin >> W[i];
    
    long long lsum[n], rsum[n];
    for (int i=0; i<n; i++) {
        lsum[i] = (i>0?lsum[i-1]:0) + W[i];
        rsum[i] = (i>0?rsum[i-1]:0) + W[n-i-1];
    }

    long long best = 1e18;
    for (int i=0; i<=n; i++) {
        long long cost = (i>0?lsum[i-1]:0)*l + (n-i-1>=0?rsum[n-i-1]:0)*r;
        // i lefts and n-i rights
        if (i > n-i) {
            cost += (2*i-n-1)*ql;
        } else if (i < n-i) {
            cost += (n-2*i-1)*qr;
        }
        best = min(best, cost);
    }
    cout << best << endl;

    return 0;
}
