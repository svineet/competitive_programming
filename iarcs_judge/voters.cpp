#include <bits/stdc++.h>
using namespace std;

int main() {
    int n1, n2, n3;
    cin >> n1 >> n2 >> n3;
    map<int, int> mp;

    for (int i=0; i<n1+n2+n3; i++) {
        int a; cin >> a;
        mp[a]++;
    }

    map<int, int>::iterator iter;
    vector<int> result;
    result.reserve(n1+n2+n3);
    for (iter = mp.begin(); iter != mp.end(); iter++) {
        if (iter->second>=2) result.push_back(iter->first);
    }

    int len = result.size();
    cout << len << endl;
    for (int i=0; i<len; i++) {
        cout << result[i] << endl;
    }

    return 0;
}
