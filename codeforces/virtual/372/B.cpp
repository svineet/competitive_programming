#include <bits/stdc++.h>
using namespace std;

bool ascii[256];

int main() {
    ios::sync_with_stdio(false);
    string str; cin >> str;
    int n = str.length();
    if (n<26) {
        cout << -1 << endl;
        return 0;
    }

    bool gotem = false;
    for (int i=0; i<n-25; i++) {
        for (int j='A'; j<='Z'; j++) ascii[j] = false;
        // Clear last iteration things

        int qs = 0;
        for (int j=i; j<i+26; j++) {
            if (str[j] == '?')
                qs++;
            else
                ascii[int(str[j])] = true;
        }

        int missing = 0;
        for (int j='A'; j<='Z'; j++) {
            if (!ascii[int(j)])
                missing++;
        }

        if (missing == qs) {
            // Filling can be done.
            // We are in luck.
            int qhole = i;
            for (int j='A'; j<='Z'; j++) {
                if (!ascii[int(j)]) {
                    for (int k=qhole; k<i+26; k++) {
                        if (str[k] == '?') {
                            qhole = k; break;
                        }
                    }
                    str[qhole] = char(j);
                }
            }
            gotem = true;
            break;
        }
    }

    if (gotem) {
        for (int i=0; i<n; i++) {
            if (str[i] == '?') cout << 'A';
            else               cout << str[i];
        }
        cout << endl;
    } else {
        cout << -1 << endl;
    }

    return 0;
}
