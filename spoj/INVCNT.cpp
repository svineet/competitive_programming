#include <bits/stdc++.h>
using namespace std;

int get_sum(int tree[], int element) {
    int sm = 0;
    int index = element;
    while (index > 0) {
        sm += tree[index]; // Add frequency of this element
        index -= (index)&(-index);
        // Go down the tree ladder
        // of responsibilities.
        // We have already counted all
        // responsible elements of this element.
    }
    return sm;
}

void update_tree(int tree[], int maxelem, int element, int diff) {
    int index = element;
    while (index <= maxelem) {
        tree[index] += diff;
        index += (index)&(-index);
    }
}

int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        int array[n];
        int maxelem = 0;
        for (int i=0; i<n; i++) {
            cin >> array[i];
            maxelem = max(maxelem, array[i]);
        }

        int BITree[maxelem+1];
        memset(BITree, 0, sizeof(BITree));

        long long invcnt = 0;
        for (int i=n-1; i>=0; i--) {
            invcnt += get_sum(BITree, array[i]);
            // Count number of things that we have seen
            // before that
            // are lower than array[i] in value
            // but we saw them ahead of array[i]
            // ( at a j such that j > i)
            // using BIT's cumulative sum function.
            update_tree(BITree, maxelem, array[i], 1);
            // We just saw an element "array[i]",
            // so increment its frequency by 1.
        }
        cout << invcnt << endl;
    }

    return 0;
}
