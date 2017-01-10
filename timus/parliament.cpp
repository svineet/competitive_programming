#include <bits/stdc++.h>
using namespace std;

const int LEET = -1337;
vector<int> order;
int tree[500000];
int maxmum = 0;

void make_tree(int *array, int left, int right, int treedex) {
    // treedex is the index where the current
    // node's value will live.
    // Make a tree out of BST's left-right-root
    // traversal
    // Left is 2*treedex + 1 and
    // Right is 2*treedex + 2

    //cout << left << " " << right << endl;

    maxmum = max(maxmum, treedex);
    if (right<left) return;
    if (left == right) {
        tree[treedex] = array[left];
        tree[2*treedex+1] = LEET; tree[2*treedex+2] = LEET;
        return;
    }

    tree[treedex] = array[right];
    bool allmore = true, allless = true;
    for (int i=left; i<right; i++) {
        if (array[i]>array[right]) allless = false;
        if (array[i]<array[right]) allmore = false;
    }
 
    int leftson = 2*treedex + 1,
        rightson = 2*treedex + 2;
    if (allmore) {
        tree[leftson] = LEET;
        make_tree(array, left, right-1, rightson);
    } else if (allless) {
        tree[rightson] = LEET;
        make_tree(array, left, right-1, leftson);
    } else {
        // Find and index 'i' such that
        // all indices left..i are less than 
        int index = 0;
        for (int i=left; i<right; i++) {
            if (array[i]<array[right] && array[i+1]>array[right]) {
                /*cout << "break" << endl;
                cout << left << " " << right << endl;
                cout << index << endl;*/
                index = i; break;
            }
        }
        make_tree(array, left, index, leftson);
        make_tree(array, index+1, right-1, rightson);
    }
}

void even_order(int treedex) {
    // right - left - cur
    if (tree[2*treedex+2] != LEET)
        even_order(2*treedex+2);
    if (tree[2*treedex+1] != LEET)
        even_order(2*treedex+1);

    if (tree[treedex] != LEET) order.push_back(tree[treedex]);
}

int main() {
    int n; cin >> n;
    int array[n];
    for (int i=0; i<n; i++) {
        cin >> array[i];
    }

    make_tree(array, 0, n-1, 0);
    // 0 is the root
    even_order(0);
    int len = order.size();
    for (int i=0; i<len; i++)
        cout << order[i] << " ";
    cout << endl;
}
