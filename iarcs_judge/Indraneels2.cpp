
#include <bits/stdc++.h>
using namespace std;

int dp[305][305];
pair<int, int> parent[305][305];
map<int, int> M;

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
    // from A[0..i] and B[0..j]
    for (int i=0; i<=n; i++) {
        dp[0][i] = dp[i][0] = 0;
        parent[0][i] = parent[i][0] = make_pair(-1, -1);
        // Empty subarrays cannot contribute
        // anything
    }

    // A takes the columns, B takes the rows
    map<int, int>::iterator iter;

    for (int i=1; i<=n; i++) {
        // Keep adding as we look
        // over B elements.
        for (int j=1; j<=n; j++) {
            dp[i][j] = 1;
            parent[i][j] = make_pair(-1, -1);
            int diff = A[j-1]-B[i-1];
            for (int k=j-2; k>=0; k--) {
                // Loop over A elements
                // looking for complements
                iter = M.find(A[k]-diff);
                if (iter != M.end()) {
                    // We found a complement
                    int guess = 1+dp[iter->second+1][k+1];
                    if (guess>dp[i][j]) {
                        dp[i][j] = guess;
                        parent[i][j] = make_pair(iter->second+1, k+1);
                    }
                }
            }
        }
        M[B[i-1]] = i-1;
    }

    int best = 0;
    pair<int, int> parentage;
    for (int i=0; i<=n; i++) {
        for (int j=0; j<=n; j++) {
            //cout << "(" << parent[i][j].first << ", " << parent[i][j].second << ") ";
            if (dp[i][j]>=best) {
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

