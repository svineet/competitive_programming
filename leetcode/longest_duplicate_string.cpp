#include <bits/stdc++.h>
using namespace std;


class RollingHash {
    public:
        const long long M = 1000000123, // Modulus
                        D = 117;        // Base

        long long raised_d;
        long long hash;
        int len;

        queue<char> current_characters;

        RollingHash(string str, int len) {
            this->len = len;

            long long raised_m = 1;
            for (int i=0; i<len-1; i++)
                raised_m = (raised_m*D)%M;
            this->raised_d = raised_m;

            long long h = 0;
            for (int i=0; i<len; i++) {
                h = (h*D + str[i])%M;
                this->current_characters.push(str[i]);
            }

            this->hash = h;
            cout << hash << endl;
        }

        long long get_hash() {
            return this->hash;
        }

        void roll_over(char new_char) {
            char delet = this->current_characters.front();

            long long h = this->hash;
            h = (D*(h - delet*(this->raised_d)) + new_char)%M;
            if (h < 0) h += M;
            this->hash = h;

            this->current_characters.pop();
            this->current_characters.push(new_char);
        }
};


bool dup_exists(string S, int len) {
    /*
        Idea is to maintain a running hash and a hash
        table to store number of occurrences.
    */

    int n = S.size();

    unordered_map<long long, int> M;
    RollingHash* h = new RollingHash(S, len);
    M[h->get_hash()] = 0;
    for (int i=len; i<n; i++) {
        h->roll_over(S[i]);
        if (M.find(h->get_hash()) != M.end()) {
            // Check for true equal match
            bool equal = true;
            int idx = M[h->get_hash()];
            int j = idx;
            int k = i-len+1;
            while (j < idx+len && equal) {
                equal = equal && (S[j] == S[k]);
                j++; k++;
            }

            if (equal) return true;
        }
        M[h->get_hash()] = i;
    }

    return false;
}

string longestDupSubstring(string S) {
    int n = S.size();
    int low=0,high=n-1;
    
    while (low != high) {
        int mid = (high+low)/2;
        if (dup_exists(S, mid)) {
            low = mid;
        } else {
            high = mid-1;
        }
    }
}

int main(int argc, char **argv) {
    cout << dup_exists("vinvin", 3) << endl;

    string str; cin >> str;
    cout << longestDupSubstring(str) << endl;

    return 0;
}
