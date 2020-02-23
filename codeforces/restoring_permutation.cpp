#include <bits/stdc++.h>
using namespace std;

bool present[1000] = {0};

int main(int argc, char **argv) {
    ios_base::sync_with_stdio(false);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        int arr[n];
        for (int i=0; i<n; i++) cin >> arr[i];

        for (int i=1; i<=2*n; i++) present[i] = false;
        for (int i=0; i<n; i++) present[arr[i]] = true;

        vector<int> choose;
        // Collect all not present items
        for (int i=1; i<=2*n; i++)
            if (!present[i]) choose.push_back(i);

        vector<int> result;
        bool possible = true;
        for (int i=0; i<n; i++) {
            // Find the item that is just bigger than the current array element
            auto idx = lower_bound(choose.begin(), choose.end(), arr[i]);
            if (idx == choose.end()) {
                possible = false;
            } else {
                result.push_back(*idx);
                choose.erase(idx);
            }
        }

        if (!possible) {
            cout << -1 << endl;
        } else {
            for (int i=0; i<n; i++)
                cout << arr[i] << " " << result[i] << " ";
            cout << endl;
        }
    }

    return 0;
}

