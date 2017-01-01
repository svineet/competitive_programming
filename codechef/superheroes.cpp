#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        int vil = 1, sup = 1;
        bool done = false;
        for (int i=0; i<n; i++) {
            string str; cin >> str;
            if (done) continue;
            int len = str.length();
            if (len >=3 && str[len-1] == 'n' &&
                           str[len-2] == 'a' &&
                           str[len-3] == 'm') {
                sup++;
            } else if (len >=5 && str[len-1] == 'n' &&
                                  str[len-2] == 'a' &&
                                  str[len-3] == 'm' &&
                                  str[len-4] == 'o' &&
                                  str[len-5] == 'w') {
                sup++;
            } else {
                vil++;
            }
            if (sup-2 == vil) {
                cout << "superheroes" << endl;
                done = true;
            } else if (vil-3 == sup) {
                cout << "villains" << endl;
                done = true;
            }
        }

        if (!done) cout << "draw" << endl;
    }

    return 0;
}
