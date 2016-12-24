#include <stdio.h>
#include <algorithm>
using namespace std;

int main() {
	//freopen("sample.in", "r", stdin);

	int m, n;
	scanf("%d%d", &m, &n);
	
	long long sums[m][n];
	for (int i=0; i<m; i++) {
		for (int j=0; j<n; j++) {
			scanf("%lld", &sums[i][j]);
			if (i==0 && j==0) {
				continue;
			} else if (j==0) {
				sums[i][0] = sums[i][0]+sums[i-1][0];
			} else if (i==0) {
				sums[0][j] = sums[0][j]+sums[0][j-1];
			} else {
				sums[i][j] = sums[i][j] + sums[i-1][j] + sums[i][j-1] - sums[i-1][j-1];
			}
		}
	}
	
	/*for (int i=0; i<m; i++) {
		for (int j=0; j<n; j++) {
			cout << sums[i][j] << " ";
		}
		cout << endl;
	}*/
	
	int c; scanf("%d", &c);
	for (int i=0; i<c; i++) {
		int x1, y1, x2, y2;
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
		x1--; y1--; x2--; y2--;
		long long res = sums[x2][y2];
		res -= ((x1-1>=0?sums[x1-1][y2]:0) + (y1-1>=0?sums[x2][y1-1]:0));
		res += (x1-1>=0 && y1-1>=0?sums[x1-1][y1-1]:0);

		printf("%lld\n", res);
	}
	
	return 0;
}
