#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    int A[n], B[n];
    for (int i=0; i<n; i++) cin >> A[i];
    for (int i=0; i<n; i++) cin >> B[i];

    int dp[n][n];
    pair<int, int> parent[n][n];
    // dp[i][j] is the largest
    // required subseq length
    // if considering A[0..i] and B[0..j]
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            dp[i][j] = 1;
            parent[i][j] = make_pair(-1, -1);
            for (int w=0; w<i; w++) {
                for (int k=0; k<j; k++) {
                    if (A[w]-B[k] == A[i]-B[j]) {
                        if (1+dp[w][k] > dp[i][j]) {
                            dp[i][j] = 1+dp[w][k];
                            parent[i][j] = make_pair(w, k);
                        }
                    }
                }
            }
        }
    }

    stack<int> astack, bstack;
    int bi = 0, bj = 0;
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            if (dp[i][j]>dp[bi][bj]) {
                bi = i; bj = j;
            }
        }
    }

    pair<int, int> cur(bi, bj);
    while (cur.first != -1) {
        astack.push(A[cur.first]);
        bstack.push(B[cur.second]);
        cur = parent[cur.first][cur.second];
    }

    cout << dp[bi][bj] << endl;
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
