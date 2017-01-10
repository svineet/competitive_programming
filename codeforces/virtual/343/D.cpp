#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    long long volumes[n];
    long long dp[n];
    for (int i=0; i<n; i++) {
        int r, h; cin >> r >> h;
        volumes[i] = r*r*h;
    }

    dp[0] = volumes[0];
    for (int i=1; i<n; i++) {
        dp[i] = volumes[i];
        // Find the cake with volume
        // less than volumes[i]
        // and largest value of dp[j]
    }

    return 0;
}
