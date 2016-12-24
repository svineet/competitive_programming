#include <bits/stdc++.h>
using namespace std;

int pos[200005];
bool comparor(const int a,
              const int b) {
    return pos[a]>pos[b];
}

bool comparator2(const pair<int, int> a,
                 const pair<int, int> b) {
    return a.second<b.second;
}

vector< pair<int, int> > sorted;

int main() {
    int n; cin >> n;
    int bids[n+1];
    for (int i=0; i<n; i++) {
        int a, b; cin >> a >> b;
        bids[a] = b;
    }
    sorted.reserve(n+1);
    sorted.push_back(make_pair(0, 0));
    for (int i=0; i<n; i++) {
        sorted.push_back(make_pair(i+1, bids[i+1]));
    }

    sort (sorted.begin(), sorted.end(), comparator2);
    for (int i=0; i<n; i++) {
        pos[sorted[i].first] = i;
    }

    int q; cin >> q;
    while (q--) {
        int k; cin >> k;
        int things[k];
        for (int i=0; i<k; i++)
            cin >> things[i];
        sort (things, things+k, comparor);

        int bptr = n-1;
        for (int i=0; i<k; i++) {
            if (things[i] == bptr) bptr--;
        }
        cout << sorted[bptr].first << " " << sorted[bptr].second << endl;
    }

    return 0;
}
