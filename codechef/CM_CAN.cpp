
#include <iostream>
using namespace std;

pair<long long, int> stree[400010];
// Sum, number of numbers.
long long arr[200000];
const long long MOD = 1e9+7;

pair<long long, int> query(int node, int left, int right,
                           int ql, int qr) {
    if (qr < left || ql > right) {
        return make_pair(0, 0);
    }

    if (ql <= left && right <= qr) {
        return stree[node];
    }

    int mid = (left+right)/2;
    int ln = 2*node+1,
        rn = 2*node+2;
    pair<long long, int> qln, qrn;
    qln = query(ln, left, mid, ql, qr);
    qrn = query(rn, mid+1, right, ql, qr);
    return make_pair((qln.first+qrn.first)%MOD, qln.second+qrn.second);
}

void update_tree(int node, int left, int right, int updex, int val) {
    if (left == right && updex == left) {
        stree[node].first += val;
        stree[node].first %= MOD;
        stree[node].second++;
        // cout << stree[node].first << stree[node].second << endl;
        return;
    }
    
    if (updex < left || updex > right) {
        return;
    }
    
    int mid = (left+right)/2;
    int ln = 2*node+1,
        rn = 2*node+2;
    update_tree(ln, left, mid, updex, val);
    update_tree(rn, mid+1, right, updex, val);
    stree[node].first = (stree[rn].first+stree[ln].first)%MOD;
    stree[node].second = stree[rn].second+stree[ln].second;
}


int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        for (int i=0; i<n; i++) cin >> arr[i];
        
        fill(stree, stree+400010, make_pair(0, 0));
        
        cout << arr[0] << " ";
        update_tree(0, 0, 100000, arr[0], arr[0]);
        for (int i=1; i<n; i++) {
            pair<long long, int> left = query(0, 0, 100000, 0, arr[i]-1);
            pair<long long, int> right = query(0, 0, 100000, arr[i]+1, 100000);
            long long ans = (arr[i]*left.second-left.first)%MOD;
            ans += (right.first-arr[i]*right.second)%MOD;
            ans %= MOD;
            cout << ans;
            if (i == n-1) cout << endl;
            else          cout << " ";
            
            update_tree(0, 0, 100000, arr[i], arr[i]);
        }
    }

	return 0;
}

