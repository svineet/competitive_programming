#include <iostream>
#include <algorithm>
using namespace std;

int dp[1010][1010][3];
int hcost[3] = {-3, 5, 20},
    acost[3] = {-2, 10, -5};

int solve(int h, int a, int state) {
    if (h<=0 || a<=0) {
        return 0;
    }

    if (dp[h][a][state]!=-1)
        return dp[h][a][state];

    for (int s=0; s<3; s++) {
        if (state == s)
            continue;

        if (h-hcost[s] <= 0 || a-acost[s] <= 0) {
            // Unfeasible to go that way.
            continue;
        }
        dp[h][a][state] = max(dp[h][a][state],
                              solve(h-hcost[s], a-acost[s], s));
    }
    dp[h][a][state]++; // We survived one chromosome here.
    return dp[h][a][state];
}

int main () {
    int t;
    cin >> t;
    for (int cs=0; cs<t; cs++) {
        int h, a;
        cin >> h >> a;
        for (int i=0; i<1010; i++) {
            for (int j=0; j<1010; j++) {
                int temp = ((i==0 || j==0)?0:-1);
                dp[i][j][0] = dp[i][j][1] = dp[i][j][2] = temp;
            }
        }
        cout << max(solve(h, a, 0),
                    max(solve(h, a, 1), solve(h, a, 2))) << endl;
    }

    return 0;
}
