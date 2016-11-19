#include <stdio.h>
#include <algorithm>
#include <cstring>
using namespace std;

int char_cost(char a[], char b[], int i, int j) {
    int diff = (char)a[i]-(char)b[j];
    return ((diff>0)? diff: -diff);
}

int main() {
    char a[2001], b[2001];
    scanf("%s", &a[0]);
    scanf("%s", &b[0]);
    int blank_cost;
    scanf("%d", &blank_cost);

    int m, n;
    m = strlen(a);
    n = strlen(b);
    int dp[m+1][n+1];
    for (int i=0; i<m+1; i++) {
        dp[i][0] = i*blank_cost;
    }
    for (int j=1; j<n+1; j++) {
        dp[0][j] = j*blank_cost;
    }

    for (int i=1; i<m+1; i++) {
        for (int j=1; j<n+1; j++) {
            dp[i][j] = min(
                    min(dp[i-1][j], dp[i][j-1]) + blank_cost,
                    char_cost(a, b, i-1, j-1) + dp[i-1][j-1]);
        }
    }

    /*for (int i=0; i<=m; i++) {
        for (int j=0; j<=n; j++) {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }*/

    printf("%d\n", dp[m][n]);

    return 0;
}
