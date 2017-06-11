/*
ID: saivine1
PROG: friday
LANG: C++11
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("friday.in", "r", stdin);
    freopen("friday.out", "w", stdout);

    int n; cin >> n;
    int memo[7] = {0};

    int day = 1;
    int date = 1;
    int month = 1;
    int year = 1900;
    int daymemo[2][13] = {
        {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
        {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
    };

    while (!(date == 1 && month == 1 && year == 1900+n)) {
        if (date == 13) memo[day]++;

        int leap = (year%400==0 || (year%4==0 && year%100!=0));
        date++; day++;
        day %= 7;
        if (date > daymemo[leap][month]) {
            date = 1; month++;
            if (month > 12) {
                month = 1; year++;
            }
        }
    }

    cout << memo[6] << " ";
    for (int i=0; i<6; i++) {
        cout << memo[i];
        if (i == 5) cout << endl;
        else        cout << " ";
    }

    return 0;
}
