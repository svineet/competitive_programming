#include <bits/stdc++.h>
using namespace std;

int dp[1000][10000];
int digit[1000][10000];
// dp[i][j] indicates if 
// a sum of digits 'i' and
// a sum of digits squared
// of 'j' is achievable or not.
// If not, it is -1.
// If it is, it notes the number
// of digits in that number.

int main() {
    ios::sync_with_stdio(false);

    dp[0][0] = 0;
    // the number 0 satisfies dp[0][0]
    for (int i=0; i<901; i++) {
        for (int j=0; j<8101; j++) {
            if (i==0 && j==0) continue;
            dp[i][j] = -1;
            // Default is impossible.
            for (int d=1; d<=9; d++) {
                if (i-d>=0 && j-d*d>=0 && dp[i-d][j-d*d] != -1) {
                    if (dp[i-d][j-d*d]+1<dp[i][j] || dp[i][j] == -1) {
                        dp[i][j] = 1+dp[i-d][j-d*d];
                        digit[i][j] = d;
                    }
                }
            }
        }
    }

    int t; cin >> t;
    while (t--) {
        int s1, s2; cin >> s1 >> s2;
        if (s1 > 900 || s2 > 8100 || dp[s1][s2] == -1 || dp[s1][s2] > 100) {
            cout << "No solution" << endl;
        } else {
            while (!(s1 == 0 && s2 == 0)) {
                int d = digit[s1][s2];
                cout << d;
                s1 -= d; s2 -= d*d;
            }
            cout << endl;
        }
    }

    return 0;
}
