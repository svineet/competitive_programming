#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n, k, d; cin >> n >> k >> d;
    long long MODULO = 1000000007;

    long long dp[n+1][2];
    // dp[i][0] is the number of ways to get i without
    // satisfying an edge was over d.
    // dp[i][1] is the number of ways with one or more
    // edges satisfied by the condition.
    dp[0][0] = 1; // 1 way only to get i
    dp[0][1] = (n==0);
    for (int i=1; i<=n; i++) {
        dp[i][0] = dp[i][1] = 0; // Garbage values
        for (int cand=1; cand<=min(i, k); cand++) {
            if (cand<d) {
                dp[i][0] += dp[i-cand][0]; // Stay dissatisfied
            }

            if (cand>=d) {
                dp[i][1] += dp[i-cand][0];
            }
            dp[i][1] += dp[i-cand][1];
        }
        dp[i][0] %= MODULO;
        dp[i][1] %= MODULO;
    }
    cout << dp[n][1] << endl;

    return 0;
}
