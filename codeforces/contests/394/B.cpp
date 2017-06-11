#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, l; cin >> n >> l;
    int arr1[n], arr2[n];

    for (int i=0; i<n; i++) {
        cin >> arr1[i];
    }
    for (int i=0; i<n; i++) {
        cin >> arr2[i];
    }

    for (int k=0; k<=l; k++) {
        // See if arr2 is arr1+k mod l
        bool ye = true;
        vector<int> moves; moves.reserve(n);
        for (int i=0; i<n; i++) {
            if (k<=arr2[i]) {
                moves.push_back(arr2[i]-k);
            } else {
                moves.push_back(l-abs(arr2[i]-k));
            }
        }
        sort (moves.begin(), moves.end());
        for (int i=0; i<n; i++) {
            ye = ye && arr1[i]==moves[i];
            // cout << moves[i] << " ";
        }
        // cout << endl;

        if (ye) {
            cout << "YES" << endl;
            return 0;
        }
    }

    cout << "NO" << endl;

    return 0;
}
