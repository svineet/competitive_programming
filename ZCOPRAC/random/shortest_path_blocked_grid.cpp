#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n, blocks; cin >> n >> blocks;

    int dp[n][n];
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            dp[i][j] = 0;
        }
    }

    for (int i=0; i<blocks; i++) {
        int x, y;
        cin >> x >> y;
        dp[x][y] = -1; // -1 is not accessible
    }

    dp[0][0] = 0; // 0 steps to reach 0, 0
    for (int i=1; i<n; i++) {
        if (dp[0][i-1]==-1) {
            dp[0][i] = -1;
        }
        if (dp[i-1][0]==-1) {
            dp[i][0] = -1;
        }

        if (dp[0][i]!=-1 && dp[0][i-1]!=-1) {
            dp[0][i] = 1 + dp[0][i-1];
        }

        if (dp[i][0]!=-1 && dp[i-1][0]!=-1) {
            dp[i][0] = 1 + dp[i-1][0];
        }
    }
    for (int i=1; i<n; i++) {
        for (int j=1; j<n; j++) {
            if (dp[i][j]==-1) {
                continue;
            }

            dp[i][j] = -1; // Assume it is unreachable
            // if any of the following execute it will be
            // reachable
            if (dp[i-1][j]!=-1) {
                // if left is not inaccessible
                // and is within bounds
                dp[i][j] = 1+dp[i-1][j];
            }
            if (dp[i][j-1]!=-1) {
                // if up is accessible
                // and within bounds
                dp[i][j] = min((dp[i][j]==-1?100000000:dp[i][j]),
                               1+dp[i][j-1]);
            }
        }
    }
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    cout << dp[n-1][n-1] << endl;

    return 0;
}
