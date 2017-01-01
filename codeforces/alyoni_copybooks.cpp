#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n, a, b, c;
    cin >> n >> a >> b >> c;

    if (n%4 == 0) {
        cout << 0 << endl;
        return 0;
    }

    long long left = ((n - n%4)/4 + 1)*4 - n;
    if (left == 3) {
        cout << min({c, 3*a, a+b}) << endl;
    } else if (left == 2) {
        cout << min({b, 2*b, 2*a, 2*c}) << endl;
    } else if (left == 1) {
        cout << min({a, b+c, 3*c}) << endl;
    }

    return 0;
}
