#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    pair<int, int> dat;
    for (int i=0; i<n; i++) {
        cin >> dat[i].first >> dat[i].second;
    }
    pair<int, int> lim[n+1];
    if (dat[0].second == 1) {
        lim[0] = {1900, 1e9};
    } else {
        lim[0] = {-1e9, 1899};
    }

    for (int i=0; i<n; i++) {
        if (dat[i].second == 1) {

        } else {
        }
    }

    return 0;
}
