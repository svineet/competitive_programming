#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    int n; cin >> n;
    int array[n];
    int d = 0;
    for (int i=0; i<n; i++) {
        cin >> array[i];
    }
    sort (array, array+n);

    if (n==1) {
        cout << -1 << endl;
        return 0;
    } else if (n==2) {
        d = array[1]-array[0];
        if (d==0) {
            cout << 1 << endl;
            cout << array[0] << endl;
        } else if (d%2==0) {
            cout << 3 << endl;
            cout << array[0]-d << " " << array[0]+d/2 << " " << array[1]+d << endl;
        } else {
            cout << 2 << endl;
            cout << array[0]-d << " " << array[1]+d << endl;
        }

        return 0;
    }

    d = array[1]-array[0];

    for (int i=1; i<n-1; i++) {
        d = min(d, array[i+1]-array[i]);
    }

    int occ = 0;
    int fault = 0;
    for (int i=0; i<n-1; i++) {
        int dc = array[i+1]-array[i];
        if (dc==d)
            continue;

        if (d*2==dc) {
            // d remains, fault changes
            occ = i;
        } else {
            fault+=10;
        }
        fault++;
    }

    if (fault>1) {
        cout << 0 << endl;
        return 0;
    } else if (fault == 0) {
        if (d!=0) {
            cout << 2 << endl;
            cout << array[0]-d << " " << array[n-1]+d << endl;
        } else {
            cout << 1 << endl;
            cout << array[0] << endl;
        }
    } else {
        cout << 1 << endl;
        cout << array[occ]+d << endl;
    }

    return 0;
}
