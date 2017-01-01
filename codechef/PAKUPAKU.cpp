#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m; cin >> n >> m;
    char matrix[n][m];
    int dist[n][m];
    int sx, sy, ex, ey;
    int addx[4] = {0, 0, -1, 1},
        addy[4] = {1, -1, 0, 0};

    for (int i=0; i<n; i++) {
        string str; cin >> str;
        for (int j=0; j<m; j++) {
            matrix[i][j] = str[j];
            dist[i][j] = -1;
            if (str[j] == 'S') {
                sx = i; sy = j;
            } else if (str[j] == 'E') {
                ex = i; ey = j;
            }
        }
    }

    queue< pair<int, int> > Q;
    dist[sx][sy] = 0;
    Q.push({sx, sy});
    while (!Q.empty()) {
        int x = Q.front().first;
        int y = Q.front().second;
        Q.pop();
        for (int i=0; i<4; i++) {
            int nx = x+addx[i],
                ny = y+addy[i];
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && dist[nx][ny] == -1 &&
                    matrix[nx][ny] != '#') {
                dist[nx][ny] = dist[x][y] + 1;
                Q.push({nx, ny});
            }
        }
    }

    cout << dist[ex][ey] << endl;

    return 0;
}
