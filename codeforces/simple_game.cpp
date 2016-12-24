#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    long long n, m; cin >> n >> m;
    long long numright = n-m,
              numleft = m-1;
    if (numright == 0 && numleft == 0) {
        cout << m << endl;
    } else if (numleft>=numright) {
        cout << m-1 << endl;
    } else {
        cout << m+1 << endl;
    }

    return 0;
}
