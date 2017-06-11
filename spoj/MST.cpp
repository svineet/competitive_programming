#include <bits/stdc++.h>
using namespace std;

int parent[400000];
int rnk[400000];

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
        return parent[node];
    }
}

void union_set(int x, int y) {
    int px = find_set(x),
        py = find_set(y);

    // Attach smaller subtree to
    // larger subtree.
    if (rnk[px] > rnk[py]) {
        parent[py] = px;
    } else if (rnk[py] > rnk[px]) {
        parent[px] = py;
    } else {
        parent[py] = px;
        rnk[px]++;
        // X tree got heavier.
    }
}

struct Edge {
    int a, b;
    int w;

    Edge() {
        a = b = w = 0;
    }

    Edge(int a_, int b_, int w_) {
        a = a_; b = b_;
        w = w_;
    }
};

bool comp(Edge a, Edge b) {
    return a.w < b.w;
}

int main() {
    int n, m; cin >> n >> m;
    vector<Edge> edgelist;
    edgelist.reserve(m);

    create_set(n);
    for (int i=0; i<m; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        edgelist.push_back({a, b, w});
        edgelist.push_back({b, a, w});
    }

    sort (edgelist.begin(), edgelist.end(), comp);
    long long mst = 0;
    for (auto e: edgelist) {
        Edge edge = e;
        // cout << e.w << endl;

        if (find_set(edge.a) == find_set(edge.b)) {
            continue;
        } else {
            // cout << "Taken edge: " << edge.a << " " << edge.b << endl;
            mst += edge.w;
            union_set(edge.a, edge.b);
        }
    }
    cout << mst << endl;

    return 0;
}
