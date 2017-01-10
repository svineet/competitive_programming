#include <bits/stdc++.h>
using namespace std;

int DFS(vector<int> adjlist[], int node, int parent) {
    int len = adjlist[node].size();
    int cur = 0;
    for (int i=0; i<len; i++) {
        int nx = adjlist[node][i];
        if (nx != parent) {
            cur = max(cur, 1+DFS(adjlist, nx, node));
        }
    }

    return cur;
}

int main() {
    int n; cin >> n;
    vector<int> adjlist[n+1];
    for (int i=2; i<=n; i++) {
        int parent; cin >> parent;
        adjlist[parent].push_back(i);
        adjlist[i].push_back(parent);
    }

    vector< pair<int, int> > depths;
    depths.reserve(n);
    // (Max depth of DFS, Node number)
    for (int i=1; i<=n; i++) {
        depths.push_back(make_pair(DFS(adjlist, i, -1), i));
    }

    sort (depths.begin(), depths.end());
    int mx = depths[0].first;
    int i = 0;
    while (depths[i].first == mx) {
        cout << depths[i].second << " ";
        i++;
    }
    cout << endl;

    return 0;
}
