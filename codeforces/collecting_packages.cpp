#include <bits/stdc++.h>
using namespace std;

void print_pair(pair<int, int> coord) {
    for (int i=0; i<coord.first; i++)
        cout << "R";
    for (int i=0; i<coord.second; i++)
        cout << "U";
}

int main(int argc, char **argv) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        pair<int, int> coord[n];
        for (int i=0; i<n; i++)
            cin >> coord[i].first >> coord[i].second;

        sort(coord, coord+n);

        pair<int, int> curpos = coord[0];
        bool possible = true;
        for (int i=1; i<n; i++) {
            pair<int, int> diff = make_pair(coord[i].first-curpos.first,
                    coord[i].second-curpos.second);
            if (diff.first >= 0 && diff.second >= 0) {
                // Everything is fine, go on.
                // cout << coord[i].first << " " << coord[i].second << endl;
            } else {
                possible = false;
                break;
            }
            curpos = coord[i];
        }

        if (!possible) {
            cout << "NO" << endl;
        } else {
            cout << "YES" << endl;

            pair<int, int> curpos = coord[0];
            print_pair(curpos);
            for (int i=1; i<n; i++) {
                pair<int, int> diff = make_pair(coord[i].first-curpos.first,
                        coord[i].second-curpos.second);
                print_pair(diff);
                curpos = coord[i];
            }
            cout << endl;
        }
    }

    return 0;
}

