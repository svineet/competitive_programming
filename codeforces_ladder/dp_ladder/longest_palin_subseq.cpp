#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main() {
    int t; cin >> t;
    for (int cs=0; cs<t; cs++) {
        string str;
        cin >> str;
        int n = str.length();
        if (n==0) continue;
        int dp[n][n];
        // We need dp[0][n-1];
        // dp[i][j] indicates the largest palindromic
        // subsequence possible in str[i..j]
        for (int i=0; i<n; i++) {
            dp[i][i] = 1;
            // 1 size substrings are already palindromic
            // Here subprob_size was 1;
        }

        for (int subprob_size=2; subprob_size<=n; subprob_size++) {
            for (int i=0; i<=(n-subprob_size); i++) {
                int j = i+subprob_size-1;
                if (str[i] == str[j]) {
                    dp[i][j] = 2+(subprob_size>2?dp[i+1][j-1]:0);
                }
                else {
                    dp[i][j] = max(dp[i+1][j],
                                   dp[i][j-1]);
                }
            }
        }

        /*for(int i=0; i<n; i++) {
            if (i==0) {
                for (int j=0; j<n; j++) {
                    cout << str[j] << " ";
                }
                cout << endl;
            }
            for (int j=0; j<n; j++) {
                if (j>=i) cout << dp[i][j] << " ";
                else      cout << "  ";
            }
            cout << endl;
        }*/

        cout << dp[0][n-1] << endl;
    }

    return 0;
}
