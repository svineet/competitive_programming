#include <bits/stdc++.h>
using namespace std;

int sum_dig(int num) {
    int sum = 0;
    while (num) {
        sum += (num%10);
        num /= 10;
    }
    return sum;
}

int main() {
    int n; cin >> n;
    int best = 1;
    for (int i=1; i<=int(sqrt(n)); i++) {
        if (n%i==0) {
            if (sum_dig(best) < sum_dig(i)) best = i;
            if (sum_dig(best) < sum_dig(n/i)) best = n/i;
        }
    }

    cout << best << endl;

    return 0;
}
