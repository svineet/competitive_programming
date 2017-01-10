#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    long long sum = 0; int mx = -1e8;
    for (int i=0; i<n; i++) {
        int temp; cin >> temp;
        sum += temp;
        mx = max(mx, temp);
    }
    
    sum = ceil(sum/double(n-1));
    if (mx>sum)
        cout << mx;
    else
        cout << sum;
    cout << endl;

    return 0;
}
