#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n, m; cin >> n >> m;
    int x, y;
    int ax, ay;
    x=0; y=m;
    ax=1; ay=-1;

    cout << min(m, n)+1 << endl;
    for (int i=0; i<=min(m, n); i++) {
        cout << x << " " << y << endl;
        x+=ax; y+=ay;
    }

    return 0;
}
