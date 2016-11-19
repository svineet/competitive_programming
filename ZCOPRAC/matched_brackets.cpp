#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;


int main() {
	// freopen("sample.in", "r", stdin);
	
	int n; cin >> n;
	int array[n];
	for (int i=0; i<n; i++) {
		cin >> array[i];
	}
	
	int bests=0, bestf=0;
	int curs=0;
	int bestd=0;
	int depth=0, depthdex=0;
	for (int i=0; i<n; i++) {
		if (array[i] == 1) {
			depth++;
			if (depth>bestd) {
				bestd = depth;
				depthdex = i;
			}
		} else if (array[i] == 2) {
			depth--;
		}

		if (depth==0) {
			if (i-curs>bestf-bests) {
				bests = curs;
				bestf = i;
			}
			curs = i+1;
		}
	}
	cout << bestd << " " << depthdex+1 << " " << bestf-bests+1 << " " << bests+1;
}
