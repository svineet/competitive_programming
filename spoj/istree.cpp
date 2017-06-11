#include <bits/stdc++.h>
using namespace std;

int n, m; 
int color[200000];
// 1 is processing
// 2 is processed
// 0 is unprocessed
vector<int> adjlist[200000];

bool DFS(int node, int parent) {
    color[node] = 1;
    // Mark as processing.
    for (auto nx: adjlist[node]) {
        // cout << nx << endl;
        if (color[nx] == 1 && nx != parent) {
            return false;
        } else if (nx != parent && color[nx] == 0) {
            DFS(nx, node);
        }
    }

    color[node] = 2;
    return true;
}

int main() {
    cin >> n >> m;
    bool tree = (n>0?n-1==m:m==0);
    for (int i=0; i<m; i++) {
        int a, b; cin >> a >> b;
        adjlist[a].push_back(b);
        adjlist[b].push_back(a);
    }

    tree = tree && DFS(1, -1);
    for (int i=1; i<=n; i++)
        tree = tree && color[i] == 2;

    if (tree)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;

    return 0;
}
