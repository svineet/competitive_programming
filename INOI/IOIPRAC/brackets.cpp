#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n, k; cin >> n >> k;
    int values[n]; int brackets[n];
    for (int i=0; i<n; i++) {
        cin >> values[i];
    }
    for (int i=0; i<n; i++) {
        cin >> brackets[i];
    }

    int dp[n][n];
    for (int i=0; i<n; i++) {
        dp[i][i] = 0;
        // Maximum possible sum for one length subproblems
        // is zero because you cannot match one bracket.
    }

    for (int subsize=2; subsize<=n; subsize++) {
        for (int i=0; i<(n-subsize+1); i++) {
            int j = i+subsize-1;
            dp[i][j] = 0;
            if (brackets[i] == brackets[j]-k) {
                // They match up, take them.
                dp[i][j] = values[i]+values[j]+
                           (subsize==2?0:dp[i+1][j-1]);
                // at subproblem size 2, the indices don't
                // fit
            }
            dp[i][j] = max(dp[i][j],
                           max(dp[i+1][j], dp[i][j-1]));
            for (int z=i+1; z<j; z++) {
                dp[i][j] = max(dp[i][j],
                               dp[i][z]+dp[z+1][j]);
            }
        }
    }
    cout << dp[0][n-1] << endl;

    return 0;
}
