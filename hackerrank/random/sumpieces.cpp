#include <iostream>
#include <algorithm>
using namespace std;

long long get_sum(int j, int i, long long partials[]) {
    return partials[i]-(j==0?0:partials[j-1]);
}

int main() {
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    long long array[n];
    long long partials[n];
    for (int i=0; i<n; i++) {
        cin >> array[i];
        partials[i] = (i==0?0:partials[i-1]) + array[i];
    }

    long long dp[n];
    // dp[i] indicates the best answer to subproblem[0..i]
    // We basically snip off a certain suffix, calculate the cost for that
    // suffix and then add it to the dp[prefix]
    dp[0] = array[0]; // Just the cost of the first element
    for (int i=1; i<n; i++) {
        dp[i] = (i+1)*partials[i]; // Consider the whole subarray
        for (int j=0; j<i; j++) {
            dp[i] += dp[j] + (i-j)*(partials[i]-partials[j]);
        }
    }
    for (int i=0; i<n; i++)
        cout << dp[i] << " ";
    cout << endl;
    cout << dp[n-1] << endl;

    return 0;
}
