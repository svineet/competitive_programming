#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    for (int fucku=0; fucku<t; fucku++) {
        int n, sum=0;
        cin >> n;
        int array[n];
        for (int i=0; i<n; i++) {
            cin >> array[i];
            sum += array[i];
        }

        int dp[sum+1][n+1];
        // dp[i][j] represents if the integer 'i' can
        // be formed by using array[0..j-1]
        for (int i=1; i<=sum; i++) {
            dp[i][0] = 0; // Can't form any sum with 0 elements;
        }
        for (int j=0; j<=n; j++) {
            dp[0][j] = 1;
            // Empty set has sum 0 so it can always be formed
        }

        int result = 0;
        for (int i=1; i<=sum; i++) {
            for (int j=1; j<=n; j++) {
                dp[i][j] = 0;
                if (array[j-1]>i || array[j-1] == 0) {
                    dp[i][j] = dp[i][j-1];
                }
                else {
                    dp[i][j] = max(dp[i][j-1],
                                   dp[i-array[j-1]][j-1]);
                    // Try to include array[j-1] and see if that
                    // is better than just not using it.
                }
            }
            if (dp[i][n] == 1) result+=i;
        }
        /*for (int i=0; i<=sum; i++) {
            for (int j=0; j<=n; j++) {
                cout << dp[i][j] << " ";
            }
            cout << endl;
        }*/
        cout << result << endl;
    }

    return 0;
}
