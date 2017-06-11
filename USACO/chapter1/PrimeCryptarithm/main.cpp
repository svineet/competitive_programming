/*
ID: saivine1
PROG: crypt1
LANG: C++11
*/
#include <bits/stdc++.h>
using namespace std;

int n;
int digs[10];
vector<int> ch;

long long solve(int left) {
    if (left == 0) {
        int a = ch[0]*100+ch[1]*10+ch[2];

        int p1 = a*ch[3];
        int p2 = a*ch[4];
        if (int(log10(p1))+1>3 ||
            int(log10(p2))+1>3) return 0;

        int ans = p1;
        while (ans > 0) {
            int d = ans%10;
            bool found = false;
            for (int i=0; i<n; i++) found = found || (digs[i]==d);
            if (!found) return 0;
            ans /= 10;
        }

        ans = p2;
        while (ans > 0) {
            int d = ans%10;
            bool found = false;
            for (int i=0; i<n; i++) found = found || (digs[i]==d);
            if (!found) return 0;
            ans /= 10;
        }

        ans = p1+p2*10;
        while (ans > 0) {
            int d = ans%10;
            bool found = false;
            for (int i=0; i<n; i++) found = found || (digs[i]==d);
            if (!found) return 0;
            ans /= 10;
        }

        return 1;
    }

    int cnt = 0;
    for (int i=0; i<n; i++) {
        ch.push_back(digs[i]);
        cnt += solve(left-1);
        ch.pop_back();
    }

    return cnt;
}

int main() {
    freopen("crypt1.in", "r", stdin);
    freopen("crypt1.out", "w", stdout);

    cin >> n;
    ch.reserve(5);
    for (int i=0; i<n; i++) cin >> digs[i];

    cout << solve(5) << endl;

    return 0;
}
