#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
using namespace std;

struct data {
    int x, y, state;
    int level;
};

int xadd[5] = {0, 1, -1, 0, 0};
int yadd[5] = {0, 0, 0, 1, -1};

int main() {
    int cs = 1;
    while (true) {
        int n, m, states; cin >> n >> m >> states;
        if (n == 0) break;

        int matrix[n][m][states] = {0};
        int visited[n][m][states] = {0};
        for (int s=0; s<states; s++) {
            for (int i=0; i<n; i++) {
                string input; cin >> input;
                for (int j=0; j<m; j++) {
                    if (input[j] == '1')
                        matrix[i][j][s] = 1;
                    else
                        matrix[i][j][s] = 0;

                    visited[i][j][s] = 0;
                }
            }
        }

        if (matrix[0][0][0] == 1) {
            cout << "Case " << cs++ << ": Luke and Leia cannot escape." << endl;
            continue;
        }

        queue<data> Q;
        data start; start.x = 0; start.y = 0; start.state = 0;
        start.level = 0;
        visited[0][0][0] = 1;
        Q.push(start);

        int target = -1;
        while (!Q.empty()) {
            data current = Q.front();
            Q.pop();
            int x = current.x,
                y = current.y,
                state = current.state,
                level = current.level;
            /*cout << "Explore: " << x << ", " << y << ", ";
            cout << state << ", " << level << endl;
            for (int i=0; i<n; i++) {
                for (int j=0; j<m; j++) {
                    cout << visited[i][j][state] << " ";
                }
                cout << " | ";
                for (int j=0; j<m; j++) {
                    cout << matrix[i][j][state] << " ";
                }
                cout << endl;
            }*/

            if (x == n-1 && y == m-1) {
                target = level;
                break;
            }

            int nexts = (state+1)%states;
            for (int i=0; i<5; i++) {
                int nx = xadd[i]+x,
                    ny = yadd[i]+y;
                if (nx>=0 && nx<n &&
                       ny>=0 && ny<m &&
                       matrix[nx][ny][nexts] == 0 &&
                       visited[nx][ny][nexts] != 1) {
                    data temp;
                    temp.x = nx; temp.y = ny; temp.state = nexts;
                    temp.level = level+1;
                    Q.push(temp);
                    visited[nx][ny][nexts] = 1;
                }
            }
        }

        if (target == -1)
            cout << "Case " << cs << ": Luke and Leia cannot escape." << endl;
        else
            cout << "Case " << cs << ": Luke and Leia can escape in " << target << " steps." << endl;
        cs++;
    }

    return 0;
}
