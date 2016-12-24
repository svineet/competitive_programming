#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b, c; cin >> a >> b >> c;
    int comps = 0;
    while (a>=1 && b>=2 && c>=4) {
        comps+=7;
        a--; b-=2; c-=4;
    }
    cout << comps << endl;

    return 0;
}
