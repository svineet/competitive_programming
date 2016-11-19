#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    int matrix[n][n];
    bool safe[n][n];
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            cin >> matrix[i][j];
            safe[i][j] = false;
        }
    }
    for (int cs=0; cs<m; cs++) {
        int x, y, strength;
        cin >> x >> y >> strength;
        x--; y--;
        safe[x][y] = true;
        for (int i=x; i<=(x+strength); i++) {
            for (int j=y; j<=y+(x+strength-i); j++) {
                if (i>=0 && i<n && j>=0 && j<n) {
                    safe[i][j] = true;
                }
            }
            for (int j=y; j>=y-(x+strength-i); j--) {
                if (i>=0 && i<n && j>=0 && j<n) {
                    safe[i][j] = true;
                }
            }
        }
        for (int i=x; i>=(x-strength); i--) {
            int leftover = strength-(x-i);
            for (int j=y; j<=y+(leftover); j++) {
                if (i>=0 && i<n && j>=0 && j<n) {
                    safe[i][j] = true;
                }
            }
            for (int j=y; j>=y-(leftover); j--) {
                if (i>=0 && i<n && j>=0 && j<n) {
                    safe[i][j] = true;
                }
            }
        }
    }
    /*for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            cout << (safe[i][j]?1:0) << " ";
        }
        cout << endl;
    }*/
    int dp[n][n];
    int FUK = -13370000;
    dp[0][0] = (safe[0][0]?matrix[0][0]:FUK);
    for (int i=1; i<n; i++) {
        if (!safe[0][i] || dp[0][i-1] == FUK) {
            dp[0][i] = FUK;
        }
        else {
            dp[0][i] = dp[0][i-1] + matrix[0][i];
        }

        if (!safe[i][0] || dp[i-1][0] == FUK) {
            dp[i][0] = FUK;
        }
        else {
            dp[i][0] = dp[i-1][0] + matrix[i][0];
        }
    }

    for (int i=1; i<n; i++) {
        for (int j=1; j<n; j++) {
            if (!safe[i][j]) {
                dp[i][j] = FUK;
                continue;
            }
            if (dp[i-1][j] == FUK && dp[i][j-1] == FUK) {
                dp[i][j] = FUK;
                continue;
            }

            if (dp[i-1][j] == FUK) {
                dp[i][j] = matrix[i][j] + dp[i][j-1];
                continue;
            }
            if (dp[i][j-1] == FUK) {
                dp[i][j] = matrix[i][j] + dp[i-1][j];
                continue;
            }

            dp[i][j] = matrix[i][j]+max(dp[i-1][j],
                                        dp[i][j-1]);
        }
    }
    /*for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }*/
    if (dp[n-1][n-1] != FUK) {
        cout << "YES" << endl << dp[n-1][n-1] << endl;
    }
    else {
        cout << "NO" << endl;
    }

    return 0;
}
