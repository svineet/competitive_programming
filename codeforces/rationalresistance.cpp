#include <bits/stdc++.h>
using namespace std;

long long steps(long long a, long long b) {
    if (b==0)
        return 0;
    else
        return a/b+steps(b, a%b);
}

int main() {
    long long a, b;
    cin >> a >> b;
    cout << steps(max(a, b), min(a, b)) << endl;
    
    return 0;
}
