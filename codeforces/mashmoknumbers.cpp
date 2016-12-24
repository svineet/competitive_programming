#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k; cin >> n >> k;

    if (n/2>k) {
        cout << -1 << endl;
        return 0;
    }

    if (k==0 && n==1) {
        cout << 1 << endl;
        return 0;
    }
    
    if (n==1 && k!=0) {
        cout << -1 << endl;
        return 0;
    }

    int need = k-(n-2)/2;
    // Need is the gcd we need to make numbers
    cout << need*2 << " " << need*3 << " ";
    n-=2; // Spit out two already.
    int print = need*3+1;
    while (n>0) {
        cout << print << " ";
        print++; n--;
    }
    cout << endl;

    return 0;
}
