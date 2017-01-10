#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k; cin >> n >> k;
    k--;
    int forward[n];
    int backward[n];
    int cost[n];
    for (int i=0; i<n; i++) {
        cin >> cost[i];
    }

    forward[k] = 0;
    for (int i=k+1; i<n; i++) {
        forward[i] = cost[i]+ max(forward[i-1],
                                  (i-2>=k?forward[i-2]:-(int)1e9));
    }
    backward[n-1] = 0;
    for (int i=n-2; i>=0; i--) {
        backward[i] = -1e9;
        if (i+1>=k && i+1<n) {
            backward[i] = cost[i]+forward[i+1];
        }
        if (i+2>=k && i+2<n) {
            backward[i] = max(backward[i],
                              cost[i]+forward[i+2]);
        }
        if (i+2<n) {
            backward[i] = max(backward[i],
                              cost[i]+backward[i+2]);
        }
        if (i+1<n) {
            backward[i] = max(backward[i],
                              cost[i]+backward[i+1]);
        }
    }

    cout << backward[0] << endl;
    return 0;
}
