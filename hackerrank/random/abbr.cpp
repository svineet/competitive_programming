#include <iostream>
#include <algorithm>
#include <string>
#include <ctype.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    int q;
    cin >> q;
    for (int cs=0; cs<q; cs++) {
        string a, b;
        cin >> a >> b;

        int alen = a.length(),
            blen = b.length();
        int dp[blen+1][alen+1];
        dp[0][0] = 1; // Empty string to empty string doable.
        for (int i=1; i<blen+1; i++) {
            dp[i][0] = 0;
            // Cannot convert empty string into unempty string
        }
        for (int i=1; i<alen+1; i++) {
            dp[0][i] = islower(a[i-1]) && dp[0][i-1];
        }

        for (int i=1; i<blen+1; i++) {
            for (int j=1; j<alen+1; j++) {
                dp[i][j] = (dp[i][j-1] && islower(a[j-1]));
                // Delete a character from a if it is lowercase
                dp[i][j] = dp[i][j] ||
                           (toupper(a[j-1]) == b[i-1] && dp[i-1][j-1]);
            }
        }
        cout << (dp[blen][alen]?"YES":"NO") << endl;
    }


    return 0;
}
