#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m; cin >> n >> m;
    long long cost = 0;
    int curhouse = 1;
    for (int i=0; i<m; i++) {
        int a; cin >> a;
        if (a > curhouse) {
            cost += a-curhouse;
        } else if (a < curhouse) {
            cost += n+a-curhouse;
        }
        curhouse = a;
    }
    cout << cost << endl;

    return 0;
}
