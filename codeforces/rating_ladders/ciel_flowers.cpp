#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b, c; cin >> a >> b >> c;
    int ans = 0;
    for (int i=0; i<3; i++) {
        if (min({a, b, c})-i >= 0) {
            ans = max(ans, (a-i)/3 + (b-i)/3 + (c-i)/3 + i);
        }
    }
    cout << ans << endl;

    return 0;
}
