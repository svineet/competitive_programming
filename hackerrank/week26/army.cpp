#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m; cin >> n >> m;
    if (n==1 && m==1) {
        cout << 1 << endl;
    } else if ((n==1 && m!=1) || (n!=1 && m==1)) {
        cout << (n*m)/2+(n*m)%2 << endl;
    } else {
        long long c = (n*m)/4;
        long long x = (n*m)%4;
        c += x/2 + x%2;
        cout << c << endl;
    }
}
