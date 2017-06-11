/*
ID: saivine1
PROG: barn1
LANG: C++11
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("barn1.in", "r", stdin);
    freopen("barn1.out", "w", stdout);

    int m, s, c;
    cin >> m >> s >> c;
    int cows[c];
    for (int i=0; i<c; i++)
        cin >> cows[i];

    sort (cows, cows+c);
    pair<int, int> diff[c-1];
    for (int i=0; i<c-1; i++) {
        diff[i] = {cows[i+1]-cows[i], i};
    }
    sort (diff, diff+c-1, greater<pair<int, int>>());

    vector<int> indices;
    indices.reserve(m+1);
    indices.push_back(-1);
    indices.push_back(c-1);
    for (int i=0; i<min(m, c)-1; i++) {
        indices.push_back(diff[i].second);
    }
    sort (indices.begin(), indices.end());

    int ans = 0;
    for (int i=1; i<min(m, c)+1; i++) {
        // cout << indices[i] << endl;
        ans += cows[indices[i]]-cows[indices[i-1]+1]+1;
        // cout << cows[indices[i]] << " - " <<
        //    cows[indices[i-1]+1] << endl;
    }
    cout << ans << endl;

    return 0;
}
