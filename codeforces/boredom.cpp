#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n; cin >> n;
    int array[n];
    long long dp[n];
    long long maxtill[n];
    for (int i=0; i<n; i++) {
        cin >> array[i];
        dp[i] = maxtill[i] = 0;
    }
    sort(array, array+n);

    dp[0] = array[0];
    maxtill[0] = array[0];
    for (int i=1; i<n; i++) {
        int ak = array[i];
        // Try to delete ak
        if (array[i-1] == array[i]) {
            dp[i] = ak+dp[i-1];
        } else {
            int index = lower_bound(array, array+i, ak-1)-array;
            //cout << "At: " << i << ", found: " << index << endl;
            if (index-1>=0) {
                dp[i] = ak+maxtill[index-1];
            } else {
                dp[i] = ak;
            }
        }
        maxtill[i] = max(maxtill[i-1], dp[i]);
    }

    /*for (int i=0; i<n; i++)
        cout << dp[i] << " ";
    cout << endl;*/

    cout << maxtill[n-1] << endl;

    return 0;
}
