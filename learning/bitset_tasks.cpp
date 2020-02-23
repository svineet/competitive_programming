#include <bits/stdc++.h>
using namespace std;


int main(int argc, char **argv) {
    int n = 128+256;
    cout << (1 << __builtin_ctz(n)) << endl;

    return 0;
}

