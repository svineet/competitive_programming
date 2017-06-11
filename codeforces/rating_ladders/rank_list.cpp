#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k; cin >> n >> k;
    pair<int, int> score[n];
    for (int i=0; i<n; i++)
        cin >> score[i].first >> score[i].second;

    sort (score, score+n,
          [] (const pair<int, int> a,
              const pair<int, int> b) {
            if (a.first != b.first)
                return a.first > b.first;
            else
                return b.second > a.second;
          });

    int rank[n];
    rank[0] = 1;
    for (int i=1; i<n; i++) {
        if (score[i] == score[i-1]) rank[i] = rank[i-1];
        else
            rank[i] = rank[i-1]+1;
    }

    cout << count(rank, rank+n, rank[k-1]) << endl;

    return 0;
}
