#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main() {
    int ascii[256] = {0};
    string inp; cin >> inp;
    int n = inp.length();
    char maxer = inp[0];
    for (int i=0; i<n; i++) {
        if (maxer < inp[i])
            maxer = inp[i];
        ascii[int(inp[i])]++;
    }
    for (int i=0; i<ascii[int(maxer)];  i++) {
        cout << maxer;
    }
    cout << endl;

    return 0;
}
