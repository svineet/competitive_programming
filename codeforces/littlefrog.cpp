#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;

    int cur = 1;
    int inc = n-1;
    int iter = 0;
    bool parity = false;
    // false means add,
    // true means subtract
    while (iter<n) {
        cout << cur << " ";
        if (parity)
            cur -= inc;
        else
            cur += inc;
        inc--; parity = !parity;
        iter++;
    }
    cout << endl;

    return 0;
}
