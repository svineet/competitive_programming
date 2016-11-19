#include <iostream>
#include <algorithm>
using namespace std;

struct blaster {
    pair<int, int> coord;
    int start;
    int freq;
};

bool pulsed(int x, int y, int time, int k, blaster blasters[],
            int n, int m) {
    bool rekt = false;
    for (int i=0; i<k; i++) {
        if (time < blasters[i].start)
            continue;

        int time_taken = time-blasters[i].start;
        int bx = blasters[i].coord.first,
            by = blasters[i].coord.second;
        int dx = abs(x-bx),
            dy = abs(y-by);
        if (dx==0) {
            if ((time_taken-dy)%blasters[i].freq==0)
                rekt = true;
        }
        else if (dy==0) {
            if ((time_taken-dx)%blasters[i].freq==0)
                rekt = true;
        }
    }
    return rekt;
}

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    int dp[n][m];
    blaster blasters[k];
    for (int i=0; i<k; i++) {
        blaster temp;
        cin >> temp.coord.first >> temp.coord.second;
        cin >> temp.start >> temp.freq;
        temp.coord.first--; temp.coord.second--;
        blasters[i] = temp;
    }
    dp[0][0] = (pulsed(0, 0, 0, k, blasters, n, m)?-1:0);
    // dp[i][j] is -1 if it is unreachable under all circumstances
    // x, y, time, k, blasters, n, m
    for (int i=1; i<n; i++) {
        if (dp[i-1][0] == -1) {
            dp[i][0] = -1;
            continue;
        }
        if (pulsed(i, 0, 1+dp[i-1][0], k, blasters, n, m))
            dp[i][0] = -1;
        else
            dp[i][0] = 1+dp[i-1][0];
    }
    for (int j=1; j<m; j++) {
        if (dp[0][j-1] == -1) {
            dp[0][j-1] = -1;
            continue;
        }
        if (pulsed(0, j, 1+dp[0][j-1], k, blasters, n, m))
            dp[0][j] = -1;
        else
            dp[0][j] = 1+dp[0][j-1];
    }
    for (int i=1; i<n; i++) {
        for (int j=1; j<m; j++) {
            dp[i][j] = -1;
            if (dp[i-1][j] == -1 && dp[i][j-1] == -1)
                continue;
            // Node is unreachable under any circumstance

            bool upye = (dp[i-1][j] != -1 &&
                         !pulsed(i, j, 1+dp[i-1][j], k, blasters, n, m)),
                 lefy = (dp[i][j-1] != -1 &&
                         !pulsed(i, j, 1+dp[i][j-1], k, blasters, n, m));

            if (upye && lefy) {
                dp[i][j] = min(1+dp[i-1][j],
                               1+dp[i][j-1]);
            }
            if (upye && !lefy) {
                dp[i][j] = 1+dp[i-1][j];
            }
            if (!upye && lefy) {
                dp[i][j] = 1+dp[i][j-1];
            }
        }
    }
    /*for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }*/
    if (dp[n-1][m-1] == -1) {
        cout << "NO" << endl;
    }
    else {
        cout << "YES" << endl;
        cout << dp[n-1][m-1] << endl;
    }

    return 0;
}
