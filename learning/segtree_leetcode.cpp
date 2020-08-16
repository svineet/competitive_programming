
// Problem link: https://leetcode.com/problems/range-sum-query-mutable/
class NumArray {
public:
    // Segment tree where each node is an integer, sum
    //   of the child nodes.
    vector<int> segtree;
    int n;
    vector<int> arr;

    void build_segtree(int node, int left, int right) {
        if (left == right) {
            segtree[node] = arr[left];
            return;
        }

        int mid = (left+right)/2;
        int lnode = 2*node;
        int rnode = 2*node+1;
        build_segtree(lnode, left, mid);
        build_segtree(rnode, mid+1, right);

        segtree[node] = segtree[lnode] + segtree[rnode];
    }

    void update_segtree(int node, int left, int right,
                        int target, int target_index) {
        if (left == right) {
            segtree[node] = target;
            return;
        }

        int mid = (left+right)/2;
        int lnode = 2*node;
        int rnode = 2*node+1;

        if (target_index <= mid) {
            update_segtree(lnode, left, mid, target, target_index);
        } else {
            update_segtree(rnode, mid+1, right, target, target_index);
        }

        segtree[node] = segtree[lnode] + segtree[rnode];
    }

    int segtree_sum(int node, int left, int right,
                              int i, int j) {
        if (left >= i && right <= j)
            return segtree[node];
        if (left == right)
            return segtree[node];

        int mid = (left+right)/2;
        int lnode = 2*node;
        int rnode = 2*node+1;

        if (i > mid) {
            // Go total right
            return segtree_sum(rnode, mid+1, right, i, j);
        } else if (j <= mid) {
            // Go total left
            return segtree_sum(lnode, left, mid, i, j);
        } else {
            // Split down middle
            
            return segtree_sum(lnode, left, mid, i, mid)+
                   segtree_sum(rnode, mid+1, right, mid+1, j);
        }
    }

    NumArray(vector<int>& nums) {
        n = nums.size();
        segtree.resize(4*n+1);
        arr = nums;
        
        if (n == 0) return;

        build_segtree(1, 0, n-1);
    }

    void update(int i, int val) {
        update_segtree(1, 0, n-1, val, i);
    }

    int sumRange(int i, int j) {
        return segtree_sum(1, 0, n-1, i, j);
    }
};
