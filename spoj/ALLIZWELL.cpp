#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

char matrix[100][100];
int visited[100][100];
int r, c;
string AIM = "ALLIZZWELL";

bool dfs(int x, int y, int lindex) {
    if (lindex == 9)
        return true;

    bool result = false;
    visited[x][y] = 1;
    for (int i=x-1; i<=x+1; i++) {
        for (int j=y-1; j<=y+1; j++) {
            if (i>=0 && i<r &&
                j>=0 && j<c &&
                matrix[i][j] == AIM[lindex+1] &&
                visited[i][j] != 1) {
                result = result || dfs(i, j, lindex+1);
            }
        }
    }
    visited[x][y] = 0;
    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    int t; cin >> t;
    while (t--) {
        cin >> r >> c;
        for (int i=0; i<r; i++) {
            string in; cin >> in;
            for (int j=0; j<c; j++) {
                matrix[i][j] = in[j];
                visited[i][j] = 0;
            }
        }

        bool result = false;
        for (int i=0; i<r; i++) {
            for (int j=0; j<c; j++) {
                if (matrix[i][j] == 'A') {
                    result = result || dfs(i, j, 0);
                }
                if (result) break;
            }
            if (result) break;
        }
        if (result)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}
