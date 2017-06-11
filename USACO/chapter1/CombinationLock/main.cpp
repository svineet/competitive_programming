/*
ID: saivine1
PROG: combo
LANG: C++11
*/
#include <bits/stdc++.h>
using namespace std;

int n; 
int get_cost(int a, int fj) {
    int b1 = max(a, fj),
        b2 = min(a, fj);
    a = b2; fj = b1;
    return min(abs(fj-a), a+n-fj);
}

bool correct(int a, int b, int c,
             int fj[3]) {

    return (get_cost(a, fj[0]) <= 2 &&
            get_cost(b, fj[1]) <= 2 &&
            get_cost(c, fj[2]) <= 2);
}

int main() {
    freopen("combo.in", "r", stdin);
    freopen("combo.out", "w", stdout);

    cin >> n;
    int fj[3],
        ml[3];
    for (int i=0; i<3; i++)
        cin >> fj[i];
    for (int i=0; i<3; i++)
        cin >> ml[i];

    int cnt = 0;
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            for (int k=1; k<=n; k++) {
                if (correct(i, j, k, fj) ||
                    correct(i, j, k, ml)) {
                    cnt++;
                }
            }
        }
    }
    cout << cnt << endl;

    return 0;
}
