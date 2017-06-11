#include <bits/stdc++.h>
using namespace std;

long long n, tmax;
long long arr[40000];

bool feasible(int k) {
    priority_queue<int, vector<int>, greater<int>> Q;
    long long ltime = 0;
    // cout << k << endl;
    for (int i=0; i<n; i++) {
        int qs = Q.size();
        if (qs == k) {
            ltime = Q.top();
            Q.pop();
        }

        if (ltime+arr[i]>tmax) return false;
        // cout << ltime+arr[i] << " ";
        Q.push(ltime+arr[i]);
    }
    // cout << endl;

    return true;
}

int main() {
    freopen("cowdance.in", "r", stdin);
    freopen("cowdance.out", "w", stdout);

    cin >> n >> tmax;
    for (int i=0; i<n; i++) cin >> arr[i];

    int left = 1,
        right = n;
    while (left != right) {
        int mid = (left+right)/2;
        if (feasible(mid))
            right = mid;
        else
            left = mid+1;
    }

    assert (left == right);
    cout << left << endl;

    return 0;
}
