#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    int k; cin >> k;
    string str; cin >> str;

    int changed = 0;
    if (n >= 2 && str[0] == str[1]) {
        str[0] = 'A'+((str[1]-'A')+1)%k;
        changed++;
    }

    for (int i=1; i<n; i++) {
        if (str[i] == str[i-1]) {
            for (char c='A'; c<'A'+k; c++) {
                if (c != str[i] && c != str[i-1]) {
                    if (i<n-1 && c != str[i+1]) {
                        str[i] = c;
                    } else if (i == n-1) {
                        str[i] = c;
                    }
                }
            }

            changed++;
        }
    }

    cout << changed << endl;
    cout << str << endl;

    return 0;
}
