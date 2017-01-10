#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, p; cin >> n >> p;
    string str; cin >> str;

    int i = n-1;
    str[i]++;
    while (i>=0 && i<n) {
        if (str[i]-'a' >= p) {
            str[i] = 'a'; i--;
            if (i>=0) str[i]++;
        } else if ((i>=1 && str[i-1]==str[i]) || (i>=2 && str[i-2]==str[i])) {
            str[i]++;
        } else {
            i++;
        }
    }
    
    if (i<0)
        cout << "NO" << endl;
    else
        cout << str << endl;
 
    return 0;
}
