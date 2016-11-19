#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n, m; cin >> n >> m;
    int times = 0;
    while (true) {
        if (n-1>=0 && m-2>=0 && m>=n) {
            n-=1; m-=2; times++;
        } else if (n-2>=0 && m-1>=0 && n>m) {
            n-=2; m-=1; times++;
        } else {
            break;
        }
    }
    cout << times << endl;

    return 0;
}
