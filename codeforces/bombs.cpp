#include <stdio.h>
#include <algorithm>
using namespace std;

bool comparator(pair<long, long> &a,
				pair<long, long> &b) {
	long h1 = abs(a.first)+abs(a.second);
	long h2 = abs(b.first)+abs(b.second);
	return h1<h2;
}

int main() {
	//freopen("sample.in", "r", stdin);
	
	int n; scanf("%d", &n);
	
	
	long count = 2*n;
	pair<long, long> bombs[n];
	for (int i=0; i<n; i++) {
		scanf("%ld", &bombs[i].first);
		scanf("%ld", &bombs[i].second);
		if (bombs[i].first == 0 ||
			bombs[i].second == 0) {
			count+=2;
		} else {
			count+=4;
		}
	}
	sort (bombs, bombs+n, comparator);
	
	printf("%ld\n", count);
	for (int i=0; i<n; i++) {
		long x = bombs[i].first;
		long y = bombs[i].second;
		
		if (x!=0) {
			printf("1 %ld %c\n", abs(x), (x>0?'R':'L'));
		}
		
		if (y!=0) {
			printf("1 %ld %c\n", abs(y), (y>0?'U':'D'));
		}
		
		printf("%d\n", 2);
		
		if (x!=0) {
			printf("1 %ld %c\n", abs(x), (x>0?'L':'R'));
		}
		
		if (y!=0) {
			printf("1 %ld %c\n", abs(y), (y>0?'D':'U'));
		}
		
		printf("%d\n", 3);
		
	}
	
	return 0;
}
