#include <bits/stdc++.h>
using namespace std;

int stree[4000004];
int arr[4000004];

void build_tree(int node, int left, int right) {
    if (left == right) {
        stree[node] = 1;
        return;
    }

    int mid = (left+right)/2;
    build_tree(2*node+1, left, mid);
    build_tree(2*node+2, mid+1, right);
    stree[node] = stree[2*node+1]+stree[2*node+2];
}

int search_tree(int node, int left, int right, int freq) {
    if (left == right && freq == 1) {
        return left;
    } else if (left == right) {
        cout << "FUKKKK" << endl;
        cout << left << endl;
        cout << freq << endl;
    }

    if (stree[2*node+1]<freq) {
        // Go right with a decreased frequency
        return search_tree(2*node+2, (left+right)/2 + 1, right, freq-stree[2*node+1]);
    } else {
        // Go left with the same frequency
        return search_tree(2*node+1, left, (left+right)/2, freq);
    }
}

void update_tree(int node, int left, int right, int updex) {
    if (updex<left || updex>right) return;
    if (left == right && left == updex) {
        stree[node] = 0;
        return;
    }

    int mid = (left+right)/2;
    update_tree(2*node+1, left, mid, updex);
    update_tree(2*node+2, mid+1, right, updex);
    stree[node] = stree[2*node+1]+stree[2*node+2];
}

int main() {
    int n; cin >> n;
    for (int i=0; i<n; i++) cin >> arr[i];
    build_tree(0, 0, n-1);

    int m; cin >> m;
    while (m--) {
        int bookdex; cin >> bookdex;
        int index = search_tree(0, 0, n-1, bookdex);
        cout << arr[index] << endl;
        update_tree(0, 0, n-1, index);
    }

    return 0;
}
