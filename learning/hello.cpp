#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int n;
    scanf("%d", &n);

    vector<long long> array;
    for (int cse=0; cse<n; cse++) {
        long long temp;
        scanf("%lld", &temp);
        array.push_back(temp);
    }

    std::sort(array.begin(), array.end());
    long long max=-5000;
    for (long long i=0; i<n; i++) {
        if (array[i]*(n-i)>max)
            max = array[i]*(n-i);
    }
    printf("%lld\n", max);

    return 0;
}
