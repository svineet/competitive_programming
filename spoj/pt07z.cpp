#include <bits/stdc++.h>
using namespace std;

vector<int> adjlist[20000];
int best = 0;
int depth[20000];

void DFSPre(int node, int parent) {
    depth[node] = 0; // Assume leaf.
    int len = adjlist[node].size();
    for (int i=0; i<len; i++) {
        int nx = adjlist[node][i];
        if (nx != parent) {
            DFSPre(nx, node);
            depth[node] = max(depth[node],
                              1+depth[nx]);
        }
    }
}

void DFSPost(int node, int parent) {
    int len = adjlist[node].size();
    int max1, max2;
    max1 = max2 = -1;
    for (int i=0; i<len; i++) {
        int nx = adjlist[node][i];
        if (nx != parent) {
            if (depth[nx] > max1) {
                max2 = max1;
                max1 = depth[nx];
            } else if (depth[nx] > max2) {
                max2 = depth[nx];
            }
        }
    }

    // This also works for leaf nodes and
    // chain intermediate nodes because
    // maxes are -1 by default.
    // Leaf: -1 -1 +2 = 0;
    // Intermediate node in chain: D -1 + 2 = D+1;
    // General obviously works.
    best = max(best, max1+max2+2);
}

int main() {
    int n; cin >> n;
    for (int i=0; i<n; i++) {
        int a, b; cin >> a >> b;
        adjlist[a].push_back(b);
        adjlist[b].push_back(a);
    }
    
    DFSPre(1, -1);
    DFSPost(1, -1);
    cout << best << endl;

    return 0;
}
