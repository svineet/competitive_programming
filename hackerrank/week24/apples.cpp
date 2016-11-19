#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    std::ios::sync_with_stdio(0);

    int s, t;
    cin >> s >> t;
    int a, b;
    cin >> a >> b;
    int m, n;
    cin >> m >> n;

    int apples = 0, oranges = 0;
    for (int i=0; i<m; i++) {
        int temp;
        cin >> temp;
        if (a+temp>=s && a+temp<=t)
            apples++;
    }
    for (int i=0; i<n; i++) {
        int temp;
        cin >> temp;
        if (b+temp>=s && b+temp<=t)
            oranges++;
    }
    cout << apples << endl << oranges << endl;

    return 0;
}
