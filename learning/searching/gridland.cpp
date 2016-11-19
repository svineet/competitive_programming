#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    vector < pair<int, int> > limits;
    limits.reserve(n);
    for (int i=0; i<n; i++) {
        pair<int, int> temp;
        temp.first = -1;
        temp.second = -1;
        limits[i] = temp;
    }

    for (int i=0; i<k; i++) {
        int r, c1, c2;
        cin >> r >> c1 >> c2;
        r--;

        if (c1<limits[r].first || limits[r].first == -1) {
            limits[r].first = c1;
        }
        if (c2>limits[r].second || limits[r].second == -1) {
            limits[r].second = c2;
        }
    }

    int usables = m*n;
    for (int i=0; i<n; i++) {
        if (limits[i].first == -1 || limits[i].second == -1)
            continue;
        usables -= limits[i].second-limits[i].first+1;
    }
    cout << usables << endl;

    return 0;
}
