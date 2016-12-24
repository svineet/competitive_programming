#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int c, f; cin >> c >> f;
    long long adjmatrix[c][c]; 
    for (int i=0; i<c; i++) {
        for (int j=0; j<c; j++) {
            if (i==j)
                adjmatrix[i][j] = 0;
            else
                adjmatrix[i][j] = 1e18;
        }
    }

    for (int i=0; i<f; i++) {
        int x, y; cin >> x >> y;
        x--; y--;
        long long p; cin >> p;
        adjmatrix[x][y] = adjmatrix[y][x] = p;
    }

    for (int k=0; k<c; k++) {
        for (int i=0; i<c; i++) {
            for (int j=0; j<c; j++) {
                if (adjmatrix[i][k]+adjmatrix[k][j]<adjmatrix[i][j])
                    adjmatrix[i][j] = adjmatrix[i][k]+adjmatrix[k][j];
            }
        }
    }

    long long best = 0;
    for (int i=0; i<c; i++) {
        for (int j=0; j<c; j++) {
            best = max(best, adjmatrix[i][j]);
        }
    }

    cout << best << endl;

    return 0;
}
