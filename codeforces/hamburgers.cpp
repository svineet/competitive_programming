#include <bits/stdc++.h>
using namespace std;

int main() {
    string str; cin >> str;
    int lenxd = str.length();
    int rb=0, rs=0, rc=0;
    for (int i=0; i<lenxd; i++) {
        if (str[i] == 'B') rb++;
        if (str[i] == 'S') rs++;
        if (str[i] == 'C') rc++;
    }

    long long hb, hs, hc;
    cin >> hb >> hs >> hc;
    int pb, ps, pc;
    cin >> pb >> ps >> pc;
    long long rubs; cin >> rubs;

    long long left = 0,
              right = 1e13;
    long long cost = 0;
    long long best = 0;
    while (left<=right) {
        long long mid = (left+right)/2;
        // Let's say we bought mid
        // hamburgers.
        cost = pb*(max(0ll, rb*mid-hb));
        cost += ps*(max(0ll, rs*mid-hs));
        cost += pc*(max(0ll, rc*mid-hc));
        if (cost>rubs) {
            // We need to take less hamburgers
            right = mid-1;
        } else if (cost == rubs) {
            left = right = best = mid;
            break;
        } else if (cost<rubs) {
            best = max(best, mid);
            left = mid+1;
        }
    }
    cout << best << endl;

    return 0;
}
