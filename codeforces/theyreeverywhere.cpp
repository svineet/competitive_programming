#include <bits/stdc++.h>
using namespace std;

int ascii[257];
int current[257];

int main() {
    int n; cin >> n;
    string str; cin >> str;
    for (int i=0; i<n; i++) {
        ascii[(int)str[i]]++;
    }

    int lptr = 0, rptr = 0;
    current[(int)str[0]]++;
    int best = 1e9;
    while (rptr<n) {
        if (lptr>rptr) {
            rptr++;
            if (rptr==n) break;
            current[(int)str[rptr]]++;
        }

        bool satisfied = true;
        for (int i='a'; i<='z'; i++) {
            if (ascii[i] && !current[i]) {
                satisfied = false;
                break;
            }
        }
        for (int i='A'; i<='Z'; i++) {
            if (ascii[i] && !current[i]) {
                satisfied = false;
                break;
            }
        }

        if (satisfied) {
            best = min(best, rptr-lptr+1);
            current[(int)str[lptr]]--; lptr++;
        } else {
            rptr++;
            if (rptr==n) break;
            current[(int)str[rptr]]++;
        }
    }
    cout << best << endl;

    return 0;
}
