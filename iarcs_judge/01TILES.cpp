#include <iostream>
#include <algorithm>
using namespace std;

int MODDER = 15746;

int main() {
    int n;
    cin >> n;

    int dp[n+1];
    dp[0] = 0; dp[1] = 1; dp[2] = 2;
    // dp[i] indicates the sum of all possible combination
    // possible with i-1 elements
    // dp[0] is 0 since no combinations with 0 elements
    // dp[i] = '1' + dp[i-1] or '00' + dp[i-2]
    for (int i=3; i<=n; i++) {
        dp[i] = (dp[i-1]+dp[i-2])%MODDER;
        // dp[i]: either we take 00 and use i-2
        // or we take 1 and use i-1;
    }
    cout << dp[n] << endl;

    return 0;
}
