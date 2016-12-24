#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    int n; cin >> n;
    pair<int, int> points[n];
    map< pair<int, int>, long long> occurs;
    map<int, long long> X, Y;
    for (int i = 0; i<n; i++) {
        cin >> points[i].first >> points[i].second;
        occurs[points[i]]++;
        X[points[i].first]++; Y[points[i].second]++;
    }

    long long count = 0;
    map<int, long long>::iterator iter;
    for (iter = X.begin(); iter != X.end(); iter++) {
        if (iter->second>=2) {
            count += iter->second*(iter->second-1)/2;
        }
    }
    for (iter = Y.begin(); iter != Y.end(); iter++) {
        if (iter->second>=2) {
            count += iter->second*(iter->second-1)/2;
        }
    }
    
    map< pair<int, int>, long long>::iterator iter2;
    for (iter2 = occurs.begin();
         iter2 != occurs.end();
         iter2++) {
        if (iter2->second>=2) {
            count -= iter2->second*(iter2->second-1)/2;
        }
    }

    cout << count << endl;

    return 0;
}
