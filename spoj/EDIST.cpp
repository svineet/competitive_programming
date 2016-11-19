#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main() {
    int t;
    cin >> t;
    for (int cs=0; cs<t; cs++) {
        int m, n;
        string a, b;
        cin >> a >> b;

        m = a.length(); n = b.length();
        int dp[m+1][n+1];
        for (int i=0; i<m+1; i++) {
            dp[i][0] = i;
        }
        for (int j=1; j<n+1; j++) {
            dp[0][j] = j;
        }

        for (int i=1; i<m+1; i++) {
            for (int j=1; j<n+1; j++) {
                dp[i][j] = min(
                        min(dp[i-1][j] + 1, dp[i][j-1] + 1),
                        ((a[i-1] == b[j-1])? 0:1) + dp[i-1][j-1]);
            }
        }

        /*for (int i=0; i<=m; i++) {
            for (int j=0; j<=n; j++) {
                cout << dp[i][j] << " ";
            }
            cout << endl;
        }*/

        cout << dp[m][n] << endl;
    }

    return 0;
}
