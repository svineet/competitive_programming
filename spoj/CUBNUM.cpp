#include <bits/stdc++.h>
using namespace std;

int dp[100010];

int main() {
    int n;

    dp[0] = 0;
    dp[1] = 1;
    for (int i=2; i<=100010; i++) {
        int lim = ceil(cbrt(i));
        dp[i] = 1+dp[i-1];
        for (int j=1; j<=lim; j++) {
            if (j*j*j<=i) dp[i] = min(dp[i], 1+dp[i-j*j*j]);
        }
    }

    int cs = 1;
    while (scanf("%d", &n) != EOF) {
        printf("Case #%d: %d\n", cs++, dp[n]);
    }

    return 0;
}
