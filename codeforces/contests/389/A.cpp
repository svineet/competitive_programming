#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m, k; cin >> n >> m >> k;

    cout << ((k-1)/(2*m))+1 << " " << ((k-1)/2)%m+1 << " ";
    if (k%2==0)
        cout << "R" << endl;
    else
        cout << "L" << endl;

    return 0;
}
