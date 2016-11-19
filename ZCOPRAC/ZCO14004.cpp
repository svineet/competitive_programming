#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    long long array[n];
    for (int i=0; i<n; i++) {
        cin >> array[i];
    }
    long long dp[n];
    // dp[i] is the best profit we get
    // if we choose to play i-th match
    dp[0] = array[0];
    for (int i=1; i<n; i++) {
        dp[i] = max(array[i]+array[i-1]+(i-3>=0?dp[i-3]:0),
                max(array[i]+(i-2>=0?dp[i-2]:0),
                    dp[i-1]));
    }
    cout << *max_element(dp, dp+n) << endl;

    return 0;
}
