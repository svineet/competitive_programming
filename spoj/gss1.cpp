#include <bits/stdc++.h>
using namespace std;

struct vertex {
    int ans, sum;
    // Best segment, sum of all elems
    int pref, suff;
    // Best prefix,
    // best suffix.
};

vertex stree[400000];
int arr[400000];

vertex combine(vertex ln, vertex rn) {
    vertex result;
    result.sum = ln.sum+rn.sum;
    result.pref = max(ln.pref,
                      ln.sum+rn.pref);
    result.suff = max(ln.suff+rn.sum,
                      rn.suff);
    result.ans = max({ln.suff+rn.pref,
                      ln.ans, rn.ans, result.pref, result.suff});
    return result;
}

void build_tree(int node, int left, int right) {
    if (left == right) {
        stree[node].sum = arr[left];
        stree[node].ans = stree[node].pref = stree[node].suff = arr[left];
        // We might not want to take this element if it is
        // negative.
        return;
    }

    int mid = (left+right)/2;
    int ln = 2*node+1, rn = 2*node+2;
    build_tree(ln, left, mid);
    build_tree(rn, mid+1, right);

    stree[node] = combine(stree[ln], stree[rn]);
}

vertex query_tree(int node, int left, int right, int x, int y) {
    if (left == x && right == y)
        return stree[node];

    int mid = (left+right)/2;
    if (y <= mid) {
        // Go left and avoid empty
        // right vertex problems.
        return query_tree(2*node+1, left, mid, x, y);
    } else if (x > mid) {
        // Go right and do similar.
        return query_tree(2*node+2, mid+1, right, x, y);
    } else {
        return combine(query_tree(2*node+1, left, mid, x, mid),
                       query_tree(2*node+2, mid+1, right, mid+1, y));
    }
}

int main() {
    int n; scanf("%d", &n);
    for (int i=0; i<n; i++) scanf("%d", &arr[i]);

    build_tree(0, 0, n-1);

    int m; scanf("%d", &m);
    while (m--) {
        int x, y; scanf("%d%d", &x, &y);
        printf("%d\n", query_tree(0, 0, n-1, x-1, y-1).ans);
    }

    return 0;
}
