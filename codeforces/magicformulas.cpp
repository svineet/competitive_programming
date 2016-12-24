#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    int n; cin >> n;
    long long pre[n+1];

    pre[0] = 0;
    for (int i=1; i<=n; i++)
        pre[i] = i^pre[i-1];

    long long res = 0;
    for (int i=1; i<=n; i++) {
        int x; cin >> x;
        res ^= x;
        long long div = n/i, rem = n%i;
        if (div%2==1) {
            res ^= pre[i-1];
        }
        res ^= pre[rem];
    }
    cout << res << endl;

    return 0;
}
