/*
ID: saivine1
PROG: milk
LANG: C++11
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("milk.in", "r", stdin);
    freopen("milk.out", "w", stdout);

    int need, n; cin >> need >> n;
    pair<int, int> offers[n];
    for (int i=0; i<n; i++)
        cin >> offers[i].first >> offers[i].second;
    sort (offers, offers+n);

    long long cost = 0;
    int i = 0;
    while (need != 0) {
        if (offers[i].second<=need) {
            cost += offers[i].first*offers[i].second;
            need -= offers[i].second;
        } else {
            cost += offers[i].first*need;
            need = 0;
        }

        i++;
    }
    cout << cost << endl;

    return 0;
}
