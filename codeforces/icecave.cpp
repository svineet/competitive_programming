#include <bits/stdc++.h>
using namespace std;

char matrix[501][501];
bool visited[501][501];
int si, sj, fi, fj; 
int n, m; 
int addx[4] = {0, 0, 1, -1},
    addy[4] = {1, -1, 0, 0};

bool DFS(int x, int y) {
    for (int i=0; i<4; i++) {
        int nx = x+addx[i],
            ny = y+addy[i];
        if (nx>=0 && nx<n && ny>=0 && ny<m) {
            if (nx == fi && ny == fj) {
                if (matrix[nx][ny] == 'X')
                    return true;
                // If it was already broken,
                // just jump in.

                int neigh = 0;
                for (int j=0; j<4; j++) {
                    int nx2 = nx+addx[j],
                        ny2 = ny+addy[j];
                    if (nx2>=0 && nx2<n && ny2>=0 && ny2<m && matrix[nx2][ny2] == '.')
                        neigh++;
                }
                if (neigh >= 2) return true;
                // Need at least two intact neighbours.
                // One is the entry point and the other
                // acts as a buffer.

                return false;
            }

            if (!visited[nx][ny] && matrix[nx][ny] != 'X') {
                visited[nx][ny] = true;
                if (DFS(nx, ny)) {
                    return true;
                }
            }
        }
    }
    
    return false;
}

int main() {
    cin >> n >> m;
    for (int i=0; i<n; i++) {
        string str; cin >> str;
        for (int j=0; j<m; j++) {
            matrix[i][j] = str[j];
        }
    }

    cin >> si >> sj; si--; sj--;
    cin >> fi >> fj; fi--; fj--;

    if (si == fi && sj == fj) {
        int neigh = 0;
        for (int j=0; j<4; j++) {
            int nx2 = fi+addx[j],
                ny2 = fj+addy[j];
            if (nx2>=0 && nx2<n && ny2>=0 && ny2<m && matrix[nx2][ny2] == '.')
                neigh++;
        }
        if (neigh>=1) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }

        return 0;
    }

    for (int i=0; i<4; i++) {
        int nx = si+addx[i],
            ny = sj+addy[i];
        if (nx == fi && ny == fj) {
            if (matrix[nx][ny] == 'X') {
                cout << "YES" << endl;
            } else {
                int neigh = 0;
                for (int j=0; j<4; j++) {
                    int nx2 = fi+addx[j],
                        ny2 = fj+addy[j];
                    if (nx2>=0 && nx2<n && ny2>=0 && ny2<m && matrix[nx2][ny2] == '.')
                        neigh++;
                }
                if (neigh>=1) {
                    cout << "YES" << endl;
                } else {
                    cout << "NO" << endl;
                }
            }

            return 0;
        }
    }

    visited[si][sj] = true;
    if (DFS(si, sj))
        cout << "YES";
    else
        cout << "NO";
    cout << endl;

    return 0;
}
