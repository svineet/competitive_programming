#include <bits/stdc++.h>
using namespace std;

int n, k;
vector<int> adjlist[1005];
int dp[1005];

void DFS(int node, int parent, int steps) {
    dp[node] = steps%2==0?2:1;
    // Assume opponent wins
    // unless we can find an edge that
    // makes us win instead
    int len = adjlist[node].size();
    for (int i=0; i<len; i++) {
        int nx = adjlist[node][i];
        if (nx != parent) {
            DFS(nx, node, steps+1);
            if (steps%2==0 && dp[node] == 2 && dp[nx] == 1) {
                dp[node] = 1;
            } else if (steps%2==1 && dp[node] == 1 && dp[nx] == 2) {
                dp[node] = 2;
            }
        }
    }
}

int main() {
    cin >> n >> k;
    for (int i=0; i<n-1; i++) {
        int a, b; cin >> a >> b;
        adjlist[a].push_back(b);
        adjlist[b].push_back(a);
    }

    DFS(k, -1, 0);
    if (dp[k] == 1) {
        int best = 1e8;
        int len = adjlist[k].size();
        for (int i=0; i<len; i++) {
            if (dp[adjlist[k][i]] == 1) {
                best = min(best, adjlist[k][i]);
            }
        }
        cout << "First player wins flying to airport " << best << endl;
    } else {
        cout << "First player loses" << endl;
    }

    return 0;
}
