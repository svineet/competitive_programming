#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m; cin >> n >> m;
    bool fukt = false;
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            string x; cin >> x;
            if (x != "W" && x != "B" && x != "G")
                fukt = true;
        }
    }
    if (!fukt)
        cout << "#Black&White" << endl;
    else
        cout << "#Color" << endl;

    return 0;
}
