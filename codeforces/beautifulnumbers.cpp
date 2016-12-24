#include <bits/stdc++.h>
using namespace std;

long long fact[1000005];
long long MOD = 1e9 + 7;

long long ModExponen(long long a, long long pow) {
    if (pow == 1) return a%MOD;
    if (pow == 0) return 1%MOD;

    if (pow%2==1) {
        return (a*ModExponen(a, pow-1))%MOD;
    } else {
        long long res = ModExponen(a, pow/2)%MOD;
        return (res*res)%MOD;
    }
}

long long Choose(long long n,
                 long long r) {
    long long ch = fact[n];
    long long inverse = ModExponen((fact[r]*fact[n-r])%MOD, MOD-2);
    return (ch*inverse)%MOD;
}

int main() {
    int n, a, b;
    cin >> a >> b >> n;

    fact[0] = fact[1] = 1;
    for (int i=2; i<=1000000; i++) {
        fact[i] = i*fact[i-1];
        fact[i] %= MOD;
    }

    long long count = 0;
    for (int i=0; i<=n; i++) {
        long long sum = a*i+b*(n-i);
        bool fukt = false;
        while (sum>0 && !fukt) {
            int d = sum%10;
            if (d!=a && d!=b)
                fukt = true;

            sum /= 10;
        }

        if (!fukt) {
            count += Choose(n, i);
            count %= MOD;
        }
    }
    cout << count << endl;

    return 0;
}
