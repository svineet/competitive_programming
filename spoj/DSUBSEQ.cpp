#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

const int MODDER = 1000000007;

int main() {
    ios_base::sync_with_stdio(false);
    int t; cin >> t;
    while (t--) {
        string str; cin >> str;
        int last[256] = {0};
        int n = str.length();
        long long dp[n+1];
        dp[0] = 1;
        for (int i=1; i<=n; i++) {
            dp[i] = 2*dp[i-1]%MODDER;
            if (last[(int)str[i-1]] != 0) {
                // We remove all subsequences that also ended with this character
                dp[i] = (dp[i]-dp[last[(int)str[i-1]]-1]+MODDER)%MODDER;
            }
            last[(int)str[i-1]] = i;
        }
        cout << dp[n] << endl;
    }

    return 0;
}
