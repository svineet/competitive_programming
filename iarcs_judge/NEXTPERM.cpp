#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    for (int cs=0; cs<k; cs++) {
        int array[n];
        for (int i=0; i<n; i++) {
            cin >> array[i];
        }

        next_permutation(array, array+n);
        for (int i=0; i<n; i++) {
            cout << array[i];
            if (i==n-1)
                cout << endl;
            else
                cout << " ";
        }
    }

    return 0;
}
