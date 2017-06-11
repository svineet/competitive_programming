#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    long long arr[n]; long long arr1[n];
    for (int i=0; i<n; i++) {
        cin >> arr[i];
        arr1[i] = arr[i];
    }
    sort (arr1, arr1+n);

    long long carr[n]; carr[0] = arr[0];
    long long carr1[n]; carr1[0] = arr1[0];
    for (int i=1; i<n; i++) {
        carr[i] = arr[i]+carr[i-1];
        carr1[i] = arr1[i]+carr1[i-1];
    }

    int m; cin >> m;
    for (int i=0; i<m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        b--; c--;
        if (a == 1) {
            cout << carr[c]-(b>0?carr[b-1]:0) << endl;
        } else {
            cout << carr1[c]-(b>0?carr1[b-1]:0) << endl;
        }
    }

    return 0;
}
