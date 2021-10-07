/*
5. 보물찾기
설명
현수, 영희, 동현은 자신들이 보물이 있다고 생각하는 섬에 도착했다.
보물섬의 지도는 N*N크기의 격자로 되어 있으며 0은 이동할 수 있는 지역을 표시하고, 1은 이동할 수 없는 지역을 표시된다.
이들은 보물을 찾기 위해 서로 다른 위치에서 출발하여 찾기로 했다.
이동은 상하좌우로만 움직일 수 있으며, 1초에 한 칸씩 이동속도는 동일합니다.
셋은 이동하지 않고 멈춰 있을 수 도 있습니다.
이들 셋이 이동하다 서로 만날 수 있는 지점중에서 최소시간으로 만날 수 있는 지점에 보물이 있다고 확신합니다.
현수, 영희, 동현의 생각대로라면 보물섬에 보물이 있는 지역은 몇 개인지 구해주는 프로그램을 작성하세요.
입력
첫 번째 줄에 N(3<=N<=100)이 입력됩니다.
두 번째 줄부터 N*N의 지도 정보가 입력됩니다.
마지막 세 줄의 현수, 영희, 동현의 출발위치가 주어집니다. 지도의 왼쪽 제일 위쪽 좌표를 (1, 1)로 합니다.
현수, 영희, 동현의 위치는 항상 이동가능한 위치로 주어집니다.
출력
첫 번째 줄에 보물이 존재하는 지역을 개수를 출력합니다. 보물이 존재하는 위치가 없으면 -1을 출력합니다.
예시 입력 1
4
1 0 0 0
0 0 0 0
0 1 0 1
1 0 0 1
1 2
4 3
3 1
예시 출력 1
2
*/

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

void BFS(int, int, int);
int flag[3][100][100];
int map[100][100];
int dy[4] = { 1,0,-1,0 }, dx[4] = { 0,1,0,-1 };
int n;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	freopen("input.txt", "rt", stdin);
	vector<vector<int>> maxFlag(100, vector<int>(100, 2147000000));
	int y, x, res = 0, minDis = 2147000000;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
		}
	}
	for (int i = 0; i < 3; i++) {
		cin >> y >> x;
		BFS(i, y - 1, x - 1);
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (flag[0][i][j] == 0 ||
				flag[1][i][j] == 0 ||
				flag[2][i][j] == 0) continue;
			maxFlag[i][j] = max(flag[0][i][j], max(flag[1][i][j], flag[2][i][j]));
			minDis = min(minDis, maxFlag[i][j]);
		}
	}
	if (minDis == 2147000000) {
		res = -1;
	}
	else {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (maxFlag[i][j] == minDis) res++;
			}
		}
	}
	cout << res;
	return 0;
}

void BFS(int who, int starti, int startj) {
	queue<pair<int, int>> pQ;
	pQ.push(make_pair(starti, startj));
	flag[who][starti][startj] = 1;
	while (!pQ.empty()) {
		pair<int, int> now = pQ.front();
		pQ.pop();
		int i = now.first;
		int j = now.second;
		for (int k = 0; k < 4; k++) {
			int ii = i + dy[k];
			int jj = j + dx[k];
			if (ii < 0 || ii >= n || jj < 0 || jj >= n ||
				map[ii][jj] == 1 || flag[who][ii][jj] > 0) continue;
			pQ.push(make_pair(ii, jj));
			flag[who][ii][jj] = flag[who][i][j] + 1;
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