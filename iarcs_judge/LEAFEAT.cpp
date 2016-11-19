#include <iostream>
#include <set>
using namespace std;

int main() {
    long long n; 
    int k;
    cin >> n >> k;
    long long caterpillars[k];
    for (int i=0; i<k; i++) {
        cin >> caterpillars[i];
    }

    long long eaten = 0;
    set<long long> differences;
    for (int i=0; i<k; i++) {
        eaten += (n+caterpillars[i]-1)/caterpillars[i];
        cout << eaten << endl;
        for (int j=i+1; j<k; j++) {
            differences.insert(caterpillars[i]*caterpillars[j]);
        }
    }

    for (set<long long>::const_iterator it=differences.begin();
         it!=differences.end();
         it++) {
        eaten -= (n+(*it)-1)/(*it);
    }
    cout << eaten << endl;

    return 0;
}
