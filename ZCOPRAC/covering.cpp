#include <iostream>
#include <algorithm>
using namespace std;

pair<int, int> intersect_dat(pair<int, int> a,
                             pair<int, int> b) {
    pair<int, int> result = make_pair(-1, -1);
    pair<int, int> smaller = min(a, b),
                   bigger = max(a, b);
    if (a == b) {
        return a;
    }

    if (smaller.second < bigger.first) {
        // They don't intersect eg: [1, 3] [4, 5]
    }
    else if (smaller.second > bigger.second) {
        // [3, 50] [40, 45] -> [40, 45]
        result.first = bigger.first;
        result.second = bigger.second;
    }
    else {
        result.first = bigger.first;
        result.second = smaller.second;
        // They do intersect: [1, 4], [4, 6] -> [4,4]
        // [1, 6] [4, 10000]
    }
    return result;
}

bool custom_compare(const pair<int, int> &a,
                    const pair<int, int> &b) {
    pair<int, int> x = make_pair(a.second, a.first),
                   y = make_pair(b.second, b.first);
    return x<y;
}

int main() {
    int n; cin >> n;
    pair<int, int> array[n];
    for (int i=0; i<n; i++) {
        int t1, t2; cin >> t1 >> t2;
        array[i] = make_pair(t1, t2);
    }
    sort(array, array+n, custom_compare);
    //for (int i=0; i<n; i++)
    //    cout << array[i].first << " " << array[i].second << endl;
    //cout << endl;

    int sets_needed = n;
    pair<int, int> prev = array[0];
    for (int i=1; i<n; i++) {
        pair<int, int> intersection;
        intersection = intersect_dat(prev, array[i]);
        //cout << intersection.first << " " << intersection.second << endl;
        if (intersection.first != -1) {
            sets_needed--;
            prev = intersection;
        }
        else {
            prev = array[i];
        }
    }
    cout << sets_needed << endl;

    return 0;
}
