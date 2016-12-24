#include <stdio.h>
#include <algorithm>
using namespace std;

int main() {
    int capacity, n;
    scanf("%d", &capacity);
    scanf("%d", &n);
    int value[n], size[n];
    for (int i=0; i<n; i++) {
        scanf("%d", &value[i]);
        scanf("%d", &size[i]);
    }

    int dp[capacity][2];
    // dp[i][j] indicates the most value you can get
    // out of using 0..j-1 items with a bag of capacity
    // i. Our goal is to get dp[capacity][n].
    // dp[0][j] is 0 since no value can be taken with
    // 0 capacity
    // dp[i][0] is also 0 since no matter how big
    // your bag gets you can't get value out of no
    // items at all.
    // dp[i][j]: you can either take (j-1)-th item or not.
    // Choose whichever is better, i.e:
    // dp[i][j] = max(dp[i-size[j-1]][j-1]+value[j-1],
    //                dp[i][j-1]);
    // Make sure to check if size[j-1] is less than
    // i or not, to avoid invalid array index.
    for (int j=0; j<=capacity; j++) {
        dp[j][0] = 0;
    }
    dp[0][1] = 0;

    int source=0, dest=1;
    for (int j=1; j<=n; j++) {
        for (int i=1; i<=capacity; i++) {
            if (size[j-1]<=i) {
                dp[i][dest] = max(dp[i-size[j-1]][source]+value[j-1],
                                  dp[i][source]);
            }
            else {
                dp[i][dest] = dp[i][source];
            }
        }
        swap(source, dest);
    }
    printf ("%d\n", dp[capacity][source]);

    return 0;
}
