/*
4. 큰 수와 작은 수의 합
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(string, string);

int main() {
	string str, strMin, strMax;
	int n;
	cin >> n;
	vector<string> strV(n);
	for (int i = 0; i < n; i++) {
		cin >> strV[i];
	}
	sort(strV.begin(), strV.end(), compare);
	for (int i = 0; i < n; i++) {
		strMin += strV[i];
		strMax += strV[n - 1 - i];
	}
	cout << stoll(strMin) + stoll(strMax);
	return 0;
}

bool compare(string a, string b) {
	if (a.size() == 1) a += a;
	if (b.size() == 1) b += b;
	return stoi(a) < stoi(b);
}

/*
모범 답안
	시간복잡도
		O(NlogN) (1<=N<=10)
	공간복잡도
		O(N)
*/

/*
모범 답안 반영 전

	주어지는 자연수가 1이상 99이하라 Counting Sort로 풀었음

	시간복잡도
		O(K)	(K=100)
	공간복잡도
		O(K)	(K=100)

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
	vector<vector<int>> board(10, vector<int>(10));
	vector<string> resV;
	string str, minStr, maxStr;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> str;
		if (str.size() == 1) {
			board[stoi(str)][stoi(str)] += 1;
		}
		else {
			board[str[0] - '0'][str[1] - '0'] += 2;
		}
	}
	for (int i = 1; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if (board[i][j] > 0) {
				if (i == j) {
					int k = board[i][j];
					while (k--) resV.push_back(to_string(i));
				}
				else {
					int k = board[i][j] / 2;
					while (k--) resV.push_back(to_string(i) + to_string(j));
				}
			}
		}
	}
	for (int i = 0; i < resV.size(); i++) {
		minStr += resV[i];
		maxStr += resV[resV.size() - 1 - i];
	}
	cout << stoll(minStr) + stoll(maxStr);
	return 0;
}
*/

