#include <bits/stdc++.h>
using namespace std;

struct vertex {
    int best, best2;
};

int arr[100010];
vertex stree[400010];

vertex merge(vertex a, vertex b) {
    vertex result;
    int xd[4] = {a.best, a.best2, b.best, b.best2};
    sort (xd, xd+4);
    result.best = xd[3];
    result.best2 = xd[2];
    return result;
}

void build_tree(int node, int left, int right) {
    if (left == right) {
        stree[node].best = arr[left];
        stree[node].best2 = -1e9;
        return;
    }

    int mid = (left+right)/2;
    int ln = 2*node+1,
        rn = 2*node+2;
    build_tree(ln, left, mid);
    build_tree(rn, mid+1, right);
    stree[node] = merge(stree[ln], stree[rn]);
}

vertex query_tree(int node, int left, int right, int ql, int qr) {
    if (ql <= left && right <= qr) {
        return stree[node];
    }

    if (left > qr || ql > right) {
        vertex xd; xd.best = xd.best2 = -1e9;
        return xd;
    }

    int mid = (left+right)/2;
    int ln = 2*node+1,
        rn = 2*node+2;
    return (merge(query_tree(ln, left, mid, ql, qr),
                  query_tree(rn, mid+1, right, ql, qr)));
}

void update_tree(int node, int left, int right, int updex, int val) {
    if (left == updex && left == right) {
        stree[node].best = val;
        return;
    }

    if (left > updex || updex > right) {
        return;
    }

    int mid = (left+right)/2;
    int ln = 2*node+1,
        rn = 2*node+2;
    update_tree(ln, left, mid, updex, val);
    update_tree(rn, mid+1, right, updex, val);
    stree[node] = merge(stree[ln], stree[rn]);
}

int main() {
    int n; cin >> n;
    for (int i=0; i<n; i++) cin >> arr[i];
    build_tree(0, 0, n-1);

    int q; cin >> q;
    while (q--) {
        string t; cin >> t;
        int a, b; cin >> a >> b;
        if (t == "Q") {
            a--; b--;
            vertex gotem = query_tree(0, 0, n-1, a, b);
            cout << gotem.best + gotem.best2 << endl;
        } else {
            a--;
            update_tree(0, 0, n-1, a, b);
        }
    }

    return 0;
}
