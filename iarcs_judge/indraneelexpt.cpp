#include <bits/stdc++.h>
using namespace std;

int dp[305][305];
pair<int, int> parent[305][305];

int main() {
    int n; cin >> n;
    int A[n], B[n];
    // M maps number to its
    // index in B.
    for (int i=0; i<n; i++) {
        cin >> A[i];
    }
    for (int i=0; i<n; i++) {
        cin >> B[i];
    }

    // dp[i][j] is the max
    // subsequence length obtainable
    // from A[0..j] and B[0..i]
    for (int i=0; i<=n; i++) {
        dp[0][i] = dp[i][0] = 0;
        parent[0][i] = parent[i][0] = make_pair(-1, -1);
        // Empty subarrays cannot contribute
        // anything
    }

    // A takes the columns, B takes the rows
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            dp[i][j] = 1;
            parent[i][j] = make_pair(-1, -1);

            for (int k=0; k<i-1; k++) {
                for (int w=0; w<j-1; w++) {
                    if (A[w]-B[k] == A[j-1]-B[i-1]) {
                        /*cout << A[j-1] << " " << B[i-1];
                        cout << " matches ";
                        cout << A[w] << " " << B[k] << endl;*/
                        if (dp[i][j] < 1+dp[k+1][w+1]) {
                            dp[i][j] = 1+dp[k+1][w+1];
                            parent[i][j] = make_pair(k+1, w+1);
                        }
                    }
                }
            }
        }
    }

    int best = 0;
    pair<int, int> parentage;
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            //cout << "(" << parent[i][j].first << ", " << parent[i][j].second << ") ";
            if (dp[i][j]>best) {
                best = dp[i][j];
                parentage = make_pair(i, j);
            }
        }
        //cout << endl;
    }

    cout << best << endl;
    stack<int> astack, bstack;
    while (parentage.first != -1) {
        bstack.push(B[parentage.first-1]);
        astack.push(A[parentage.second-1]);
        parentage = parent[parentage.first][parentage.second];
    }

    while (!astack.empty()) {
        cout << astack.top() << " ";
        astack.pop();
    }
    cout << endl;

    while (!bstack.empty()) {
        cout << bstack.top() << " ";
        bstack.pop();
    }
    cout << endl;

    return 0;
}
