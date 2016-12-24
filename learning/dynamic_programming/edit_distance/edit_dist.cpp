#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    string A, B;
    cin >> A >> B;

    int m = A.length(),
        n = B.length();
    int dp[m+1][n+1];
    for (int i=0; i<n+1; i++) {
        dp[i][0] = i;
    }
    for (int j=0; j<m+1; j++) {
        dp[0][j] = j;
    }

    for (int i=1; i<(m+1); i++) {
        for (int j=1; j<(n+1); j++) {
            dp[i][j] = min({
                            1+dp[i-1][j], // We insert a character into B
                            1+dp[i][j-1], // We insert a character into A
                            ((A[i] == B[j])?0:1)+dp[i-1][j-1]
                            // We take both characters and if they
                            // are equal we give 0 cost to the edge
                            // else we cost 1 for substitution
                          });
        }
    }

    for (int i=0; i<m+1; i++) {
        for (int j=0; j<n+1; j++) {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    cout << dp[m][n] << endl;

    return 0;
}
