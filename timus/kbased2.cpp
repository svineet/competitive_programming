#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k; cin >> n >> k;
    long long dp[n+1][k+1];
    // dp[i][j] is the number of
    // valid numbers if we use
    // j as the i-th digit.
    dp[1][0] = 0;
    for (int i=1; i<k; i++)
        dp[1][i] = 1;

    for (int i=2; i<=n; i++) {
        for (int j=0; j<k; j++) {
            dp[i][j] = 0;
            for (int w=0; w<k; w++) {
                if (j==0 && w==0) continue;
                // No consecutive zeroes
                dp[i][j] += dp[i-1][w];
            }
        }
    }
    long long tot = 0;
    for (int i=0; i<k; i++)
        tot += dp[n][i];
    cout << tot << endl;

    return 0;
}
