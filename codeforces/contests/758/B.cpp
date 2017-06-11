#include <bits/stdc++.h>
using namespace std;

int chtonum[256];

int main() {
    chtonum['R'] = 0;
    chtonum['B'] = 1;
    chtonum['Y'] = 2;
    chtonum['G'] = 3;

    string str; cin >> str;
    int n = str.length();
    int cnts[4] = {0};
    for (int i=0; i<n; i+=4) {
        if (i+4>n) break;

        bool pres[4] = {false};
        for (int j=i; j<i+4; j++) {
            if (str[j] != '!') pres[chtonum[int(str[j])]] = true;
        }

        for (int j=0; j<4; j++) {
            if (!pres[j]) {
                cnts[j]++;
            }
        }
    }

    for (int i=n-n%4; i<n; i++) {
        if (str[i] == '!') {
        }
    }

    for (int i=0; i<4; i++)
        cout << cnts[i] << " ";
    cout << endl;

    return 0;
}
