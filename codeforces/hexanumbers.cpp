#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main() {
    string n; cin >> n;
    int len = n.length();
    long long res = 0;
    bool changed = false;
    for (int i=0; i<len; i++) {
        if (changed || n[i]-'0'==1) {
            res += (1<<(len-i-1));
        }
        else if (n[i]-'0'>1) {
            res += (1<<(len-i-1));
            changed = true;
        }
    }
    cout << res << endl;

    return 0;
}
