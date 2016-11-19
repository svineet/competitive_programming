#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int t;
    cin >> t;
    for (int cs=0; cs<t; cs++) {
        int n; cin >> n;
        int array[n];
        for (int i=0; i<n; i++) {
            cin >> array[i];
        }
        sort(array, array+n);
        bool rekt = false;
        for (int i=0; i<n-1; i++) {
            if (abs(array[i+1]-array[i])>1) {
                rekt = true;
                break;
            }
        }
        cout << (rekt?"NO":"YES") << endl;
    }

    return 0;
}
