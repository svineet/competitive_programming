#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m; cin >> n >> m;
    string choices[n];
    for (int i=0; i<n; i++) {
        cin >> choices[i];
    }
    int cost[n][3];
    // 0: Cost to get it to a character
    // 1: Cost to get it to a number
    // 2: Cost to get it to '&', '*', '#'
    for (int i=0; i<n; i++) {
        cost[i][0] = cost[i][1] = cost[i][2] = 1e9;
        // Infinity;
        for (int j=0; j<m; j++) {
            if ('a' <= choices[i][j] && choices[i][j] <= 'z') {
                cost[i][0] = min(cost[i][0],
                                 min(m-j, j));
            } else if ('0' <= choices[i][j] && choices[i][j] <= '9') {
                cost[i][1] = min(cost[i][1],
                                 min(m-j, j));
            } else {
                cost[i][2] = min(cost[i][2],
                                 min(m-j, j));
            }
        }
        // cout << cost[i][0] << " " << cost[i][1] << " " << cost[i][2];
        // cout << endl;
    }

    int dp[n][8];
    // dp[i][j]:
    // j is a bitmask. It states how many
    // of the requirements have been fulfilled.

    fill (dp[0], dp[0]+8, 1e9);
    // Infinity == impossible.
    for (int i=0; i<3; i++) {
        // i-th bit is lit.
        dp[0][1<<i] = cost[0][i];
    }

    for (int i=1; i<n; i++) {
        fill (dp[i], dp[i]+8, 1e9);
        for (int j=0; j<3; j++) {
            // Use this element to light the
            // j-th bit.
            for (int k=0; k<8; k++) {
                // Previous bit pattern.
                dp[i][k|(1<<j)] = min(cost[i][j]+dp[i-1][k],
                                      dp[i][k|(1<<j)]);
            }
        }
    }

    cout << dp[n-1][7] << endl;
    // Mask is 111.

    return 0;
}
