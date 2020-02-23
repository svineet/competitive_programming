#include <bits/stdc++.h>
using namespace std;

long long stree[400000] = {0}; // Filled with zeroes completely
long long lazy[400000];

long long arr[400000];
long long nums[400000];

int stree_combine(int a, int b) {
    // Simple addition
    return a+b;
}

void stree_paint(int node, int left, int right, int x, int y, int val) {
    if (left == right) {
        // Update this node value and go back up
        stree[node] += val;
        return;
    }

    int mid = (left+right)/2;
    int ln = 2*node+1, rn = 2*node+2;

    if (y <= mid) {
        // Just update left node with shortened left and right
        stree_paint(2*node+1, left, mid, x, y, val);
    } else if (x > mid) {
        // Just update right now with shortened left and right
        stree_paint(2*node+2, mid+1, right, x, y, val);
    } else {
        stree_paint(2*node+1, left, mid, x, mid, val);
        stree_paint(2*node+2, mid+1, right, mid+1, y, val);
    }

    stree[node] = stree[ln]+stree[rn];
}

long long stree_query(int node, int left, int right, int x, int y) {
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

    long long diff[n+2] = {0};
    for (int i=0; i<q; i++) {
        int il, ir; cin >> il >> ir;

        il--; ir--;
        diff[il] += 1;
        diff[ir+1] -= 1;
    }

    nums[0] = diff[0];
    for (int i=1; i<n; i++)
        nums[i] = nums[i-1]+diff[i];

    sort(nums, nums+n);
    sort(arr, arr+n);
    long long ans = 0;
    for (int i=0; i<n; i++)
        ans += nums[i]*arr[i];

    cout << ans << endl;

    return 0;
}

