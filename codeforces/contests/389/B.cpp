#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    string str1, str2;
    cin >> str1 >> str2;
    n = str1.length();
    set< pair<char, char> > misses;
    bool fukt = false;
    for (int i=0; i<n; i++) {
        if (str1[i] != str2[i]) {
            char a = str1[i],
                 b = str2[i];
            for (int j=0; j<n && !fukt; j++) {
                if (str1[j] == a || str2[j] == a || str1[j] == b || str2[j] == b) {
                    if (!((str1[j] == a && str2[j] == b) || (str1[j] == b && str2[j] == a))) {
                        //cout << i << " " << j << endl;
                        fukt = true; break;
                    }
                }
            }

            if (fukt) {
                break;
            } else {
                misses.insert(make_pair(min(a, b), max(a, b)));
            }
        }
    }

    if (fukt) {
        cout << "-1" << endl;
        return 0;
    }

    int len = misses.size();
    cout << len << endl;
    for (auto i=misses.begin(); i != misses.end(); i++)
        cout << i->first << " " << i->second << endl;
}
