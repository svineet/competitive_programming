#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n, a, b, c;
    cin >> n >> a >> b >> c;
    int dp[n+1];
    dp[0] = 0;
    //cout << "0 ";
    for (int i=1; i<=n; i++) {
        dp[i] = -1;
        // -1 denotes cannot be formed
        if (i>=a) {
            if (dp[i-a]!=-1)
                dp[i] = max(dp[i], 1+dp[i-a]);
        }
        if (i>=b) {
            if (dp[i-b]!=-1)
                dp[i] = max(dp[i], 1+dp[i-b]);
        }
        if (i>=c) {
            if (dp[i-c]!=-1)
                dp[i] = max(dp[i], 1+dp[i-c]);
        }
        //cout << dp[i] << " ";
    }
    cout << dp[n] << endl;

    return 0;
}
