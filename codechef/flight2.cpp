#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    int arr[n];
    for (int i=0; i<n; i++)
        cin >> arr[i];

    int maxc = 0;
    for (double h=0.5; h<=1000; h+=1) {
        int cross = 0;
        for (int i=0; i<n-1; i++) {
            int a = min(arr[i], arr[i+1]);
            int b = max(arr[i], arr[i+1]);
            if (a<=h && h<=b) {
                cross++;
            }
        }
        maxc = max(maxc, cross);
    }
    cout << maxc << endl;

    return 0;
}
