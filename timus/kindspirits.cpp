#include <bits/stdc++.h>
using namespace std;

int best[300][300];
// Shortest path to level i
// and node number j

int main() {
    int n; cin >> n;
    best[0][1] = 0;

    int k; 
    for (int i=1; i<=n; i++) {
        string waste; if (i!=1) cin >> waste;
        cin >> k;
        for (int j=1; j<=k; j++) {
            // We are at best[i][j]
            best[i][j] = 1e9;
            while (true) {
                int prev; int weight;
                cin >> prev; if (prev == 0) break;
                cin >> weight;
                best[i][j] = min(best[i][j],
                                 best[i-1][prev]+weight);
            }
        }
    }

    int answer = 1e9;
    for (int i=1; i<=k; i++) {
        answer = min(answer, best[n][i]);
    }
    cout << answer << endl;

    return 0;
}
