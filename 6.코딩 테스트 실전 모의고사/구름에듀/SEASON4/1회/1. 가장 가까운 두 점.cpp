/*
1. 가장 가까운 두 점
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	long long first = 0, second = 9999999999;
	int n;
	cin >> n;
	vector<long long> V(n);
	for (int i = 0; i < n; i++) {
		cin >> V[i];
	}
	sort(V.begin(), V.end());
	for (int i = 0; i < n - 1; i++) {
		if (second - first > V[i + 1] - V[i]) {
			first = V[i];
			second = V[i + 1];
		}
	}
	cout << first << " " << second;
	return 0;
}


/*
모범 답안
	시간복잡도
		O(NlogN)
	공간복잡도
		O(N)
*/