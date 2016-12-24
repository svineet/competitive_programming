#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    int l=1, r=n*n;
    while (l<r) {
        cout << l << " " << r << endl;
        l++; r--;
    }

    return 0;
}
