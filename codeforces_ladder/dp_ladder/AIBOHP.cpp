#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main() {
    int t; cin >> t;
    for (int cs=0; cs<t; cs++) {
        string str; cin >> str;
        int n = str.length();
        int dp[n][n];
        for (int i=0; i<n; i++) {
            dp[i][i] = 0;
            // str[i..i] is already palindromic
            // so 0 operation needed to make it palindromic
            // This corresponds to subproblem size = 1
        }

        for (int subsize=2; subsize<=n; subsize++) {
            for (int i=0; i<=(n-subsize); i++) {
                int j = i+subsize-1;
                if (str[i] == str[j]) {
                    // No changes to these two required
                    // Add operations needed for the inner one
                    dp[i][j] = (subsize>2?dp[i+1][j-1]:0);
                }
                else {
                    dp[i][j] = 1+min(dp[i+1][j],
                                     dp[i][j-1]);
                }
            }
        }
        cout << dp[0][n-1] << endl;
    }
    return 0;
}
