#include <bits/stdc++.h>
using namespace std;

void print(list<int> l) {
    for (list<int>::iterator i = l.begin();
         i!=l.end();
         i++) {
        cout << *i << " ";
    }
    cout << endl;
}

int main() {
    list<int> l;
    for (int i=0; i<5; i++) {
        l.push_back(i+1);
    }

    print(l);
    list<int>::iterator iter = l.begin();
    l.insert(iter, 10);

    return 0;
}
