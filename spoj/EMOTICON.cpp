#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    string kek = "KEK";
    while (t--) {
        string str; cin >> str;
        int n = str.length();
        long long dp[n+1][4];
        for (int i=0; i<4; i++) {
            dp[0][i] = 0;
        }
        for (int i=0; i<=n; i++) {
            dp[i][0] = 1;
        }
        dp[0][0] = 1;
        // dp[i][j] is the number of ways
        // to obtain KEK[0..j] using only
        // str[0..i];
        for (int i=1; i<=n; i++) {
            for (int j=1; j<4; j++) {
                if (str[i-1] == kek[j-1]) {
                    dp[i][j] = dp[i-1][j-1];
                } else {
                    dp[i][j] = 0;
                }
                // If we can match a character
                // match it.
                dp[i][j] += dp[i-1][j];
                // Else we can also drop a character
                // from the string.
            }
        }
        cout << dp[n][3] << endl;
    }

    return 0;
}
