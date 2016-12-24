#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n; cin >> n;

    long long i = 1;
    long long cur = 2;
    while (n--) {
        long long mult = i*(i+1);
        if (mult>cur)
            cout << "nigggaaa " << i << endl;
        cout << (mult*mult - cur)/i << endl;
        cur = mult;
        i++;
    }

    return 0;
}
