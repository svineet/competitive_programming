#include <bits/stdc++.h>
using namespace std;

long long dp[(int)1e9];
int solve(long long num) {
    if (num==1) return 0;
    if (dp[num] != 0) return dp[num];
    dp[num] = 1+min(solve(num/2), solve(num-num/2));
    return dp[num];
}

int main() {
    long long n; cin >> n;
    cout << solve(n) << endl;

    return 0;
}
