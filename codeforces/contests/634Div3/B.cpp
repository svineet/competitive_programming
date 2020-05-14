#include <bits/stdc++.h>
using namespace std;

int main(int argc, char **argv) {
    int t; cin >> t;
    while (t--) {
        int n, a, b; cin >> n >> a >> b;

        int counters[26] = {0};
        char result[n] = {' '};

        // First set up seed string
        // Fill the first `a` slots with abcde..and repeat the last character till we
        // get a `b` distint char seed string
        char last = 'a';
        for (int i=0; i<b; i++) {
            counters[b]++;
            result[i] = 'a'+i;
            last = result[i];
        }

        for (int i=b; i<a; i++) {
            result[i] = last;
            counters[last-'a']++;
        }

        for (int i=a; i<n; i++) {
            // We try to fill this character
            // Find out character count of i-a
            switch(counters[result[i-a]-'a']) {
                case 1:
                    // Removal will need addition of a new character that
                    // increases distinct count. Add this character itself lol.
                    result[i] = result[i-a];
                    break;
                default:
                    // Removal will not change number of distinct characters
                    result[i] = result[i-a];
                    break;
            }
        }

        for (int i=0; i<n; i++) {
            cout << result[i];
        }
        cout << endl;
    }

    return 0;
}
