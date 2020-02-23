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

        RollingHash(string str) {
            this->len = str.size();

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

