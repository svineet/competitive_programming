#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    int n; cin >> n;
    int matrix[n][n];
    long long minordiag[2*n] = {0};
    long long majordiag[2*n] = {0};
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            cin >> matrix[i][j];
            minordiag[i+j] += matrix[i][j];
            majordiag[i-j+n] += matrix[i][j];
            // Major diagonals wrap
        }
    }

    /*for (int i=0; i<2*n; i++) {
        cout << minordiag[i] << " " << majordiag[i] << endl;
    }*/

    int sx, sy;
    int fx, fy;
    long long maxim = -1337000;
    long long maxim2 = -1337000;
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            if ((i+j)%2==0) {
                if (minordiag[i+j]+majordiag[i-j+n]-matrix[i][j]>maxim) {
                    maxim = minordiag[i+j]+majordiag[i-j+n]-matrix[i][j];
                    sx = i; sy = j;
                }
            } else {
                if (minordiag[i+j]+majordiag[i-j+n]-matrix[i][j]>maxim2) {
                    maxim2 = minordiag[i+j]+majordiag[i-j+n]-matrix[i][j];
                    fx = i; fy = j;
                }
            }
        }
    }

    cout << maxim+maxim2 << endl;
    cout << sx+1 << " " << sy+1 << " " << fx+1 << " " << fy+1 << endl;


    return 0;
}
