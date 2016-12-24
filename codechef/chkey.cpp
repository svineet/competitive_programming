#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;

int main() {
	//freopen("sample.in", "r", stdin);
	int t; cin >> t;
	while (t--) {
		int n, m, c;
		cin >> n >> m >> c;
		int root = sqrt(c);
		int result = 0;
		for (int i=1; i<=n; i++) {
			if (c%i==0) {
				int a = i;
				int b = c/i;
				if (b<=m) result++;
			}
		}
		cout << result << endl;
	}
	
	return 0;
}
