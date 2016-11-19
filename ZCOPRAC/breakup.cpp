#include <iostream>
#include <algorithm>
using namespace std;

bool palindromic(int array[], int start, int end) {
    if (start==end) return true;
    for (int i=0; i<=(end-start)/2; i++) {
        if (array[start+i]!=array[end-i]) {
            return false;
        }
    }
    return true;
}

int main() {
    int n;
    cin >> n;
    int array[n],
        dp[n];
    for (int i=0; i<n; i++) {
        cin >> array[i];
    }
    dp[0] = 1;
    for (int i=1; i<n; i++) {
        dp[i] = 100000;
        for (int j=0; j<=i; j++) {
            if (palindromic(array, j, i))
                dp[i] = min(dp[i], 1+(j-1<0?0:dp[j-1]));
        }
    }
    cout << dp[n-1] << endl;

    return 0;
}
