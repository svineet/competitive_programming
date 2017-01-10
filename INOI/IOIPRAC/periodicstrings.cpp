#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m; cin >> n >> m;

    long long mult = 4;
    long long count = 2;
    for (int i=2; i<n; i++) {
        if (n%i==0) {
            count += mult-2+m;
            count %= m;
        }
        mult *= 2; mult %= m;
    }
    cout << (mult-count+m)%m << endl;

    return 0;
}
