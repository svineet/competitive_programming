#include <iostream>
#include <algorithm>
using namespace std;

bool within_bounds(int i, int j, int sizex, int sizey) {
    if (0<=i && i<sizex && j>=0 && j<=sizey)
        return true;
    else
        return false;
}

void dfs(int matrix[10][10], int sizex,  int sizey,
                         int currow, int curcol,
                         int comp_marker,
                         int visited[10][10]) {
    if (visited[currow][curcol] != 0)
        // We've been here before
        return;

    visited[currow][curcol] = comp_marker;
    for (int i=-1; i<=1; i++) {
        for (int j=-1; j<=1; j++) {
            if (within_bounds(currow+i,
                              curcol+j,
                              sizex, sizey) &&
                    matrix[currow+i][curcol+j] == 1) {
                dfs(matrix, sizex, sizey,
                            currow+i, curcol+j,
                            comp_marker,
                            visited);
            }
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    int matrix[10][10];
    int visited[10][10];
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            cin >> matrix[i][j];
            visited[i][j] = 0;
        }
    }

    int component=1;
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if (visited[i][j] == 0 && matrix[i][j] == 1) {
                dfs(matrix, n, m,
                            i, j,
                            component,
                            visited);
                component++;
            }
        }
    }

    int comp_counts[component+1];
    for (int i=0; i<component+1; i++)
        comp_counts[i] = 0;
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if (visited[i][j] == 0) continue;
            comp_counts[visited[i][j]]++;
        }
    }
    cout << *max_element(comp_counts, comp_counts+component+1) << endl;

    return 0;
}
