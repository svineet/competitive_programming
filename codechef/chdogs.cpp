#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

int main() {
	//freopen("sample.in", "r", stdin);
	int t; cin >> t;
	while (t--) {
		double s, v; cin >> s >> v;
		printf("%.6f\n", (2*s)/(3*v));
	}
	
	return 0;
}
