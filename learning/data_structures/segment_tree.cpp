#include <bits/stdc++.h>
using namespace std;

int make_tree(int* array, int* stree, int left, int right, int segindex) {
    if (left>right) return 0;
    if (left == right) {
        stree[segindex] = array[left];
        return array[left];
    }

    int mid = (left+right)/2;
    stree[segindex] = make_tree(array, stree, left, mid, 2*segindex+1);
    stree[segindex] += make_tree(array, stree, mid+1, right, 2*segindex+2);
    return stree[segindex];
}

int get_sum(int* stree, int qleft, int qright, int left, int right, int segindex) {
    if (qleft<=left && qright>=right) {
        // This particular segment is completely inside the
        // required segment. (eg: 0..2 is completely inside
        // 0..5. Avoid further recursion as we already know
        // the answer
        return stree[segindex];
    }

    if (qright<left || qleft>right) {
        // This segment is completely outside the required
        // segment. We stop here, returning a stub value.
        return 0;
    }

    // There is some overlap. Let's recurse and eliminate the
    // useless segments.
    int mid = (left+right)/2;
    stree[segindex] = get_sum(stree, qleft, qright, left, mid, 2*segindex+1)+
                      get_sum(stree, qleft, qright, mid+1, right, 2*segindex+2);
    return stree[segindex];
}

int main() {
    int n; cin >> n;
    int array[n]; int stree[n];
    for (int i=0; i<n; i++) {
        cin >> array[i];
    }

    make_tree(array, stree, 0, n-1, 0);
    int q; cin >> q;
    while (q--) {
        int l, r; cin >> l >> r;
        cout << get_sum(stree, l, r, 0, n-1, 0) << endl;
    }

    return 0;
}
