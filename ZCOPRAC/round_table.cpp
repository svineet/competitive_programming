#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n; cin >> n;
    int array[n];
    for (int i=0; i<n; i++) {
        cin >> array[i];
    }

    if (n==1) {
        cout << 0 << endl;
        // No pairs, so...
        return 0;
    }

    long long firstgets, lastgets;
    int dp[n][2];
    // We either take a[i] or not. [2] for that.
    dp[0][0] = array[0];
    dp[0][1] = array[0];
    // Take array[0] for first run
    for (int i=1; i<n; i++) {
        dp[i][0] = dp[i-1][1]; // Had to take the last one
        dp[i][1] = array[i] + min(dp[i-1][0],
                                  dp[i-1][1]);
    }
    firstgets = dp[n-1][0];
    // First gets, and the last guy does not get dessert

    dp[0][0] = 0;
    dp[0][1] = array[0];
    // Not necessarily take first guy
    for (int i=1; i<n; i++) {
        dp[i][0] = dp[i-1][1]; // Had to take the last one
        dp[i][1] = array[i] + min(dp[i-1][0],
                                  dp[i-1][1]);
    }
    lastgets = dp[n-1][1];
    // Take the last guy forcefully.

    cout << min(lastgets, firstgets) << endl;
    return 0;
}
