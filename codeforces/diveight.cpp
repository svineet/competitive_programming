#include <bits/stdc++.h>
using namespace std;

int main() {
    string str; cin >> str;
    int n = str.length();

    bool ye = false;
    for (int i=0; i<=1000; i++) {
        if (i%8 == 0) {
            string f = to_string(i);
            int fptr = 0;
            for (int j=0; j<n; j++) {
                if (str[j] == f[fptr]) fptr++;
            }

            int len = f.length();
            if (fptr == len) {
                cout << "YES" << endl << f << endl;
                ye = true;
                break;
            }
        }
    }
    
    if (!ye)
        cout << "NO" << endl;

    return 0;
}
