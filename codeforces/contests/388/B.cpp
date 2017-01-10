#include <bits/stdc++.h>
using namespace std;

int main() {
    pair<int, int> a, b, c;
    cin >> a.first >> a.second;
    cin >> b.first >> b.second;
    cin >> c.first >> c.second;

    set< pair<int, int> > ds;
    ds.insert(make_pair(a.first+b.first-c.first,
                        a.second+b.second-c.second));
    ds.insert(make_pair(-a.first+b.first+c.first,
                        -a.second+b.second+c.second));
    ds.insert(make_pair(a.first-b.first+c.first,
                        a.second-b.second+c.second));
    cout << ds.size() << endl;
    for (set< pair<int, int> >::iterator iter = ds.begin();
         iter != ds.end();
         iter++) {
        cout << iter->first << " " << iter->second << endl;
    }


    return 0;
}
