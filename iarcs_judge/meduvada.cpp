#include <bits/stdc++.h>
using namespace std;

char matrix[1005][1005];
int visited[1005][1005];
int addx[4] = {1, -1, 0, 0};
int addy[4] = {0, 0, 1, -1};
int sr, sc; int r, c;

bool DFS(int x, int y) {
    /*for (int i=0; i<r; i++) {
        for (int j=0; j<c; j++) {
            cout << matrix[i][j];
        }
        cout << endl;
    }
    cout << endl;*/

    for (int i=0; i<4; i++) {
        int nx, ny;
        nx = x+addx[i]; ny = y+addy[i];
        if (nx<0) nx=r-1;
        if (ny<0) ny=c-1;
        if (nx==r) nx=0;
        if (ny==c) ny=0;

        assert(nx>=0 && nx<r);
        assert(ny>=0 && ny<c);
        if (!visited[nx][ny] && matrix[nx][ny] != '#') {
            if (matrix[nx][ny] == 'D') {
                cout << "YES" << endl;
                for (int i=0; i<r; i++) {
                    for (int j=0; j<c; j++) {
                        cout << matrix[i][j];
                    }
                    cout << endl;
                }
                return true;
            }

            visited[nx][ny] = true;
            matrix[nx][ny] = 'x';
            bool done = DFS(nx, ny);
            if (done) return true;
            matrix[nx][ny] = '.';
        }
    }
    return false;
}

int main() {
    cin >> r >> c;
    for (int i=0; i<r; i++) {
        for (int j=0; j<c; j++) {
            cin >> matrix[i][j];
            if (matrix[i][j] == 'M') {
                sr = i; sc = j;
            }
        }
    }

    visited[sr][sc] = 1;
    if (!DFS(sr, sc)) {
        cout << "NO" << endl;
    }
}
