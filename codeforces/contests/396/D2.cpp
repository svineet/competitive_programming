#include <bits/stdc++.h>
using namespace std;

int rnk[20000];
int parent[20000];

int find_set(int node) {
    if (parent[node] == node) {
        return node;
    } else {
        parent[node] = find_set(parent[node]);
        return parent[node];
    }
}

bool union_set(int x, int y) {
    int px = find_set(x),
        py = find_set(y);

    if (rnk[px] > rnk[py]) {
        parent[py] = px;
        return true;
    } else if (rnk[py] > rnk[px]) {
        parent[px] = py;
        return false;
    } else {
        parent[px] = py;
        rnk[px]++;
        return false;
    }
    // returns if x was preferred daddy tree.
}

void create_set(int n) {
    for (int i=1; i<=n; i++) {
        parent[i] = i;
        rnk[i] = 0;
    }
}

int main() {
    int n, m, q;
    cin >> n >> m >> q;
    unordered_map<string, int> index;

    int meaning[n];
    for (int i=0; i<n; i++) {
        string str; cin >> str;
        index[str] = i;
        meaning[i] = 0;
    }

    create_set(n);
    for (int i=0; i<m; i++) {
        int t; string a1, b1;
        cin >> t >> a1 >> b1;
        int a = index[a1],
            b = index[b1];

        int kek = find_set(a),
            fef = find_set(b);
        // cout << kek << " " << fef << endl;
        // cout << meaning[a] << " " << meaning[b] << endl;
        if (t == 1) {
            if (kek == fef && meaning[kek] != meaning[fef]) {
                cout << "NO" << "\n";
            } else {
                if (union_set(a, b)) {
                    meaning[fef] = meaning[kek];
                } else {
                    meaning[kek] = meaning[fef];
                }
                cout << "YES" << "\n";
            }
        } else if (t == 2) {
            if (kek == fef && meaning[kek] == meaning[fef]) {
                cout << "NO" << "\n";
            } else {
                if (union_set(a, b)) {
                    meaning[fef] = 1-meaning[kek];
                } else {
                    meaning[kek] = 1-meaning[fef];
                }
                cout << "YES" << "\n";
            }
        }
    }

    for (int i=0; i<q; i++) {
        string a1, b1;
        cin >> a1 >> b1;

        int a = index[a1],
            b = index[b1];
        if (find_set(a) == find_set(b)) {
            if (meaning[find_set(a)] == meaning[find_set(b)])
                cout << 1 << "\n";
            else
                cout << 2 << "\n";
        } else {
            cout << 3 << "\n";
        }
    }

    return 0;
}
