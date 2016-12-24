#include <bits/stdc++.h>
using namespace std;

int n;
char matrix[100][100];
bool visited[100][100];
long long cnt;
int addx[4] = {0, 0, 1, -1},
    addy[4] = {1, -1, 0, 0};

void DFS(int x, int y) {
    /*cout << x << "  " << y << endl;
    cout << matrix[x][y] << endl;*/
    for (int i=0; i<4; i++) {
        int nx = x+addx[i],
            ny = y+addy[i];

        if ((nx == -1 && ny == 0)
            || (nx == 0 && ny == -1)
            || (nx == n && ny == n-1)
            || (nx == n-1 && ny == n))
            continue;
        // Edge conditions mentioned in
        // question.

        if (nx<0 || nx>=n || ny<0 || ny>=n || matrix[nx][ny] == '#') {
            //cout << nx << " " << ny << endl;
            cnt++;
        } else if (!visited[nx][ny]) {
            visited[nx][ny] = true;
            DFS(nx, ny);
        }
    }
}

int main() {
    cin >> n;
    for (int i=0; i<n; i++) {
        string str; cin >> str;
        for (int j=0; j<n; j++) {
            matrix[i][j] = str[j];
        }
    }

    visited[0][0] = true;
    DFS(0, 0);
    if (!visited[n-1][n-1]) {
        visited[n-1][n-1] = true;
        DFS(n-1, n-1);
    }

    cout << cnt*9 << endl;

    return 0;
}
