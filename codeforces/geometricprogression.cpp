#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	freopen("sample.in", "r", stdin);
	int n, k; cin >> n >> k;
	vector<int> positives;
	positives.reserve(n);
	vector<int> negatives;
	negatives.reserve(n);

	for (int i=0; i<n; i++) {
		int temp; cin >> temp;
		positives.push_back(temp);
	}
	
	sort (positives.begin(), positives.end());
	int lp = positives.size();
	
	long long count = 0;
	for (int i=0; i<lp; i++) {
		int find = positives[i]*k;
		long long tcount = 0;
		int lb = lower_bound(positives.begin()+i, positives.end(),
							 find)-positives.begin();
		int ub = upper_bound(positives.begin()+i, positives.end(),
							 find)-positives.begin();
		
		if (k==1) {
			long long x = ub-lb;
			count += (x*(x-1)*(x-2))/6;
			i = ub-1;
			continue;
		}

		if (ub-lb!=0) {
			tcount = ub-lb;
			cout << find << " " << lb << " " << ub << endl;
			
			find *= k;
			int lb2 = ub;
			
			lb = lower_bound(positives.begin()+lb2, positives.end(),
							 find)-positives.begin();
			ub = upper_bound(positives.begin()+lb2, positives.end(),
							 find)-positives.begin();
			cout << find << " " << lb << " " << ub << endl;
			tcount = tcount*(ub-lb);
		}
		count += tcount;
	}

	/*for (int i=0; i<ln; i++) {
		int find = negatives[i]*k;
		long long tcount = 0;
		int lb = lower_bound(negatives.begin(), negatives.end(),
							 find)-negatives.begin();
		int ub = upper_bound(negatives.begin(), negatives.end(),
							 find)-negatives.begin();
		
		cout << lb << " " << ub << endl;			 
		if (k==1) {
			long long x = ub-lb;
			count += (x*(x-1)*(x-2))/6;
			i = ub-1;
			continue;
		}
		

		if (ub-lb!=0) {
			tcount = ub-lb;
			find *= k;
			
			lb = lower_bound(negatives.begin(), negatives.end(),
							 find)-negatives.begin();
			ub = upper_bound(negatives.begin(), negatives.end(),
							 find)-negatives.begin();
			tcount = tcount*(ub-lb);
		}
		count += tcount;
	}*/
	
	cout << count << endl;
	
	return 0;
}
