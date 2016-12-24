#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    string str; cin >> str;
    transform(str.begin(), str.end(), str.begin(), ::tolower);

    bool ascii[500] = {false};
    for (int i=0; i<n; i++) {
        ascii[int(str[i])] = true;
    }

    bool yas = true;
    for (int i='a'; i<='z'; i++) {
        if (!ascii[i]) {
            yas = false;
            break;
        }
    }

    if (yas)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;

    return 0;
}
