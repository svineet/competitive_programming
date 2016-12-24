#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    string str; cin >> str;
    string result(1, str[n-1]);
    for (int i=n-2; i>=0; i--) {
        int len = result.length();
        result.insert(result.begin()+len/2, str[i]);
    }
    cout << result << endl;
}
