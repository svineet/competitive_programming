#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k; cin >> n >> k;
    for (int i=n; i>=n-k+1; i--)
        cout << i << " ";
    for (int i=1; i<=n-k; i++)
        cout << i << " ";
    cout << endl;

    return 0;
}
