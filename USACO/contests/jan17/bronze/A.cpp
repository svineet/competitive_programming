#include <bits/stdc++.h>
using namespace std;

int get_dex(string str) {
    if (str == "Bessie")
        return 0;
    else if (str == "Elsie")
        return 1;
    else if (str == "Daisy")
        return 2;
    else if (str == "Gertie")
        return 3;
    else if (str == "Annabelle")
        return 4;
    else if (str == "Maggie")
        return 5;
    else if (str == "Henrietta")
        return 6;
    else
        return 1e8;
}

string namedex[7] = {
    "Bessie", "Elsie", "Daisy",
    "Gertie", "Annabelle", "Maggie",
    "Henrietta"
};

int main() {
    freopen("notlast.in", "r", stdin);
    freopen("notlast.out", "w", stdout);

    int n; cin >> n;
    int prods[7] = {0};
    for (int i=0; i<n; i++) {
        string name; int prod;
        cin >> name; cin >> prod;
        prods[get_dex(name)] += prod;
    }
    
    pair<int, string> cows[7];
    for (int i=0; i<7; i++) {
        cows[i].first = prods[i];
        cows[i].second = namedex[i];
    }
    sort (cows, cows+7);

    bool found = false;
    int bf = 1e8;
    for (int i=1; i<7; i++) {
        //cout << cows[i].first << " " << cows[i].second << endl;
        if (!found && cows[i].first>cows[i-1].first) {
            // Bump has been hit.
            found = true;
            bf = i;
            continue;
        }

        if (found && cows[bf].first == cows[i].first) {
            cout << "Tie" << endl;
            return 0;
        }
    }

    if (!found)
        cout << "Tie" << endl;
    else
        cout << cows[bf].second << endl;

    return 0;
}
