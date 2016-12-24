#include <bits/stdc++.h>
using namespace std;

int main() {
    int dp[1011][1011];
    // dp[i][j] indicates
    // how many experiments are needed
    // if we have j eggs and i floors to
    // check
    for (int i=1; i<1001; i++) {
        dp[i][1] = i;
        // Linear search through
        // the floors.
        dp[1][i] = 1;
        // One floor only so...
        dp[0][i] = 0;
        // No trials no 0 floors
    }

    for (int i=2; i<=1000; i++) {
        for (int j=2; j<=1000; j++) {
            if (eggs>=ceil(log(floors))+1) {
                dp[i][j] = ceil(log(floors))+1;
                continue;
            }
            dp[i][j] = 1e9;
            for (int w=1; w<=floors; w++) {
                // Drop an egg from the w-th floor.
                dp[i][j] = min(dp[i][j],
                           1+max(dp[w-1][j-1], dp[i-w][j]));
            }
        }
    }

    int eggs, floors;
    scanf("%d%d", &eggs, &floors);
    while (eggs != 0) {
        cout << dp[floors][eggs] << endl;
        scanf("%d%d", &eggs, &floors);
    }

    return 0;
}
