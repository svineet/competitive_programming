#include <bits/stdc++.h>
using namespace std;

bool comp(const pair<int, int> a,
          const pair<int, int> b) {
    return a.second<b.second;
}

int main() {
    int n, l, r; cin >> n >> l >> r;

    int A[n];
    pair<int, int> rank[n];
    for (int i=0; i<n; i++) cin >> A[i];
    for (int i=0; i<n; i++) {
        cin >> rank[i].first;
        rank[i].second = i;
        // Real index is second;
    }

    sort (rank, rank+n);
    pair<int, int> B[n];
    // Selected C, real index.
    // We sort by real index at the end.
    // Set the first C to 0.
    B[0].first = l;
    B[0].second = rank[0].second;
    for (int i=1; i<n; i++) {
        B[i].first = B[i-1].first-A[rank[i-1].second];
        B[i].first += A[rank[i].second]+1;
        B[i].first = max(B[i].first, l);
        // Bring it into limits.
        B[i].second = rank[i].second;
        if (B[i].first>r) {
            cout << -1 << endl;
            return 0;
        }
    }

    sort (B, B+n, comp);
    for (int i=0; i<n; i++)
        cout << B[i].first << " ";
    cout << endl;

    return 0;
}
