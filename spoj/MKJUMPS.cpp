#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

#define m(i, j) make_pair(i, j)
pair<int, int> adders[8] = {
    m(2, 1), m(2, -1),
    m(1, 2), m(1, -2),
    m(-2, 1), m(-2, -1),
    m(-1, 2), m(-1, -2)
};
int matrix[10][10] = {0};
int visited[10][10] = {0};
int n;

int dfs(int x, int y) {
    int best = 0;
    visited[x][y] = 1;
    for (int i=0; i<8; i++) {
        int nx = x+adders[i].first,
            ny = y+adders[i].second;
        if (nx>=0 && nx<n &&
            ny>=0 && ny<10 &&
            matrix[nx][ny] == 1 &&
            visited[nx][ny] != 1) {
            best = max(best, dfs(nx, ny));
        }
    }
    visited[x][y] = 0;
    return 1+best;
}

int main() {
    ios_base::sync_with_stdio(false);
    int cas = 1;
    while (true) {
        cin >> n;
        if (n==0) break;

        int sx = 0, sy = 0;
        int total = 0;
        for (int i=0; i<10; i++) {
            for (int j=0; j<10; j++) {
                matrix[i][j] = 0;
                visited[i][j] = 0;
            }
        }
        for (int i=0; i<n; i++) {
            int start, num; cin >> start >> num;
            total += num;

            for (int j=0; j<10; j++) {
                matrix[i][j] = (j>=start && j<start+num?1:0);
                visited[i][j] = 0;
            }
        }

        int res = total-dfs(sx, sy);
        if (res == 1) {
            cout << "Case " << cas << ", 1 square can not be reached." << endl;
        } else {
            cout << "Case " << cas << ", " << res << " squares can not be reached." << endl;
        }
        cas++;
    }
    return 0;
}
