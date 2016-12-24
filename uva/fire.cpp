#include <bits/stdc++.h>
using namespace std;

struct point {
    int x, y;
    int cost;

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
        int joer, joec, firer, firec;
        for (int i=0; i<r; i++) {
            string str; cin >> str;
            for (int j=0; j<c; j++) {
                matrix[i][j] = str[j];
                if (matrix[i][j] == 'F') {
                    firer = i; firec = j;
                } else if (matrix[i][j] == 'J') {
                    joer = i; joec = j;
                }
            }
        }

        int joe_dist[r][c], fire_dist[r][c];
        bool visited[r][c] = {false};
        joe_dist[joer][joec] = 0;
        queue<point> Q;
        Q.push(point(joer, joec, 0));
        while (!Q.empty()) {
            point node = Q.front();
            Q.pop();
            for (int i=0; i<4; i++) {
                int nx = node.x + addx[i],
                    ny = node.y + addy[i];
                if (nx>=0 && nx<r && ny>=0 && ny<c) {
                }
            }
        }
    }

    return 0;
}
