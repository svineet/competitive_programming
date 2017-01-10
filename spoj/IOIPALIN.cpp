#include <bits/stdc++.h>
using namespace std;

int dp[2][5005+1];
int n; char str[5005];

int main() {
    scanf("%d", &n);
    scanf("%s", &str[0]);

    int source = 0,
        dest = 1;
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            dp[dest][j] = max((str[i-1] == str[n-j]?1:0)+dp[source][j-1],
                          max(dp[dest][j-1], dp[source][j]));
        }
        swap (source, dest);
    }
    printf("%d\n", n-dp[source][n]);

    return 0;
}
