#include <bits/stdc++.h>
using namespace std;

bool prime[int(1e9+1)];

int main() {
    prime[2] = false;
    int inc = 1;
    for (long long i=2; i<(long long)(1e5+1); i+=inc) {
        cout << i << endl;
        for (long long j=i*i; j<(long long)(1e9+1); j+=i) {
            prime[j] = true;
        }
        if (i==3) inc = 2;
    }

    vector<int> twins;
    for (long long i=2; i<(long long)(1e9-1); i++) {
        if (!prime[i] && !prime[i+2]) {
            twins.push_back(i);
        }
    }

    cout << "{";
    for (int i=0; i<(int)twins.size(); i++) {
        cout << twins[i];
        if ((int)twins.size()-1==i)
            cout << "}";
        else
            cout << ",";
    }
}
