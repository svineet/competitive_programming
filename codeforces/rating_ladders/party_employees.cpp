#include <bits/stdc++.h>
using namespace std;

int DFS(int node, list<int> adj[]) {
    int mx = 0;
    for (int nx: adj[node]) {
        mx = max(1+DFS(nx, adj), mx);
    }

    return mx;
}

void ComponentMark(int node, list<int> adj[],
                   list<int> comps[], int cnum,
                   bool visited[]) {
    visited[node] = true;
    // cout << cnum << " " << node << endl;
    comps[cnum].push_back(node);
    for (int nx: adj[node]) {
        if (!visited[nx])
            ComponentMark(nx, adj, comps, cnum, visited);
    }
}

int main() {
    int n; scanf("%d", &n);

    list<int> adj[n+1];
    list<int> adjInDir[n+1];
    for (int i=1; i<=n; i++) {
        int p; scanf("%d", &p);
        if (p == -1) continue;

        adj[p].push_back(i);
        adjInDir[p].push_back(i);
        adjInDir[i].push_back(p);
    }

    bool visited[n+1];
    list<int> comps[n];
    memset(visited, false, sizeof visited);

    int cnum = 0;
    for (int i=1; i<=n; i++) {
        if (!visited[i]) {
            ComponentMark(i, adjInDir, comps, cnum, visited);
            cnum++;
        }
    }

    int totmx = -1e9;
    for (list<int> tree: comps) {
        if (tree.size() == 0) break;
        int cmin = -1e9;
        for (auto node: tree) {
            // printf("%d ", node);
            cmin = max(1+DFS(node, adj),
                       cmin);
        }
        // printf("\n");
        totmx = max(totmx, cmin);
    }

    printf("%d\n", totmx);

    return 0;
}
