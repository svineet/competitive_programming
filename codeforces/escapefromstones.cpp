#include <bits/stdc++.h>
using namespace std;

int main() {
    string str; cin >> str;
    int n = str.length();

    list<int> result;
    list<int>::iterator iter = result.begin();
    result.push_back(1);
    for (int i=0; i<n-1; i++) {
        if (str[i] == 'l') {
            iter--;
            result.insert(iter, i+2);
        } else if (str[i] == 'r') {
            result.insert(iter, i+2);
        }
    }

    for (iter = result.begin();
         iter != result.end();
         iter++) {
        cout << *iter << " ";
    }
    cout << endl;

    return 0;
}
