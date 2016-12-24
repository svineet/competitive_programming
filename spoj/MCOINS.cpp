#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int k, l, m;
    cin >> k >> l >> m;
    bool dp[2][1000005]; // 0 is Asen, 1 is Boyan
    dp[0][0] = dp[1][0] = false;
    for (int i=1; i<1000005; i++) {
        dp[0][i] = (!dp[1][i-1]);
        // Remove one and see if Boyan loses.
        // if he does, awesome. Asen can win this one.
        dp[1][i] = (!dp[0][i-1]);
        // Similar logic
        if (i>=k) {
            dp[0][i] = dp[0][i] || (!dp[1][i-k]);
            dp[1][i] = dp[1][i] || (!dp[0][i-k]);
        }
        if (i>=l) {
            dp[0][i] = dp[0][i] || (!dp[1][i-l]);
            dp[1][i] = dp[1][i] || (!dp[0][i-l]);
        }
    }

    for (int cs=0; cs<m; cs++) {
        int n; cin >> n;
        cout << (dp[0][n]?"A":"B");
    }
    cout << endl;

    return 0;
}
