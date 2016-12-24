#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;

    if (n%2==0) {
        int times = n/2;
        cout << times << endl;
        for (int i=0; i<times; i++) {
            cout << 2 << " ";
        }
        cout << endl;
    } else {
        n-=3;
        int times = n/2;
        cout << times+1 << endl;
        cout << 3 << " ";
        for (int i=0; i<times; i++) {
            cout << 2 << " ";
        }
        cout << endl;
    }

    return 0;
}
