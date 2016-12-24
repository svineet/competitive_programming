#include <bits/stdc++.h>
using namespace std;

int stree[4*1000000];
int array[1000000], sortarray[1000000];

int sum_query(int node, int left, int right, int qleft, int qright) {
    if (right<qleft || left>qright)
        return 0;
    if (qleft<=left && right<=qright)
        return stree[node];

    int sm = 0;
    int mid = (left+right)/2;
    sm += sum_query(2*node+1, left, mid, qleft, qright);
    sm += sum_query(2*node+2, mid+1, right, qleft, qright);
    return sm;
}

void update_tree(int node, int left, int right, int updex) {
    if (left == right && updex == left) {
        stree[node] = 1;
        // Question specific detail.
        return;
    }

    if (updex < left || updex > right)
        return;

    int mid = (left+right)/2;
    update_tree(2*node+1, left, mid, updex);
    update_tree(2*node+2, mid+1, right, updex);
    stree[node] = stree[2*node+1] + stree[2*node+2];
}

int main() {
    int n; cin >> n;
    for (int i=0; i<n; i++) {
        cin >> array[i];
        sortarray[i] = array[i];
    }
    sort (sortarray, sortarray+n);

    for (int i=0; i<n; i++) {
        int sdex = lower_bound(sortarray, sortarray+n, array[i])-sortarray;
        int rank = sum_query(0, 0, n-1, sdex+1, n)+1;
        cout << rank << "\n";
        // Number of things more than this element
        // + 1
        update_tree(0, 0, n-1, sdex);
    }

    return 0;
}
