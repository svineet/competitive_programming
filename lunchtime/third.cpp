#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int t; cin >> t;
    for (int cs=0; cs<t; cs++) {
        int n; cin >> n;
        string ans;
        if (n==1) {
            cout << "3 1" << endl;
            cout.flush();

            continue;
        }
        
        if (n==2) {
            cout << "2 1 2" << endl;
            cout.flush();
            cin >> ans;
            if (ans == "Yes")
                cout << "3 1 2" << endl;
            else
                cout << "3 2 1" << endl;

            continue;
        }

        cout << "1 1 3 2" << endl;
        cout.flush();

        cin >> ans;
        if (ans == "Yes") {
            cout << "2 1 3" << endl;
            cout.flush();
            cin >> ans;
            if (ans == "Yes") {
                cout << "3 1 2 3" << endl;
            } else {
                cout << "3 3 2 1" << endl;
            }
            cout.flush();
        }
        else {
            cout << "1 2 3 2" << endl;
            cout.flush();
            cin >> ans;
            if (ans == "Yes") {
                cout << "2 2 3" << endl;
                cout.flush();
                cin >> ans;
                if (ans == "Yes") {
                    cout << "3 2 1 3" << endl;
                } else {
                    cout << "3 2 3 1" << endl;
                }
                cout.flush();
            }
            else {
                cout << "2 1 2" << endl;
                cout.flush();
                cin >> ans;
                if (ans == "Yes") {
                    cout << "3 1 3 2" << endl;
                } else {
                    cout << "3 3 1 2" << endl;
                }
                cout.flush();
            }
        }
    }

    return 0;
}
