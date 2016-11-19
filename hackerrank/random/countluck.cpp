#include <iostream>
#include <queue>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    int t;
    cin >> t;
    for (int cs=0; cs<t; cs++) {
        int n, m;
        cin >> n >> m;

        char matrix[n][m]; int levels[n][m];
        pair<int, int> starter, ender;
        for (int i=0; i<n; i++) {
            string temp;
            cin >> temp;
            for (int j=0; j<m; j++) {
                matrix[i][j] = temp[j];
                levels[i][j] = -1;
                if (temp[j] == 'M') {
                    starter = make_pair(i, j);
                }
                else if (temp[j] == '*') {
                    ender = make_pair(i, j);
                }
            }
        }
        int predicted;
        cin >> predicted;
    }

    return 0;
}
