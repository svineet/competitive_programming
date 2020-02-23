#include <bits/stdc++.h>
using namespace std;

long long stree[800000] = {0}; // Filled with zeroes completely
long long lazy[800000];

long long arr[400000];
long long nums[400000];


// (x, y) are the indices to update
// (left, right) are internal indices of the segtree node we're at
void stree_paint(int node, int left, int right, int x, int y) {
    if (lazy[node]) {
        // There's some work left over, complete and propagate to daughter nodes

        stree[node] += (right-left+1)*lazy[node];
        if (left != right) {
            lazy[2*node+1] += lazy[node];
            lazy[2*node+2] += lazy[node]; // Value to add is propagated
        }
        lazy[node] = 0;
    }

    if (left == right) {
        // Update this node 1ue and go back up
        stree[node] += 1;
        lazy[node] = 0;
        return;
    }

    if (x <= left && right <= y) {
        stree[node] += (right-left+1)*1;
        if (left != right) {
            lazy[2*node+1] += 1;
            lazy[2*node+2] += 1;
        }

        return;
    }

    int mid = (left+right)/2;
    int ln = 2*node+1, rn = 2*node+2;

    if (y <= mid) {
        // Just update left node with shortened left and right
        stree_paint(2*node+1, left, mid, x, y);
    } else if (x > mid) {
        // Just update right now with shortened left and right
        stree_paint(2*node+2, mid+1, right, x, y);
    } else {
        stree_paint(2*node+1, left, mid, x, mid);
        stree_paint(2*node+2, mid+1, right, mid+1, y);
    }

    stree[node] = stree[ln]+stree[rn];
}


long long stree_query(int node, int left, int right, int x, int y) {
    if (lazy[node]) {
        // There's some work left over, complete and propagate to daughter nodes

        stree[node] += (right-left+1)*lazy[node];
        if (left != right) {
            lazy[2*node+1] += lazy[node];
            lazy[2*node+2] += lazy[node]; // Value to add is propagated
        }
        lazy[node] = 0;
    }

    if (x <= left && right <= y)
        return stree[node];

    if (left == right)
        return stree[node];

    int mid = (left+right)/2;
    if (y <= mid) {
        return stree_query(2*node+1, left, mid, x, y);
    } else if (x > mid) {
        return stree_query(2*node+2, mid+1, right, x, y);
    } else {
        return stree_query(2*node+1, left, mid, x, mid)+
               stree_query(2*node+2, mid+1, right, mid+1, y);
    }
}


int main(int argc, char **argv) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q; cin >> n >> q;
    for (int i=0; i<n; i++)
        cin >> arr[i];

    for (int i=0; i<q; i++) {
        int il, ir; cin >> il >> ir;

        stree_paint(0, 0, n-1, il-1, ir-1);
    }

    for (int i=0; i<n; i++)
        nums[i] = stree_query(0, 0, n-1, i, i);

    sort(nums, nums+n);
    sort(arr, arr+n);
    long long ans = 0;
    for (int i=0; i<n; i++)
        ans += nums[i]*arr[i];

    cout << ans << endl;

    return 0;
}

