#include <bits/stdc++.h>
using namespace std;

map<int, long long> M;

int main() {
    int n; cin >> n;
    int array[n];
    for (int i=0; i<n; i++) {
        cin >> array[i];
        M[array[i]]++;
    }

    map<int, long long>::iterator iter, iter2;
    long long count = 0;
    for (iter = M.begin();
         iter != M.end();
         iter++) {
        if (iter->first == 0) {
            count += ((iter->second)*(iter->second-1))/2;
            // nC2 for zeroes
            continue;
        }

        iter2 = M.find(-(iter->first));
        if (iter2 != M.end()) {
            count += (iter2->second)*(iter->second);
        }
        iter2->second = 0; iter->second = 0;
    }
    cout << count << endl;

    return 0;
}
