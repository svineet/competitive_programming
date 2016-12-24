#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    int a[n];
    for (int i=0; i<n; i++) {
        cin >> a[i];
    }

    int dp[n+2];
    dp[0] = dp[1] = 0;
    for (int i=2; i<n+2; i++) {
        dp[i] = a[i-2] + max(dp[i-1], max(dp[i-2],dp[i-3]));
    }
    cout << max(dp[n+1], max(dp[n], dp[n-1])) << endl;

    return 0;
}
