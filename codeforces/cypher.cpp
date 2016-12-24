#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main () {
    string inp; cin >> inp;
    int n = inp.length();

    long long a, b; cin >> a >> b;

    int adivs[n], bdivs[n];

    long long lastmod = (inp[0]-'0')%a;
    adivs[0] = lastmod==0;
    for (int i=1; i<n; i++) {
        long long cur = int(inp[i]-'0');
        lastmod = ((lastmod*(10%a))%a + cur%a)%a;
        if (lastmod == 0) {
            adivs[i] = 1;
        } else {
            adivs[i] = 0;
        }
    }

    lastmod = (inp[n-1]-'0')%b;
    bdivs[n-1] = (lastmod==0 && (inp[n-1]-'0')!=0);
    long long multiplier = 10%b;
    // No leading zeroes allowed
    for (int i=n-2; i>=0; i--) {
        long long cur = (inp[i]-'0');
        lastmod = (((cur%b)*(multiplier))%b+lastmod)%b;

        multiplier *= 10;
        multiplier %= b;

        if (lastmod == 0 && cur != 0) {
            bdivs[i] = 1;
        } else {
            bdivs[i] = 0;
        }
    }
    bool gotem = false;
    for (int i=0; i<n-1; i++) {
        if (adivs[i]==1 && bdivs[i+1]==1) {
            gotem = true;

            cout << "YES" << endl;
            for (int j=0; j<=i; j++) {
                cout << inp[j];
            }
            cout << endl;
            for (int j=i+1; j<n; j++) {
                cout << inp[j];
            }
            cout << endl;

            break;
        }
    }
    
    if (!gotem)
        cout << "NO" << endl;

    return 0;
}
