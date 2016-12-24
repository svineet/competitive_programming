#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    pair<int, int> array[n];
    for (int i=0; i<n; i++) {
        cin >> array[i].first;
        array[i].second = i+1;
    }
    sort (array, array+n);

    cout << ceil(n/2.0) << endl;
    for (int i=0; i<n; i+=2) {
        cout << array[i].second << " ";
    }
    cout << endl;

    cout << n/2 << endl;
    for (int i=1; i<n; i+=2) {
        cout << array[i].second << " ";
    }
    cout << endl;

    return 0;
}
