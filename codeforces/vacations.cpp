#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    int array[n];
    for (int i=0; i<n; i++) {
        cin >> array[i];
    }

    int dp[n+1][3];
    // [0] = rest
    // [1] = gym
    // [2] = contest
    dp[0][0] = dp[0][1] = dp[0][2] = 0;
    for (int i=1; i<=n; i++) {
        dp[i][0] = 1+min({dp[i-1][0], dp[i-1][1],
                          dp[i-1][2]});

        if (array[i-1] == 2 || array[i-1] == 3) {
            dp[i][1] = 0;
        } else {
            dp[i][1] = 1;
        }
        dp[i][1] += min(dp[i-1][0], dp[i-1][2]);

        if (array[i-1] == 1 || array[i-1] == 3) {
            dp[i][2] = 0;
        } else {
            dp[i][2] = 1;
        }
        dp[i][2] += min(dp[i-1][0], dp[i-1][1]);
    }

    cout << min({dp[n][0], dp[n][1], dp[n][2]}) << endl;

    return 0;
}
