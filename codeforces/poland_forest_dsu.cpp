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

void union_set(int x, int y) {
    int px = find_set(x),
        py = find_set(y);

    // Attach lighter tree to heavier one.
    if (rnk[px] > rnk[py]) {
        parent[py] = px;
    } else if (rnk[py] > rnk[px]) {
        parent[px] = py;
    } else {
        parent[px] = py;
        rnk[px]++;
    }
}

void create_set(int n) {
    for (int i=1; i<=n; i++) {
        parent[i] = i;
        rnk[i] = 0;
    }
}

int main() {
    int n; cin >> n;
    create_set(n);
    for (int i=1; i<=n; i++) {
        int p; cin >> p;
        union_set(i, p);
        // Now i and p are in the same connected
        // components.
    }

    set<int> comps;
    for (int i=1; i<=n; i++) {
        comps.insert(find_set(i));
    }
    cout << comps.size() << endl;

    return 0;
}
