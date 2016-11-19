#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    while (true) {
        string inp;
        cin >> inp;
        int n = inp.length();

        if (n==1 && inp[0]=='0')
            break;

        long long dp[n];
        dp[0] = 1;
        // dp[i] is the possible number of interpretations of
        // the sequence inp[0..i].
        for (int i=1; i<n; i++) {
            dp[i] = 0;
            int last_interpret = atoi(inp.substr(i-1, 2).c_str());
            int last_interpret2 = atoi(inp.substr(i, 1).c_str());
            if (last_interpret>=10 && last_interpret<=26) {
                dp[i] += (i!=1?dp[i-2]:1);
            }
            if (last_interpret2>=1 && last_interpret2<=26) {
                dp[i] += dp[i-1];
            }
        }
        cout << dp[n-1] << endl;
    }
    return 0;
}
