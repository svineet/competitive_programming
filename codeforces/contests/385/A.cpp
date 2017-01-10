#include <bits/stdc++.h>
using namespace std;

int main() {
    string str; cin >> str;
    int n = str.length();
    set<string> S;
    for (int i=0; i<n; i++) {
        string lel; lel += str[i];
        int j = (i+1)%n;
        while (j != i) {
            lel += str[j];
            j++; j %= n;
        }
        S.insert(lel);
    }
    cout << S.size() << endl;

    return 0;
}
