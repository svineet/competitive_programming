#include <bits/stdc++.h>
using namespace std;

bool sieve[(int)1e7+10];
int cunt[(int)1e7+10];
int pre[(int)1e7+10];

int main() {
    int n; scanf("%d", &n);
    for (int i=0; i<n; i++) {
        int x; scanf("%d", &x);
        cunt[x]++;
    }

    fill (sieve, sieve+(int)1e7+1, true);
    for (long long i=2; i<1e7+2; i++) {
        if (sieve[i]) {
            for (long long j=2*i; j<1e7+2; j+=i) {
                sieve[j] = false;
            }
        }
    }

    pre[1] = 0;
    for (long long i=2; i<1e7+2; i++) {
        if (sieve[i]) {
            for (long long j=i; j<1e7+2; j+=i) {
                pre[i] += cunt[j];
            }
        } else {
            pre[i] = 0;
        }
        pre[i] += pre[i-1];
    }

    int q; scanf("%d", &q);
    for (int i=0; i<q; i++) {
        int l, r;
        scanf("%d%d", &l, &r);
        if (l>1e7) {
            cout << 0 << endl;
            continue;
        } else if (r>1e7) {
            r = 1e7;
        }
        printf("%d\n", pre[r]-pre[l-1]);
    }

    return 0;
}
