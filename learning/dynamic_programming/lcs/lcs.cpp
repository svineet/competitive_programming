#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    string a, b;
    cin >> a >> b;
    int m = a.length(),
        n = b.length();
    int dp[m+1][n+1];

    for (int i=0; i<=m; i++)
        dp[i][0] = 0;
    for (int j=0; j<=n; j++)
        dp[0][j] = 0;

    for (int i=1; i<=m; i++) {
        for (int j=1; j<=n; j++) {
            dp[i][j] = max(max(dp[i-1][j], dp[i][j-1]),
                           (a[i-1] == b[j-1]? 1:0) + dp[i-1][j-1]);
        }
    }
    cout << dp[m][n] << endl;

    return 0;
}
