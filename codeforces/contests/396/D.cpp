#include <bits/stdc++.h>
using namespace std;

void DFS(int node, vector<pair<int, int>> adj[],
         int cur_comp, pair<int, int> comp[],
         int parity) {
    comp[node] = {cur_comp, parity};
    for (pair<int, int> nx: adj[node]) {
        if (comp[nx.first] == make_pair(0, 0))
            DFS(nx.first, adj, cur_comp, comp,
                    (parity+nx.second)%2);
    }
}

int main() {
    int n, m, q;
    cin >> n >> m >> q;
    unordered_map<string, int> index;
    for (int i=0; i<n; i++) {
        string str; cin >> str;
        index[str] = i;
    }

    vector<pair<int, int>> adj[n];
    pair<int, int> comp[n];
    // Component number, parity.
    for (int i=0; i<n; i++) {
        comp[i] = {0, 0};
        int t;
        string a1, b1;
        cin >> t >> a1 >> b1;

        int a = index[a1],
            b = index[b1];
        if (t == 1) {
            adj[a].push_back({b, 0});
            adj[b].push_back({a, 0});
        } else if (t == 2) {
            adj[a].push_back({b, 1});
            adj[b].push_back({a, 1});
        }
    }

    int cur_comp = 1;
    for (int i=0; i<n; i++) {
        if (comp[i] == make_pair(0, 0)) {
            DFS(i, adj, cur_comp, comp, 0);
            cur_comp++;
        }
    }

    for (int i=0; i<q; i++) {
        string a, b;
        cin >> a >> b;
        pair<int, int> c1 = comp[index[a]],
                       c2 = comp[index[b]];
        if (c1.first == c2.first) {
            if (c1.second == c2.second)
                cout << 1 << "\n";
            else
                cout << 2 << "\n";
        } else {
            cout << 3 << "\n";
        }
    }

    return 0;
}
