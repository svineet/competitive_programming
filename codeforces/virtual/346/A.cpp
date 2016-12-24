#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, a, b; cin >> n >> a >> b;
    int x = a;
    if (b<0) {
        while (b<0) {
            x--;
            if (x==0) x = n;
            b++;
        }
    } else {
        while (b>0) {
            x++;
            if (x>n) x = 1;
            b--;
        }
    }
    cout << x << endl;
    return 0;
}
