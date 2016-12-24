#include <bits/stdc++.h>
using namespace std;

int tree[1000001];

int get_sum(int elem) {
    int sm = 0;
    while (elem > 0) {
        sm += tree[elem];
        elem -= (elem)&(-elem);
    }
    return sm;
}

void update_tree(int elem, int maxelem) {
    while (elem <= maxelem) {
        tree[elem] += 1;
        elem += (elem)&(-elem);
    }
}

int main() {
    int n; cin >> n;
    int array[n], sortarray[n];
    for (int i=0; i<n; i++) {
        cin >> array[i];
        sortarray[i] = array[i];
    }
    sort (sortarray, sortarray+n);

    for (int i=0; i<n; i++) {
        int fakedex = lower_bound(sortarray, sortarray+n, array[i])-sortarray+1;
        int rank = i+1-get_sum(fakedex);
        update_tree(fakedex, n+1);
        cout << rank << "\n";
    }

    return 0;
}
