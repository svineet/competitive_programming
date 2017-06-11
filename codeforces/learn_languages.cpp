#include <bits/stdc++.h>
using namespace std;

int parent[1000];
int rnk[1000];

void create_set(int n) {
    for (int i=1; i<=n; i++) {
        parent[i] = i;
        rnk[i] = 0;
    }
}

int find_set(int node) {
    if (parent[node] == node) {
        return node;
    } else {
        parent[node] = find_set(parent[node]);
        // Path compression.
        return parent[node];
    }
}

void union_set(int x, int y) {
    int px = find_set(x),
        py = find_set(y);
    if (rnk[px] > rnk[py]) {
        parent[px] = py;
    } else if (rnk[px] < rnk[py]) {
        parent[py] = px;
    } else {
        parent[py] = px;
        rnk[px]++;
    }
}

int main() {
    ios::sync_with_stdio(false);
    int n, m; cin >> n >> m;

    create_set(n);
    vector<int> langs[n+1];
    bool allzero = true;
    for (int i=1; i<=n; i++) {
        int l; cin >> l;
        if (l == 0) continue;
        allzero = false;
        langs[i].reserve(l);
        while (l--) {
            int a; cin >> a;
            langs[i].push_back(a);
        }
        sort (langs[i].begin(), langs[i].end());
    }

    if (allzero) {
        cout << n << endl;
        return 0;
    }

    for (int i=1; i<=n; i++) {
        for (int j=i+1; j<=n; j++) {
            int lptr = 0,
                rptr = 0;
            int l1 = langs[i].size(),
                l2 = langs[j].size();
            bool done = false;
            while (lptr<l1 && rptr<l2) {
                if (langs[i][lptr] == langs[j][rptr]) {
                    done = true; break;
                } else if (langs[i][lptr] < langs[j][rptr]) {
                    lptr++;
                } else {
                    rptr++;
                }
            }

            if (done) {
                union_set(i, j);
            }
        }
    }

    set<int> comps;
    for (int i=1; i<=n; i++) {
        comps.insert(find_set(i));
    }
    cout << comps.size()-1 << endl;

    return 0;
}
