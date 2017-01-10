#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    int array[n] = {0};
    for (int i=0; i<(n-n%3); i+=3) {
        int x, y, z;
        int sm;
        cout << "? " << i+1 << " " << i+2 << endl;
        cin >> x;
        cout << "? " << i+1 << " " << i+3 << endl;
        cin >> y;
        cout << "? " << i+2 << " " << i+3 << endl;
        cin >> z;
        sm = (x+y+z)/2;
        array[i] = sm-z; array[i+1] = sm-y;
        array[i+2] = sm-x;
        //cout << array[i] << " " << array[i+1] << " " << array[i+2] << endl;
    }

    if (n%3) {
        int rem = n%3;
        if (rem >= 1) {
            cout << "? " << 1 << " " << n << endl;
            int x; cin >> x;
            array[n-1] = x-array[0];
        }
        if (rem == 2) {
            cout << "? " << 1 << " " << n-1 << endl;
            int x; cin >> x;
            array[n-2] = x-array[0];
        }
    }

    cout << "! ";
    for (int i=0; i<n; i++)
        cout << array[i] << " ";
    cout << endl;
}
