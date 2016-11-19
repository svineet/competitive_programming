#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int n, m; cin >> n >> m;
    vector< vector<int> > counties(m, vector<int>(0));
    for (int i=0; i<n; i++) {
        int temp; cin >> temp;
        counties[temp-1].push_back(i);
    }
    int dp[n][n];
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            if (i==j)
                dp[i][j] = 0;
            else
                dp[i][j] = 10*n;
        }
    }

    for (int i=0; i<n-1; i++) {
        int a, b; cin >> a >> b;
        a--; b--;
        dp[a][b] = 1;
        dp[b][a] = 1;
    }
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (dp[i][k] + dp[k][j] < dp[i][j])
                    dp[i][j] = dp[i][k] + dp[k][j];
            }
        }
    }
    /*for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }*/

    int q; cin >> q;
    for (int cs=0; cs<q; cs++) {
        int ca, cb; cin >> cb >> ca;
        ca--; cb--;
        int mindist = 10*n;
        for (int i=0; i<counties[ca].size(); i++) {
            int cityi = counties[ca][i];
            if (dp[cityi][cb]<mindist)
                mindist = dp[cityi][cb];
        }
        cout << mindist << endl;
    }

    return 0;
}
