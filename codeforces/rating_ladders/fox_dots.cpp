#include <bits/stdc++.h>
using namespace std;

int n, m; 
char matrix[100][100];
int color[100][100];

int addx[4] = {0, 0, 1, -1},
    addy[4] = {1, -1, 0, 0};

bool DFS(int i, int j, int x, int y) {
    color[i][j] = 1;
    for (int k=0; k<4; k++) {
        int nx = i+addx[k],
            ny = j+addy[k];
        if (nx >= 0 && nx < n &&
            ny >= 0 && ny < m &&
            matrix[nx][ny] == matrix[i][j] &&
            !(x == nx && y == ny)) {
            if (color[nx][ny] == 1) {
                // cout << i << " " << j << endl;
                // cout << nx << " " << ny << endl;
                return true;
            } else {
                if (DFS(nx, ny, i, j)) return true;
            }
        }
    }

    color[i][j] = 2;
    return false;
}

int main() {
    cin >> n >> m;
    for (int i=0; i<n; i++) {
        string str; cin >> str;
        for (int j=0; j<m; j++) {
            matrix[i][j] = str[j];
            color[i][j] = 0;
        }
    }

    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if (color[i][j] == 0) {
                if (DFS(i, j, -1, -1)) {
                    cout << "Yes" << endl;
                    return 0;
                }
            }
        }
    }

    cout << "No" << endl;

    return 0;
}
