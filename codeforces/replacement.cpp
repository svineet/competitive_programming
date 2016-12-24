#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    int array[n];
    bool allones = true;
    for (int i=0; i<n; i++) {
        cin >> array[i];
        if (array[i] != 1) allones = false;
    }
    sort (array, array+n);

    if (allones) {
        for (int i=0; i<n-1; i++)
            cout << "1 ";
        cout << "2" << endl;
        return 0;
    }

    cout << "1 ";
    for (int i=0; i<n-1; i++) {
        cout << array[i] << " ";
    }
    cout << endl;

    return 0;
}
