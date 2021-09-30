/*
3. 큰 호수
설명
현수의 농장이 최근 폭풍으로 물바다가 되었다. 그러나 현수가 가입한 보험 회사는 그의 농장에 생긴 가장 큰 호수의 규모에 따라
보상액을 결정해 그것만 보상할 것이다.
농장은 세로N(1≤N≤100), 가로 M(1≤M≤100)개의 격자로 된 직사각형 모양이다. 농장은 K개 격자가 침수되었다.
호수는 각 침수된 각 격자의 변을 공유한다. 상하좌우로 연결되어 있으면 같은 호수이다.
보상을 받을 수 있는 가장 큰 호수의 크기를 구하는 프로그램을 작성하세요.
입력
첫째 줄 : 3개의 정수 N, M, K.
둘째 줄부터 침수된 격자의 행과 열 번호가 주어진다.
출력
가장 큰 호수의 격자의 개수를 출력한다.
예시 입력 1
3 4 5
3 2
2 2
3 1
2 3
1 1
예시 출력 1
4
*/

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void DFS(int, int);
int map[102][102];
int dy[4] = { 1,0,-1,0 }, dx[4] = { 0,1,0,-1 };
int n, m, k, cnt;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	freopen("input.txt", "rt", stdin);
	vector<pair<int, int>> pV;
	int y, x, res = -1;
	cin >> n >> m >> k;
	for (int i = 0; i < k; i++) {
		cin >> y >> x;
		map[y][x] = 1;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (map[i][j] == 1) {
				cnt = 0;
				DFS(i, j);
				if (res < cnt) res = cnt;
			}
		}
	}
	cout << res;
	return 0;
}

void DFS(int i, int j) {
	map[i][j] = 0;
	cnt++;
	for (int t = 0; t < 4; t++) {
		int ii = i + dy[t];
		int jj = j + dx[t];
		if (map[ii][jj] == 1) {
			DFS(ii, jj);
		}
	}
}

/*
모범 답안
	시간복잡도
		O(N^2)
	공간복잡도
		O(N^2)
*/

/*
모범 답안 반영 전

	1<=N<=100이고 1<=K<=N^2이여서 N^4여도 1초안에 될 것 같아서 BFS로 풀었다.
	이 경우는 DFS로 푸는게 훨씬 빠르다!

	시간복잡도
		O(N^2 * K) (1<=K<=N^2)
	공간복잡도
		O(N^2)

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void BFS(int, int);
int map[100][100];
int accum[100][100];
int dy[4] = { 1,0,-1,0 }, dx[4] = { 0,1,0,-1 };
int n, m, k;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	freopen("input.txt", "rt", stdin);
	vector<pair<int, int>> pV;
	int y, x, max = -1;
	cin >> n >> m >> k;
	for (int i = 0; i < k; i++) {
		cin >> y >> x;
		map[y - 1][x - 1] = 1;
		pV.push_back(make_pair(y - 1, x - 1));
	}
	for (int i = 0; i < k; i++) {
		BFS(pV[i].first, pV[i].second);
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (max < accum[i][j]) max = accum[i][j];
		}
	}
	cout << max;
	return 0;
}

void BFS(int y, int x) {
	vector<vector<int>> flag(n, vector<int>(m));
	queue<pair<int, int>> pQ;
	accum[y][x] += 1;
	flag[y][x] = 1;
	pQ.push(make_pair(y, x));
	while (!pQ.empty()) {
		pair<int, int> now = pQ.front();
		pQ.pop();
		int i = now.first;
		int j = now.second;
		for (int t = 0; t < 4; t++) {
			int ii = i + dy[t];
			int jj = j + dx[t];
			if (ii < 0 || ii >= n || jj < 0 || jj >= m ||
				map[ii][jj] == 0 || flag[ii][jj] > 0) continue;
			accum[ii][jj] += 1;
			flag[ii][jj] = 1;
			pQ.push(make_pair(ii, jj));
		}
	}
}
*/