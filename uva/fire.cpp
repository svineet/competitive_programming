#include <bits/stdc++.h>
using namespace std;

bool visited[1001][1001];
bool fvisited[1001][1001];
int joe_dist[1001][1001];
int fire_dist[1001][1001];

struct point {
    int x, y;
    int cost;
    int type;

    point(int i, int j, int c) {
        x = i; y = j; cost = c;
    }
};

int addx[4] = {0, 0, -1, 1},
    addy[4] = {1, -1, 0, 0};

int main() {
    int t; cin >> t;
    while (t--) {
        int r, c; cin >> r >> c;
        char matrix[r][c];
        int joer, joec;
        vector< pair<int, int> > fires;
        for (int i=0; i<r; i++) {
            string str; cin >> str;
            for (int j=0; j<c; j++) {
                matrix[i][j] = str[j];
                fvisited[i][j] = visited[i][j] = false;
                joe_dist[i][j] = fire_dist[i][j] = 1e8;

                if (matrix[i][j] == 'F') {
                    fires.push_back({i, j});
                } else if (matrix[i][j] == 'J') {
                    joer = i; joec = j;
                }
            }
        }

        queue<point> Q;
        joe_dist[joer][joec] = 0;
        visited[joer][joec] = true;
        Q.push(point(joer, joec, 0));
        // Node has x, y, cost
        while (!Q.empty()) {
            point node = Q.front();
            joe_dist[node.x][node.y] = node.cost;
            Q.pop();
            for (int i=0; i<4; i++) {
                int nx = node.x + addx[i],
                    ny = node.y + addy[i];
                if (nx>=0 && nx<r && ny>=0 && ny<c && !visited[nx][ny] && matrix[nx][ny] != '#') {
                    visited[nx][ny] = true;
                    Q.push(point(nx, ny, node.cost+1));
                }
            }
        }

        for (auto iter: fires) {
            fire_dist[iter.first][iter.second] = 0;
            fvisited[iter.first][iter.second] = true;
            Q.push(point(iter.first, iter.second, 0));
        }

        while (!Q.empty()) {
            point node = Q.front();
            fire_dist[node.x][node.y] = node.cost;
            Q.pop();
            for (int i=0; i<4; i++) {
                int nx = node.x + addx[i],
                    ny = node.y + addy[i];
                if (nx>=0 && nx<r && ny>=0 && ny<c && !fvisited[nx][ny] && matrix[nx][ny] != '#') {
                    //cout << nx << " " << ny << endl;
                    fvisited[nx][ny] = true;
                    Q.push(point(nx, ny, node.cost+1));
                }
            }
        }

        /*for (int i=0; i<r; i++) {
            for (int j=0; j<c; j++) {
                cout << joe_dist[i][j] << " ";
            }
            cout << endl;
        }
        for (int i=0; i<r; i++) {
            for (int j=0; j<c; j++) {
                cout << fire_dist[i][j] << " ";
            }
            cout << endl;
        }*/

        int best = 1e9;
        for (int i=0; i<c; i++) {
            if (matrix[0][i] != '#' && joe_dist[0][i] < fire_dist[0][i])
                best = min(best, joe_dist[0][i]);
            if (matrix[r-1][i] != '#' && joe_dist[r-1][i] < fire_dist[r-1][i])
                best = min(best, joe_dist[r-1][i]);
        }

        for (int i=0; i<r; i++) {
            if (matrix[i][0] != '#' && joe_dist[i][0] < fire_dist[i][0])
                best = min(best, joe_dist[i][0]);
            if (matrix[i][c-1] != '#' && joe_dist[i][c-1] < fire_dist[i][c-1])
                best = min(best, joe_dist[i][c-1]);
        }

        if (best == 1e9)
            cout << "IMPOSSIBLE" << endl;
        else
            cout << best+1 << endl;
    }

    return 0;
}
