#include <bits/stdc++.h>
using namespace std;

int n, m, k;
int matrix[501][501];
int visited[501][501];
int numvis = 0;
int totalvisitable = 0;

int xadd[4] = {0, 0, -1, 1};
int yadd[4] = {1, -1, 0, 0};

void DFS(int x, int y) {
    numvis++;
    if (numvis>=totalvisitable-k) return;

    for (int i=0; i<4; i++) {
        int nx = x+xadd[i],
            ny = y+yadd[i];
        if (nx>=0 && nx<n &&
            ny>=0 && ny<m &&
            matrix[nx][ny] == 1 &&
            !visited[nx][ny])
        {
            visited[nx][ny] = 1;
            DFS(nx, ny);
            if (numvis>=totalvisitable-k) return;
        }
    }
}

int main() {
    cin >> n >> m >> k;
    for (int i=0; i<n; i++) {
        string inp; cin >> inp;
        for (int j=0; j<m; j++) {
            if (inp[j] == '.')
                matrix[i][j] = 1;
            else
                matrix[i][j] = 2;

            if (inp[j] == '.') totalvisitable++;
            visited[i][j] = 0;
        }
    }

    int sx, sy;
    bool done = false;
    for (int i=0; i<n && !done; i++) {
        for (int j=0; j<m && !done; j++) {
            if (matrix[i][j] == 1) {
                sx = i; sy = j;
                done = true;
            }
        }
    }

    visited[sx][sy] = 1;
    DFS(sx, sy);
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if (!visited[i][j] && matrix[i][j] == 1)
                cout << "X";
            if (visited[i][j] && matrix[i][j] == 1)
                cout << '.';
            if (matrix[i][j] == 2)
                cout << '#';
        }
        cout << endl;
    }

    return 0;
}
