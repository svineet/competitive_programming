#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main() {
	//freopen("sample.in", "r", stdin);
	int n; cin >> n;
	string inp; cin >> inp;

	int dp[n][n];
	for (int i=0; i<n; i++) {
		dp[i][i] = 1;
	}
	
	int left=0, right=0;
	for (int size=2; size<=n; size++) {
		for (int i=0; i<=(n-size); i++) {
			int j = i+size-1;
			dp[i][j] = 0;
			if (inp[i] == inp[j]) {
				if (size==2 || dp[i+1][j-1]) {
					dp[i][j] = 1;
					if (j-i>right-left) {
						right = j;
						left = i;
					}
				}
			}
		}
	}

	cout << right-left+1 << endl;
	for (int i=left; i<=right; i++) {
		cout << inp[i];
	}
	cout << endl;
	
	return 0;
}
