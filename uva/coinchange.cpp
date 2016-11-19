#include <stdio.h>
#include <algorithm>
using namespace std;

int main() {
    int dp[8001] = {1, 1, 1, 1, 1};
    dp[0] = 1;
    for (int i=1; i<8001; i++) {
        dp[i] = dp[i-1];
    }
    for (int i=5; i<8001; i++) {
        dp[i] += dp[i-5];
    }
    for (int i=10; i<8001; i++) {
        dp[i] += dp[i-10];
    }
    for (int i=25; i<8001; i++) {
        dp[i] += dp[i-25];
    }
    for (int i=50; i<8001; i++) {
        dp[i] += dp[i-50];
    }

    while (true) {
        int inp;
        if (scanf("%d", &inp) == EOF) {
            break;
        }
        printf("%d\n", dp[inp]);
    }

    return 0;
}
