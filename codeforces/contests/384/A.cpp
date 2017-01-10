#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, a, b; cin >> n >> a >> b;
    string str; cin >> str;
    a--; b--;
    if (a == b || str[a] == str[b]) {
        cout << 0 << endl;
    } else {
        int a1 = a,
            a2 = b;
        int closesta2 = a2,
            closesta1 = a1;
        for (int i=0; i<n; i++) {
            if (abs(closesta2-a1)>abs(i-a1) && str[i] == str[a2])
                closesta2 = i;
            // Closest element to a1 akin to a2
            if (abs(closesta1-a2)>abs(i-a2) && str[i] == str[a1])
                closesta1 = i;
        }
        //cout << a1 << " " << a2 << endl;
        //cout << closesta1 << " " << closesta2 << endl;
        cout << min(abs(closesta2-a1), abs(closesta1-a2)) << endl;
    }
}
