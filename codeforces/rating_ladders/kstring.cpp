#include <bits/stdc++.h>
using namespace std;

int main() {
    int k; cin >> k;
    string str; cin >> str;
    int n = str.length();

    int ascii[256];
    fill (ascii, ascii+256, 0);

    for (int i=0; i<n; i++) {
        ascii[int(str[i])]++;
    }

    string elem = "";
    for (int i='a'; i<='z'; i++) {
        if (ascii[i]%k != 0) {
            cout << -1 << endl;
            return 0;
        } else {
            for (int j=0; j<(ascii[i]/k); j++)
                elem += char(i);
        }
    }

    for (int i=0; i<k; i++)
        cout << elem;
    cout << endl;

    return 0;
}
