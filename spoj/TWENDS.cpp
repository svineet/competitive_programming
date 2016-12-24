#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int m=1;
    while (true) {
        int n; cin >> n;
        if (n==0) break;

        int array[n];
        for (int i=0; i<n; i++) {
            cin >> array[i];
        }
        int dp[n][n];
        // dp[i][j] is the best difference dp-greedy
        // that can be achieved using array[i..j]
        // sub problem sizes are an indicator of who is
        // playing right now. Since n is even,
        // and dp boi plays first, then greedy,
        // dp boi always ends up with an even subproblem size
        // while greedy always ends up with an odd subproblem
        // size
        for (int i=0; i<n; i++) {
            dp[i][i] = -array[i];
            // subproblem size is one. GreedyBoi plays
            // meaning he picks the last one.
        }

        for (int subsize=2; subsize<=n; subsize++) {
            for (int i=0; i<=(n-subsize); i++) {
                int j = i+subsize-1;
                if (subsize%2==0) {
                    // We're DPBoi xD rekt
                    dp[i][j] =  max(array[i]+dp[i+1][j],
                                    array[j]+dp[i][j-1]);
                }
                else {
                    // We're GreedyBoi :(
                    if (array[i]>=array[j]) {
                        dp[i][j] = dp[i+1][j]-array[i];
                    }
                    else {
                        dp[i][j] = dp[i][j-1]-array[j];
                    }
                }
            }
        }

        cout << "In game " << m << ", the greedy strategy might lose by as many as " << dp[0][n-1] << " points." << endl;
        m++;
    }

    return 0;
}
