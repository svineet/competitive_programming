#include <bits/stdc++.h>
using namespace std;

int main(int argc, char **argv) {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        unordered_map<int, int> count;
        for (int i=0; i<n; i++) {
            int x; cin >> x;
            if (count.find(x) == count.end())
                count[x] = 1;
            else
                count[x]++;
        }

        int unique_elems = count.size();
        auto iter = count.begin();
        int best = 0;
        while (iter != count.end()) {
            int key = iter->first, val = iter->second;
            best = max(best, min(val, unique_elems-1));
            if (val >= unique_elems+1)
                best = max(best, unique_elems);

            iter++;
        }
        cout << best << endl;
    }

    return 0;
}

