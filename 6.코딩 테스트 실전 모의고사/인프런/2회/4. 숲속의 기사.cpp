/*
4. 숲속의 기사
설명
영희는 궁전에 살고 있는데, 굉장히 곤란한 상황에 맞닥뜨리게 됐다. 그녀는 숲속이 기사가 지키고 서 있는 숲을 통과해 나가야 한다.
이 숲을 안전하게 통과하기 위해서 그녀는 기사에게 산딸기를 가져다 줘야 한다. 시간이 촉박하기 때문에 영희는 최대한 빨리 산딸기를 기사에게 가져다 줘야 한다.
영희는 이 숲의 지도를 갖고 있다. 이 숲은 W x H의 판 형태의 크기로 되어 있다.(1<=W<=1000; 1<=H<=1000)
이 지도에는 영희가 시작하는 위치, 기사가 서 있는 위치, 산딸기가 존재하는 위치 등이 표시되어 있다. 또한 영희가 가지 못하는 위치도 표시되어 있다.
영희는 산딸기가 없이는 기사를 지나쳐 갈 수 없다.
영희는 동,서,남,북 4방향으로만 움직일 수 있고, 하루에 한칸 씩 움직일 수 있다
영희는 항상 산딸기를 기사에게 가져다 줄 수 있다.
입력
Line 1: W and H.가 입력으로 들어온다
Lines 2~?: 지도을 표현하는 입력이 들어온다. 지도의 북서쪽 방향에서 시작해서 지도의 동서쪽 방향까지 지도가 그려져 있다.
지도의 각 숫자는 다음과 같은 의미를 갖고 있다.
0: 영희가 움직일 수 있는 곳을 뜻한다.
1: 영희가 움직일 수 없는 곳을 말한다.
2: 영희의 시작 위치를 뜻한다.
3: 숲속이 기사의 위치를 뜻한다.(반드시 하나만 존재한다)
4: 산딸기의 위치를 뜻한다.
출력
첫 줄에영희가 산딸기를 기사에게 가져다주는 가장 짧은 날 수를 출력하면 된다
예시 입력 1
8 4
4 1 0 0 0 0 1 0
0 0 0 1 0 1 0 0
0 2 1 1 3 0 4 0
0 0 0 4 1 1 1 0
예시 출력 1
11
*/

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void BFS(int, vector<vector<int>>&, vector<vector<vector<int>>>&);
vector<pair<int, int>> pV(2);
int dy[4] = { 1,0,-1,0 }, dx[4] = { 0,1,0,-1 };
int w, h, res = 2147000000;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	freopen("input.txt", "rt", stdin);
	vector<pair<int, int>> berryV;
	int num;
	cin >> w >> h;
	vector<vector<int>> map(h, vector<int>(w));
	vector<vector<vector<int>>> flag(h, vector<vector<int>>(w, vector<int>(2)));
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			cin >> num;
			map[i][j] = num;
			if (num == 2) {
				pV[0].first = i;
				pV[0].second = j;
			}
			else if (num == 3) {
				pV[1].first = i;
				pV[1].second = j;
			}
			else if (num == 4) {
				berryV.push_back(make_pair(i, j));
			}
		}
	}
	for (int i = 0; i < 2; i++) {
		BFS(i, map, flag);
	}
	for (int i = 0; i < berryV.size(); i++) {
		int startToBerry = flag[berryV[i].first][berryV[i].second][0];
		int endToBerry = flag[berryV[i].first][berryV[i].second][1];
		if (startToBerry != 0 && endToBerry != 0) {
			if (res > startToBerry + endToBerry) res = startToBerry + endToBerry;
		}
	}
	cout << res - 2;
	return 0;
}

void BFS(int state, vector<vector<int>> &map, vector<vector<vector<int>>> &flag) {
	queue<pair<int, int>> pQ;
	flag[pV[state].first][pV[state].second][state] = 1;
	pQ.push(pV[state]);
	while (!pQ.empty()) {
		pair<int, int> now = pQ.front();
		pQ.pop();
		int i = now.first;
		int j = now.second;
		for (int k = 0; k < 4; k++) {
			int ii = i + dy[k];
			int jj = j + dx[k];
			if (ii < 0 || ii >= h || jj < 0 || jj >= w ||
				map[ii][jj] == 1 || flag[ii][jj][state] > 0) continue;
			flag[ii][jj][state] = flag[i][j][state] + 1;
			pQ.push(make_pair(ii, jj));
		}
	}
}

/*
모범 답안

	3차원 BFS라도 무조건 특정 지점을 지나야할 경우,
	시작 지점부터 그 지점까지의 BFS와 도착 지점부터 그 지점까지의 BFS
	총 2번의 BFS와 메모리로 표현할 수 있다!

	시간복잡도
		O(WH)
	공간복잡도
		O(WH)
*/

/*
모범 답안 반영 전1

	메모리 초과

	시간복잡도
		O(WHK) (K는 산딸기의 개수)
	공간복잡도
		O(WHK) (K는 산딸기의 개수)

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Position {
	int i;
	int j;
	int z;
	Position() {};
	Position(int a, int b, int c) {
		i = a;
		j = b;
		z = c;
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	freopen("input.txt", "rt", stdin);
	vector<pair<int, int>> berryV;
	Position startP, endP;
	int dy[4] = { 1,0,-1,0 }, dx[4] = { 0,1,0,-1 };
	int w, h, num, res = 2147000000;
	cin >> w >> h;
	vector<vector<int>> map(h, vector<int>(w));
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			cin >> num;
			map[i][j] = num;
			if (num == 2) {
				startP.i = i;
				startP.j = j;
				startP.z = 0;
			}
			else if (num == 3) {
				endP.i = i;
				endP.j = j;
				startP.z = 0;
			}
			else if (num == 4) {
				berryV.push_back(make_pair(i, j));
			}
		}
	}
	//log
	cout << berryV.size();
	vector<vector<vector<int>>> flag(h, vector<vector<int>>(w, vector<int>(berryV.size() + 1)));
	queue<Position> pQ;
	flag[startP.i][startP.j][startP.z] = 1; // res - 1 출력 주의
	pQ.push(startP);
	while (!pQ.empty()) {
		Position now = pQ.front();
		pQ.pop();
		int i = now.i;
		int j = now.j;
		int z = now.z;
		for (int k = 0; k < 4; k++) {
			int ii = i + dy[k];
			int jj = j + dx[k];
			if (ii < 0 || ii >= h || jj < 0 || jj >= w ||
				map[ii][jj] == 1 || flag[ii][jj][z] > 0 ||
				(map[ii][jj] == 3 && z == 0)) continue;
			if (map[ii][jj] == 4 && z == 0) {
				for (int t = 0; t < berryV.size(); t++) {
					if (berryV[t].first == ii && berryV[t].second == jj) {
						flag[ii][jj][t + 1] = flag[i][j][z] + 1;
						pQ.push(Position(ii, jj, t + 1));
						break;
					}
				}
			}
			else {
				flag[ii][jj][z] = flag[i][j][z] + 1;
				pQ.push(Position(ii, jj, z));
			}
		}
	}
	for (int i = 0; i < berryV.size(); i++) {
		if (flag[endP.i][endP.j][i + 1] != 0 && res > flag[endP.i][endP.j][i + 1]) res = flag[endP.i][endP.j][i + 1];
	}
	cout << res - 1;
	return 0;
}
*/

/*
모범 답안 반영 전2

	시간 초과

	시간복잡도
		O(WHK) (K는 산딸기의 개수)
	공간복잡도
		O(WH)

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Position {
	int i;
	int j;
	int z;
	Position() {};
	Position(int a, int b, int c) {
		i = a;
		j = b;
		z = c;
	}
};

void BFS(int, int, vector<vector<int>>&, vector<vector<vector<int>>>&);
Position startP, endP;
int dy[4] = { 1,0,-1,0 }, dx[4] = { 0,1,0,-1 };
int w, h, res = 2147000000;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	freopen("input.txt", "rt", stdin);
	vector<pair<int, int>> berryV;
	int num;
	cin >> w >> h;
	vector<vector<int>> map(h, vector<int>(w));
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			cin >> num;
			map[i][j] = num;
			if (num == 2) {
				startP.i = i;
				startP.j = j;
				startP.z = 0;
			}
			else if (num == 3) {
				endP.i = i;
				endP.j = j;
				endP.z = 0;
			}
			else if (num == 4) {
				berryV.push_back(make_pair(i, j));
			}
		}
	}
	for (int i = 0; i < berryV.size(); i++) {
		vector<vector<vector<int>>> flag(h, vector<vector<int>>(w, vector<int>(2)));
		BFS(berryV[i].first, berryV[i].second, map, flag);
	}
	cout << res - 1;
	return 0;
}

void BFS(int berryI, int berryJ, vector<vector<int>> &map, vector<vector<vector<int>>> &flag) {
	queue<Position> pQ;
	flag[startP.i][startP.j][startP.z] = 1; // res - 1 출력 주의
	pQ.push(startP);
	while (!pQ.empty()) {
		Position now = pQ.front();
		pQ.pop();
		int i = now.i;
		int j = now.j;
		int z = now.z;
		for (int k = 0; k < 4; k++) {
			int ii = i + dy[k];
			int jj = j + dx[k];
			if (ii < 0 || ii >= h || jj < 0 || jj >= w ||
				map[ii][jj] == 1 || flag[ii][jj][z] > 0 ||
				(map[ii][jj] == 3 && z == 0)) continue;
			if (map[ii][jj] == 4 && z == 0 && ii == berryI && jj == berryJ) {
				flag[ii][jj][1] = flag[i][j][z] + 1;
				pQ.push(Position(ii, jj, 1));
			}
			else {
				flag[ii][jj][z] = flag[i][j][z] + 1;
				if (ii == endP.i && jj == endP.j && z == 1) {
					if (flag[endP.i][endP.j][1] != 0 && res > flag[endP.i][endP.j][1]) res = flag[endP.i][endP.j][1];
					return;
				}
				pQ.push(Position(ii, jj, z));
			}
		}
	}
}
*/