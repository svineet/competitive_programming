#include <bits/stdc++.h>
using namespace std;

int stree[1<<18];
int array[1<<18];
int n, m;
int nlogged;

void build_tree(int node, int left, int right) {
    if (left == right) {
        stree[node] = array[left];
        return;
    }

    int mid = (left+right)/2;
    build_tree(2*node+1, left, mid);
    build_tree(2*node+2, mid+1, right);
    if (int(log2(right-left+1))%2 == 1) {
        stree[node] = stree[2*node+1] | stree[2*node+2];
    } else {
        stree[node] = stree[2*node+1] ^ stree[2*node+2];
    }
    // cout << left << " " << right << " -> " << stree[node] << endl;
}

void update_tree(int node, int left, int right, int updex, int value) {
    if (left == right && left == updex) {
        array[left] = value;
        stree[node] = value;
        return;
    }

    if (updex<left || updex>right) return;

    int mid = (left+right)/2;
    update_tree(2*node+1, left, mid, updex, value);
    update_tree(2*node+2, mid+1, right, updex, value);
    if (int(log2(right-left+1))%2 == 1) {
        stree[node] = stree[2*node+1] | stree[2*node+2];
    } else {
        stree[node] = stree[2*node+1] ^ stree[2*node+2];
    }
    // cout << left << " " << right << " -> " << stree[node] << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin >> nlogged >> m;
    n = 1<<nlogged;
    for (int i=0; i<n; i++) {
        cin >> array[i];
    }

    build_tree(0, 0, n-1);

    for (int i=0; i<m; i++) {
        int p, ap; cin >> p >> ap;
        p--;
        update_tree(0, 0, n-1, p, ap);

        /*for (int i=0; i<n; i++)
            cout << array[i] << " ";
        cout << endl;*/

        cout << stree[0] << "\n";
    }
}
