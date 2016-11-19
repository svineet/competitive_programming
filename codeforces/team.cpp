#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main() {
    int zero, one; cin >> zero >> one;
    string answer = "";
    if (zero>one) {
        answer = "0"; zero--;
    } else {
        answer = "1"; one--;
    }

    bool rekt = false;
    int tot = zero+one;
    for (int i=1; i<=tot; i++) {
        if (one>zero) {
            int count = 0;
            if (answer[i-1] == '1') count++;
            if (i!=1 && answer[i-2] == '1') count++;
            if (count < 2 && one > 0) {
                answer += "1";
                one--;
            } else {
                if (answer[i-1] != '0' && zero > 0) {
                    answer += "0";
                    zero--;
                } else {
                    rekt = true; break;
                }
            }
        } else {
            if (answer[i-1] != '0') {
                answer += "0";
                zero--;
            } else {
                int count = 0;
                if (answer[i-1] == '1') count++;
                if (i!=1 && answer[i-2] == '1') count++;
                if (count < 2 && one > 0) {
                    answer += "1";
                    one--;
                } else {
                    rekt = true;
                    break;
                }
            }
        }
    }
    if (rekt)
        cout << "-1" << endl;
    else
        cout << answer << endl;

    return 0;
}
