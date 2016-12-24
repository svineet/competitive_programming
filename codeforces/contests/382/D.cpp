#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n; cin >> n;
    if (n==2) {
        cout << 1 << endl;
        return 0;
    }
    if (n%2==0) {
        cout << 2 << endl;
        // Goldbach conjecture
        // verified for numbers upto
        // 1e18
        return 0;
    }

    bool prime = true;
    for (int i=2; i<=sqrt(n); i++) {
        if (n%i==0) {
            prime = false;
            break;
        }
    }

    if (prime) {
        cout << 1 << endl;
    } else {
        bool prime = true;
        n -= 2;
        for (int i=2; i<=sqrt(n); i++) {
            if (n%i==0) {
                prime = false;
                break;
            }
        }

        if (prime)
            cout << 2 << endl;
        else
            cout << 3 << endl;
    }

    return 0;
}
