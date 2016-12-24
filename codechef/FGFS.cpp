#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

struct triplet {
    int s, f, p;
};

bool compare(const triplet &a,
             const triplet &b) {
    if (a.f<b.f)
        return true;
    else
        return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    int t; cin >> t;
    while (t--) {
        long long n, k; cin >> n >> k;
        triplet array[n];
        unordered_map<int, int> last_comps;
        // Map compartment to the last time it was used.
        for (int i=0; i<n; i++) {
            triplet temp;
            cin >> temp.s >> temp.f >> temp.p;
            last_comps[temp.p] = 0;
            array[i] = temp;
        }
        sort (array, array+n, compare);

        int took = 0;
        for (int i=0; i<n; i++) {
            triplet current = array[i];
            if (current.s>=last_comps[current.p]) {
                // We can take this one
                took++;
                last_comps[current.p] = current.f;
            }
        }
        cout << took << endl;
    }

    return 0;
}
