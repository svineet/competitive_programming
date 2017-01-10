#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    int array[n];
    long long partials[n];
    for (int i=0; i<n; i++) {
        cin >> array[i];
        partials[i] = (i>0?partials[i-1]:0)+
                      array[i];
    }

    int count = 0;
    for (int i=0; i<n-1; i++) {
        if (partials[i] == partials[n-1]-partials[i])
            count++;
    }
    cout << count << endl;

    return 0;
}
