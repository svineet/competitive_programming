#include <bits/stdc++.h>
using namespace std;

int main() {
    map<int, int> know;
    // know[i] = how many people
    // know language i.
    int n; cin >> n;
    for (int i=0; i<n; i++) {
        int a; cin >> a;
        know[a]++;
    }

    int m; cin >> m;
    int A[m], B[m];
    for (int i=0; i<m; i++) {
        cin >> A[i];
    }
    for (int i=0; i<m; i++) {
        cin >> B[i];
    }

    pair<int, int> best = make_pair(0, 0);
    int dex = -1;
    for (int i=0; i<m; i++) {
        int fir = know[A[i]],
            sec = know[B[i]];
        if (make_pair(fir, sec)>best) {
            best = make_pair(fir, sec);
            dex = i;
        }
    }
    cout << dex+1 << endl;
}
