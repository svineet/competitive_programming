/*
ID: saivine1
PROG: transform
LANG: C++11
*/
#include <bits/stdc++.h>
using namespace std;

int n;
char mato[100][100],
     matf[100][100];

bool mat_equal() {
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            if (mato[i][j] != matf[i][j])
                return false;
        }
    }
    return true;
}

void reflect() {
    for (int i=0; i<n; i++) {
        for (int j=0; j<n/2; j++) {
            swap(mato[i][j], mato[i][n-j-1]);
        }
    }
}

void rotate90() {
    char matprev[100][100];
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            matprev[i][j] = mato[i][j];
        }
    }

    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            mato[j][i] = matprev[i][j];
        }
    }
    reflect();
    // Where does the (i, j) element
    // go in the new matrix?
    // Transpose and reflect produces
    // 90 deg rotation.
}

void print_mat() {
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) cout << mato[i][j];
        cout << endl;
    }
}

int main() {
    freopen("transform.in", "r", stdin);
    freopen("transform.out", "w", stdout);

    cin >> n;
    for (int i=0; i<n; i++) {
        string str; cin >> str;
        for (int j=0; j<n; j++) {
            mato[i][j] = str[j];
        }
    }
    for (int i=0; i<n; i++) {
        string str; cin >> str;
        for (int j=0; j<n; j++) {
            matf[i][j] = str[j];
        }
    }

    rotate90();
    if (mat_equal()) {
        cout << 1 << endl;
    } else {
        rotate90();
        if (mat_equal()) {
            cout << 2 << endl;
        } else {
            rotate90();
            if (mat_equal()) {
                cout << 3 << endl;
            } else {
                rotate90();
                reflect();
                if (mat_equal()) {
                    cout << 4 << endl;
                } else {
                    bool ye = false;
                    rotate90();
                    ye = ye|mat_equal();
                    rotate90();
                    ye = ye|mat_equal();
                    rotate90();
                    ye = ye|mat_equal();
                    if (ye) {
                        cout << 5 << endl;
                    } else {
                        rotate90(); reflect();
                        if (mat_equal()) {
                            cout << 6 << endl;
                        } else {
                            cout << 7 << endl;
                        }
                    }
                }
            }
        }
    }

    return 0;
}
