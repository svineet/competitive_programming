#include <bits/stdc++.h>
using namespace std;

long long get_cost(int node, vector<int> adj[], int value[]) {
    int len = adj[node].size();
    long long cst = 0;
    for (int i=0; i<len; i++) {
        int nx = adj[node][i];
        cst += value[nx];
    }
    return cst;
}

int main() {
    int n; cin >> n;
    int m; cin >> m;

    int value[n+1];
    pair<int, int> nval[n];
    for (int i=1; i<=n; i++) {
        cin >> value[i];
        nval[i-1] = {value[i], i};
    }

    vector<int> adj[n+1];
    for (int i=0; i<m; i++) {
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    sort (nval, nval+n);
    reverse (nval, nval+n);

    long long cost = 0;
    for (int i=0; i<n; i++) {
        int index = nval[i].second;
        cost += get_cost(index, adj, value);
        value[index] = 0;
    }
    cout << cost << endl;

    return 0;
}
