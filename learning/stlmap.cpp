#include <bits/stdc++.h>
using namespace std;

void print_map(map<int, int> M) {
    map<int, int>::iterator iter = M.begin();
    for (iter = M.begin();
         iter!=M.end();
         iter++) {
        cout << iter->first << " ";
    }
    cout << endl;
}

int main() {
    map<int, int> M;
    for (int i=0; i<5; i++) {
        M[i] = i+1;
    }

    print_map(M);
    M.erase(M.find(2));
    print_map(M);

    return 0;
}
