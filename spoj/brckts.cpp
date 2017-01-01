#include <bits/stdc++.h>
using namespace std;

struct vertex {
    int unleft, unright;
};

vertex merge(vertex a, vertex b) {
    int matched = min(a.unleft, b.unright);
    // These brackets neutralize each
    // other.
    vertex result;
    result.unleft = a.unleft+b.unleft-matched;
    result.unright = a.unright+b.unright-matched;
    return result;
}

vertex stree[4000000];
string str; 

void build_tree(int node, int left, int right) {
    if (left == right) {
        stree[node].unleft = str[left]=='(';
        stree[node].unright = str[left]==')';
        return;
    }

    int ln = 2*node+1,
        rn = 2*node+2;
    int mid = (left+right)/2;
    build_tree(ln, left, mid);
    build_tree(rn, mid+1, right);
    stree[node] = merge(stree[ln], stree[rn]);
}

void update_tree(int node, int left, int right, int updex) {
    if (left == right && left == updex) {
        stree[node].unleft = !stree[node].unleft;
        stree[node].unright = !stree[node].unright;
        return;
    }

    if (left > updex || right < updex) return;

    int ln = 2*node+1,
        rn = 2*node+2;
    int mid = (left+right)/2;
    update_tree(ln, left, mid, updex);
    update_tree(rn, mid+1, right, updex);
    stree[node] = merge(stree[ln], stree[rn]);

    // cout << "Segment :" << left << " " << right << " " << stree[node].valid << endl;
}

int main() {
    // UPDATE THIS
    int t = 10;
    int oldt = t;
    while (t--) {
        int n; cin >> n;
        cin >> str;
        int m; cin >> m;
        build_tree(0, 0, n-1);
        cout << "Test " << oldt-t << ":" << endl;
        for (int cs=0; cs<m; cs++) {
            int k; cin >> k;
            if (k == 0) {
                if (stree[0].unleft == 0 && stree[0].unright == 0)
                    cout << "YES" << endl;
                else
                    cout << "NO" << endl;
            } else {
                update_tree(0, 0, n-1, k-1);
            }
        }
    }

    return 0;
}
