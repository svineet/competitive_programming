#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int main() {
    int m, s; cin >> m >> s;
    int dp[m+1][s+1];
    // dp[i][j] gives the highest/lowest number possible that
    // can be formed using m digits and with sum s
    // -1 if cannot be done
    for (int i=0; i<=m; i++) {
        dp[i][0] = 0;
        if (i==m) dp[i][0] = -1;
        // We disallow leading zeroes in m-th digit
    }
    for (int j=1; j<=s; j++) {
        dp[0][j] = -1;
        // Cannot form any sum using no digits at all
    }

    for (int d=1; d<=m; d++) {
        for (int sum=1; sum<=s; sum++) {
            dp[d][sum] = -1;
            // Assume it cannot be formed.
            for (int i=0; i<=9; i++) {
                // Cannot use 0 for the m-th digit!
                if (d == m && i == 0) continue;

                if (sum-i>=0 && dp[d-1][sum-i] != -1) {
                    // can deduct i from sum and it is possible to form
                    // a number with d-1 digits and sum as sum-i
                    // then try fitting i and the first digit of new number
                    dp[d][sum] = max(dp[d][sum],
                                     int(pow(10, d-1))*i+dp[d-1][sum-i]);
                }
            }
        }
    }
    int higher = dp[m][s];

    for (int d=1; d<=m; d++) {
        for (int sum=1; sum<=s; sum++) {
            dp[d][sum] = -1;
            // Assume it cannot be formed.
            for (int i=0; i<=9; i++) {
                // Cannot use 0 for the m-th digit!
                if (d == m && i == 0) continue;

                if (sum-i>=0 && dp[d-1][sum-i] != -1) {
                    // can deduct i from sum and it is possible to form
                    // a number with d-1 digits and sum as sum-i
                    // then try fitting i and the first digit of new number
                    if (dp[d][sum] == -1)
                        dp[d][sum] = int(pow(10, d-1))*i+dp[d-1][sum-i];
                    else
                        dp[d][sum] = min(dp[d][sum],
                                         int(pow(10, d-1))*i+dp[d-1][sum-i]);
                }
            }
        }
    }
    int lower = dp[m][s];

    cout << lower << " " << higher << endl;

    return 0;
}
