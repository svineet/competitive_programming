#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, c; cin >> n >> c;
    int array[n];
    for (int i=0; i<n; i++) {
        cin >> array[i];
    }

    int streak = 1;
    for (int i=1; i<n; i++) {
        if (array[i]-array[i-1]<=c)
            streak++;
        else
            streak = 1;
    }
    cout << streak << endl;

    return 0;
}
