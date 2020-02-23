#include <bits/stdc++.h>
using namespace std;


int main(int argc, char **argv) {
    /*
     * Find the maximum times occurring two length subsequence
     */

    string str; cin >> str;
    int n = str.size();

    long long cnts[26] = {0};
    unordered_map<string, long long> M;
    for (int i=0; i<n; i++) {
        for (int j=0; j<26; j++) {
            string k(1, ('a'+(char)j));
            k = k + str[i];

            // cout << k << endl;
            if (M.find(k) == M.end())
                M[k] = cnts[j];
            else
                M[k] += cnts[j];
        }

        // Add to counts
        cnts[str[i]-'a']++;
    }

    for (int i=0; i<26; i++) {
        if (cnts[i]) {
            string k(1, 'a'+i);
            M[k] = cnts[i];
        }
    }

    long long maxtym = 1;
    for (unordered_map<string, long long>::iterator iter=M.begin();
         iter != M.end(); iter++) {
        // cout << iter->first << " " << iter->second << endl;
        maxtym = max(maxtym, iter->second);
    }
    cout << maxtym << endl;

    return 0;
}

