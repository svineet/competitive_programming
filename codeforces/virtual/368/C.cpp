#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n; cin >> n;
    if (n==1 || n==2) {
        cout << -1 << endl;
        return 0;
    }

    if (n%2==1) {
        // Find x and x+1 such that
        // x+1 squared is hypotenuse
        // and x square a side and n
        // the other side.
        long long sqr = n*n;
        long long x = (sqr-1)/2;
        cout << x << " " << x+1 << endl;
    } else {
        long long sqr = n*n;
        long long x = sqr/4 - 1;
        cout << x << " " << x+2 << endl;
    }
}
