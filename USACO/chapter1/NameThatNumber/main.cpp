/*
ID: saivine1
PROG: namenum
LANG: C++11
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("namenum.in", "r", stdin);
    freopen("namenum.out", "w", stdout);
    string str; cin >> str;
    int n = str.length();

    freopen("dict.txt", "r", stdin);
    vector<string> dict;
    dict.reserve(5000);
    string curstr;
    while (cin >> curstr) dict.push_back(curstr);

    int hits = 0;
    int len = dict.size();
    for (int i=0; i<len; i++) {
        if (dict[i].length() == str.length()) {
            bool okay = true;
            for (int j=0; j<n; j++) {
                bool found = false;
                switch(str[j]) {
                    case '2':
                        if (dict[i][j] == 'A' ||
                            dict[i][j] == 'B' ||
                            dict[i][j] == 'C') found = true;
                        break;
                    case '3':
                        if (dict[i][j] == 'D' ||
                            dict[i][j] == 'E' ||
                            dict[i][j] == 'F') found = true;
                        break;
                    case '4':
                        if (dict[i][j] == 'G' ||
                            dict[i][j] == 'H' ||
                            dict[i][j] == 'I') found = true;
                        break;
                    case '5':
                        if (dict[i][j] == 'J' ||
                            dict[i][j] == 'K' ||
                            dict[i][j] == 'L') found = true;
                        break;
                    case '6':
                        if (dict[i][j] == 'M' ||
                            dict[i][j] == 'N' ||
                            dict[i][j] == 'O') found = true;
                        break;
                    case '7':
                        if (dict[i][j] == 'P' ||
                            dict[i][j] == 'R' ||
                            dict[i][j] == 'S') found = true;
                        break;
                    case '8':
                        if (dict[i][j] == 'T' ||
                            dict[i][j] == 'U' ||
                            dict[i][j] == 'V') found = true;
                        break;
                    case '9':
                        if (dict[i][j] == 'W' ||
                            dict[i][j] == 'X' ||
                            dict[i][j] == 'Y') found = true;
                        break;

                    default: found = false;
                }

                okay = found;
                if (!okay) {
                    break;
                }
            }

            if (okay) {
                cout << dict[i] << endl;
                hits++;
            }
        }
    }
     
    if (hits == 0) cout << "NONE" << endl;

    return 0;
}
