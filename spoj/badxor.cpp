#include <bits/stdc++.h>
using namespace std;

const long long MOD = 100000007;

int main() {
    int t; cin >> t;
    int oldt = t;
    while (t--) {
        int n, m; cin >> n >> m;
        bool inB[4000];
        memset(inB, 0, sizeof inB);
        int array[n];
        for (int i=0; i<n; i++) cin >> array[i];
        for (int i=0; i<m; i++) {
            int lel; cin >> lel;
            inB[lel] = true;
        }

        int dp[n+1][1024];
        memset(dp, 0, sizeof dp);
        dp[0][0] = 1;
        for (int i=1; i<=n; i++) {
            for (int j=0; j<1024; j++) {
                dp[i][j] += dp[i-1][j] + dp[i-1][j^array[i-1]];
                dp[i][j] %= MOD;
            }
        }

        long long cnt = 0;
        for (int i=0; i<1024; i++) {
            if (!inB[i]) {
                cnt += dp[n][i];
                cnt %= MOD;
            }
        }

        cout << "Case " << oldt-t << ": " << cnt << endl;
    }

    return 0;
}
