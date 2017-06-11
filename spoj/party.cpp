#include <bits/stdc++.h>
using namespace std;

int dp[200][600];

int main() {
    int budget, n;
    cin >> budget >> n;
    while (!(budget == 0 && n == 0)) {
        int values[n], cost[n];
        memset (dp, 0, sizeof dp);
        memset (values, 0, sizeof values);
        memset (cost, 0, sizeof cost);

        for (int i=0; i<n; i++) {
            cin >> cost[i] >> values[i];
        }

        // dp[i][j] is the best fun
        // you can get out of 0..i parties
        // with j amount of money.
        for (int i=0; i<=budget; i++) {
            dp[0][i] = 0;
            if (i >= cost[0])
                dp[0][i] = values[0];
        }

        for (int i=1; i<n; i++) {
            for (int j=0; j<=budget; j++) {
                dp[i][j] = dp[i-1][j];
                // Not taking this element.
                if (j >= cost[i])
                    dp[i][j] = max(dp[i][j],
                                   dp[i-1][j-cost[i]]+values[i]);
            }
        }

        int mx = -1e9;
        int key = -1;
        for (int i=0; i<=budget; i++) {
            if (dp[n-1][i] > mx) {
                mx = dp[n-1][i];
                key = i;
            }
        }

        cout << key << " " << mx << "\n";
        cin >> budget >> n;
    }

    return 0;
}
