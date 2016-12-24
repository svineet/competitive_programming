#include <bits/stdc++.h>
using namespace std;

bool antisieve[10000001];
// antisieve[i] is true if 
// i is composite

int main() {
    long long n; cin >> n;
    long long n2 = n;
  
    if (n==1) {
        cout << 1 << endl << 0 << endl;
        return 0;
    }

    antisieve[2] = false;
    long long inc = 1;
    for (long long i=2; i<10000001; i+=inc) {
        if (!antisieve[i]) {
            for (long long j=i*i; j<10000001; j+=i) {
                antisieve[j] = true;
            }
        }
        if (i==3) inc = 2;
        // Check only odd things
    }

    if (n<=1e7 && !antisieve[n]) {
        cout << 1 << endl << 0 << endl;
        return 0;
    } else {
        bool prime = true;
        for (int i=2; i<=sqrt(n); i++) {
            if (n%i==0) {
                prime = false;
                break;
            }
        }

        if (prime) {
            cout << 1 << endl << 0 << endl;
            return 0;
        }
    }

    vector<long long> divisors;
    int len = 0;
    long long looplim = sqrt(n);
    for (long long i=2; i<=min(looplim, n); i++) {
        if (!antisieve[i] && n%i==0) {
            len = divisors.size();
            divisors.push_back(i);
            if (len>=2) break;

            n /= i; i--; // Counteract the i++
        }
    }

    len = divisors.size();
    /*for (int i=0; i<len; i++)
        cout << divisors[i] << " ";
    cout << endl;*/

    if (len>=2) {
        if (divisors[0]*divisors[1] == n2) {
            cout << 2 << endl;
            return 0;
        }
        cout << 1 << endl;
        cout << divisors[0]*divisors[1] << endl;
        // Product of two prime numbers forces
        // 2 to select a prime number which
        // then makes 1 unable to make any moves
        // causing 1 to win
    } else {
        // 1 cannot select two prime numbers
        // as factors
        cout << 2 << endl;
    }

    return 0;
}
