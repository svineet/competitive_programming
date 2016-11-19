#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n, k, p;
    cin >> n >> k >> p;
    int array[n];
    int dp[n][n];
    // dp[i][j] tells us if i-th and j-th frogs are connected
    for (int i=0; i<n; i++) {
        cin >> array[i];
        dp[i][i] = 1; // Nodes are connected to themselves
    }


    return 0;
}
