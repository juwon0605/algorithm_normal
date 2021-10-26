/*
1. 길 확인하기
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		vector<vector<int>> map(8, vector<int>(8));
		vector<vector<int>> flag(8, vector<int>(8));
		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8; j++) {
				cin >> map[i][j];
			}
		}
		queue<pair<int, int>> pQ;
		if (map[0][0] != 0) {
			pQ.push(make_pair(0, 0));
			flag[0][0] = 1;
		}
		while (!pQ.empty()) {
			int i = pQ.front().first;
			int j = pQ.front().second;
			pQ.pop();
			int ii, jj;
			if (map[i][j] == 1 || map[i][j] == 3) {
				ii = i;
				jj = j + 1;
			}
			else if (map[i][j] == 2 || map[i][j] == 4) {
				ii = i + 1;
				jj = j;
			}
			if (ii < 0 || ii >= 8 || jj < 0 || jj >= 8 || map[ii][jj] == 0 || flag[ii][jj] > 0) continue;
			if ((map[i][j] == 1 || map[i][j] == 3) && (map[ii][jj] == 2 || map[ii][jj] == 3)) continue;
			else if ((map[i][j] == 2 || map[i][j] == 4) && (map[ii][jj] == 1 || map[ii][jj] == 4)) continue;
			pQ.push(make_pair(ii, jj));
			flag[ii][jj] = flag[i][j] + 1;
		}
		cout << (flag[7][7] > 0 ? "YES" : "NO") << "\n";
	}
	return 0;
}

/*
모범 답안
	시간복잡도
		O(N^2)
	공간복잡도
		O(N^2)
*/