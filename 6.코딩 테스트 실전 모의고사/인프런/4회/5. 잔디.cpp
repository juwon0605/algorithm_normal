/*
5. 잔디
설명
현수는 산기슭에 별장을 지었습니다. 별장의 마당이 정사각형 모양의 격자판으로 표현됩니다.
격자판에는 잔디를 심은 곳(2), 맨땅(0), 바위(1)로 표시되어 있습니다.
잔디는 하루 동안 자신의 위치에서 상, 하, 좌, 우의 맨땅으로 한 칸씩 퍼져나갑니다.
잔디가 퍼진 지역도 마찬가지로 하루 동안 자신의 상, 하, 좌, 우의 맨땅으로 퍼집니다. 단 바위가 있는 지역은 퍼질 수 없습니다.
바위가 가로막아 잔디가 퍼지지 못하는 맨땅은 존재하지 않습니다.
N*N 크기의 마당정보가 주어지면 마당의 맨땅이 잔디로 꽉 차는 최단시간을 몇 일인지 구하는 프로그램을 작성하세요.
입력
첫 번째 줄에 N(3<=N<=30)이 입력됩니다.
두 번째 줄부터 N*N의 지도 정보가 입력됩니다.
출력
첫 번째 줄에 최소 기간를 출력합니다.
예시 입력 1
5
1 0 0 0 0
0 0 0 1 0
0 1 2 1 0
0 0 1 2 0
0 0 0 0 0
예시 출력 1
5
*/

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void BFS();
int map[30][30];
int flag[30][30];
int dy[4] = { 1,0,-1,0 }, dx[4] = { 0,1,0,-1 };
vector<pair<int, int>> pV;
int n;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	freopen("input.txt", "rt", stdin);
	int max = -1;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
			if (map[i][j] == 2) pV.push_back(make_pair(i, j));
		}
	}
	BFS();
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (max < flag[i][j]) max = flag[i][j];
		}
	}
	cout << max - 1;
	return 0;
}

void BFS() {
	queue<pair<int, int>> pQ;
	for (int i = 0; i < pV.size(); i++) {
		flag[pV[i].first][pV[i].second] = 1;
		pQ.push(make_pair(pV[i].first, pV[i].second));
	}
	while (!pQ.empty()) {
		pair<int, int> now = pQ.front();
		pQ.pop();
		int i = now.first;
		int j = now.second;
		for (int k = 0; k < 4; k++) {
			int ii = i + dy[k];
			int jj = j + dx[k];
			if (ii < 0 || ii >= n || jj < 0 || jj >= n ||
				map[ii][jj] == 1 || flag[ii][jj] > 0) continue;
			flag[ii][jj] = flag[i][j] + 1;
			pQ.push(make_pair(ii, jj));
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