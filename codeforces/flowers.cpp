#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1e9+7;

int main() {
    int t, k; cin >> t >> k;
    long long dp[(int)1e5+5];
    long long partial[(int)1e5+5];
    dp[0] = 1; partial[0] = 1;
    for (int i=1; i<(int)1e5+2; i++) {
        dp[i] += dp[i-1] + (i-k>=0?dp[i-k]:0);
        dp[i] %= MOD;
        partial[i] = dp[i] + partial[i-1];
        partial[i] %= MOD;
    }

    while (t--) {
        int l, r; cin >> l >> r;
        cout << (partial[r]-partial[l-1]+MOD)%MOD << endl;
    }

    return 0;
}
