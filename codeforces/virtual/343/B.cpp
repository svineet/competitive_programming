#include <bits/stdc++.h>
using namespace std;

struct Person {
    bool male;
    int s, f;
};

int main() {
    int n; cin >> n;
    Person persons[n];
    for (int i=0; i<n; i++) {
        string str; cin >> str;
        if (str == "M") persons[i].male = true;
        else            persons[i].male = false;
        int st, fi; cin >> st >> fi;
        persons[i].s = st;
        persons[i].f = fi;
    }

    int best = 0;
    for (int i=1; i<=366; i++) {
        int males = 0, females = 0;
        // We take the minimum of these two
        // and invite the same number of
        // the opposite sex.
        for (int j=0; j<n; j++) {
            if (persons[j].s <= i && i <= persons[j].f) {
                if (persons[j].male)
                    males++;
                else
                    females++;
            }
        }

        int mexd = min(males, females);
        best = max(best, 2*mexd);
    }

    cout << best << endl;

    return 0;
}
