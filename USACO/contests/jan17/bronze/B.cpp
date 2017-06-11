#include <bits/stdc++.h>
using namespace std;

int play_it(pair<int, int> games[], int n, int mean[4]) {
    int won = 0;
    for (int i=0; i<n; i++) {
        int a = mean[games[i].first];
        int b = mean[games[i].second];
        if (a == 3 && b == 1)
            won++;
        if (a == 1 && b == 2)
            won++;
        if (a == 2 && b == 3)
            won++;
    }
    return won;
}

int main() {
    freopen("hps.in", "r", stdin);
    freopen("hps.out", "w", stdout);

    int n; cin >> n;
    pair<int, int> games[n];
    for (int i=0; i<n; i++) {
        cin >> games[i].first >> games[i].second;
    }

    int mean[4] = {0, 1, 2, 3};
    // mean[i] indicates the "actual"
    // meaning of that i.
    // mean[i] = 1, 2, 3
    // 1 beats 2, 2 beats 3,
    // 3 beats 1.
    // Try all meanings
    int best = -1e8;
    for (int i=1; i<=3; i++) {
        for (int j=1; j<=3; j++) {
            if (i == j) continue;
            for (int k=1; k<=3; k++) {
                if (k == i || k == j) continue;
                // means[1] has meaning i
                // [2] is j
                // [3] is k
                mean[1] = i;
                mean[2] = j;
                mean[3] = k;

                best = max(best, play_it(games, n, mean));
            }
        }
    }
    cout << best << endl;

    return 0;
}
