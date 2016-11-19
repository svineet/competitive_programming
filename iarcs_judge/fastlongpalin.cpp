#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
using namespace std;

int main() {
	//freopen("sample.in", "r", stdin);
	int n; cin >> n;
	string inp; cin >> inp;
	
	int left=0, right=0;

	queue< pair<int, int> > explore;
	for (int i=0; i<n; i++) {
		explore.push(make_pair(i, i));
	}
	for (int i=0; i<n-1; i++) {
		if (inp[i] == inp[i+1]) {
			left = i; right = i+1;
			explore.push(make_pair(i, i+1));
		}
	}

	while (!explore.empty()) {
		pair<int, int> back = explore.front();
		explore.pop();
		int i = back.first, j = back.second;
		if (i-1>=0 && j+1<n && inp[i-1] == inp[j+1]) {
			if (j-i+2>right-left) {
				left = i-1;
				right = j+1;
			}
			explore.push(make_pair(i-1, j+1));
		}
	}

	cout << right-left+1 << endl;
	for (int i=left; i<=right; i++) {
		cout << inp[i];
	}
	cout << endl;
	
	return 0;
}
