#include <bits/stdc++.h>
using namespace std;

int n;
const int MOD = 42373;
long long adjmatrix[100][100];
long long destination[100][100], temp[100][100];

void MatrixMultiply(long long A[100][100],
                    long long B[100][100],
                    long long C[100][100]) {
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            C[i][j] = 0;
            for (int k=0; k<n; k++) {
                C[i][j] += A[i][k]*B[k][j];
                C[i][j] %= MOD;
            }
        }
    }
}

void MatrixExponentiate(int hops) {
    while (hops>0) {
        if (hops&1) {
            // If hops is odd, we need to do an additional
            // multiplication.
            MatrixMultiply(destination, adjmatrix, temp);
            for (int i=0; i<n; i++) {
                for (int j=0; j<n; j++) {
                    destination[i][j] = temp[i][j];
                }
            }
        }

        MatrixMultiply(adjmatrix, adjmatrix, temp);
        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                adjmatrix[i][j] = temp[i][j];
            }
        }

        hops /= 2;
    }

    return;
}

int main() {
    cin >> n;
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            cin >> adjmatrix[i][j];
        }
    }
    int source, target, hops;
    cin >> source >> target >> hops;
    source--; target--;

    for (int i=0; i<n; i++) {
        destination[i][i] = 1;
        // Initialize destination to identity matrix
    }

    MatrixExponentiate(hops);
    cout << destination[source][target] << endl;

    return 0;
}
