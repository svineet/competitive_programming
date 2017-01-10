#include <bits/stdc++.h>
using namespace std;

int n; 
int array[100010];
int stree[400010];

void init_tree(int node, int left, int right) {
    if (left == right) {
        // Minimum in [i,i] is obviously
        // array[i]
        stree[node] = array[left];
        return;
    }

    int mid = (left+right)/2;
    init_tree(2*node + 1,
              left, mid);
    init_tree(2*node + 2,
              mid+1, right);
    stree[node] = min(stree[2*node + 1],
                      stree[2*node + 2]);
}

int query_tree(int node, int left, int right,
                         int i, int j) {
    if (i<=left && right<=j) {
        return stree[node];
    } else if (left>j || right<i) {
        return 1e9;
    }

    int mid = (left+right)/2;
    int best = min(query_tree(2*node + 1, left, mid, i, j),
                   query_tree(2*node + 2, mid+1, right, i, j));
    return best;
}

int main() {
    cin >> n;
    for (int i=0; i<n; i++) cin >> array[i];
    init_tree(0, 0, n-1);
    // Root is node 0
    // Root covers interval 0 to n-1

    int q; cin >> q;
    while (q--) {
        int i, j; cin >> i >> j;
        cout << query_tree(0, 0, n-1, i, j) << endl; 
    }

    return 0;
}
