#include <bits/stdc++.h>
using namespace std;

int matrix[1000+10][1000+10];
int ones[1000+10];

struct order {
    int t; int a, b;
};

int main() {
    int n, m, q; cin >> n >> m >> q;
    bool inverted[n+1];
    order deez[q];
    bool showtime[q];
    for (int i=0; i<q; i++) {
        cin >> deez[i].t;
        int type = deez[i].t;
        if (type == 1 || type == 2) {
            cin >> deez[i].a >> deez[i].b;
        } else if (type == 3) {
            cin >> deez[i].a;
        } else if (type == 4) {
            cin >> deez[i].a;
        }
    }

    for (int i=0; i<q; i++) {
        if (deez[i].t == 1 || deez[i].t == 2) {
            int t = deez[i].t;
            int a = deez[i].a,
                b = deez[i].b;
            if (t == 1 && inverted[a]) {
                if (matrix[a][b] != 0) ones[a]++;
                matrix[a][b] = 0;
                // 0 represents presence in
                // inverted matrix
            } else if (t == 1 && !inverted[a]) {
                if (matrix[a][b] != 1) ones[a]--;
                matrix[a][b] = 1;
            } else if (t == 2 && inverted[a]) {
                if (matrix[a][b] != 1) ones[a]--;
                matrix[a][b] = 1;
            } else {
                if (matrix[a][b] != 0) ones[a]++;
                matrix[a][b] = 0;
            }
        } else if (deez[i].t == 3) {
            int a = deez[i].a,
                b = deez[i].b;
            ones[a] = b-ones[a];
            inverted[a] = !inverted[a];
        }

        if (showtime[i]) {
            for (int j=1; j<=n; j++) {
                cout << ones[j] << endl;
            }
        }
    }

    return 0;
}
