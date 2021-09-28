/*
5. 톰과 제리(BFS)
설명
모두가 잘 알고 있듯이 톰과 제리는 별로 가까운 사이가 아니다. 항상 톰은 제리를 쫒아다녔지만 그때마다 번번이 실패하고 말았다.
곰곰이 꾀를 내던 톰은 제리가 자고 있을 때 가장 빠른 길로 잽싸게 달려가면 제리를 잡을 수 있겠다 싶었다.
그런데 그러기 위해서는 가장 적은 횟수로 방향을 바꾸어서 제리가 있는 곳까지 가는 방법을 알아야만 한다.
톰과 제리가 있는 정사각형 모양의 방의 상태와, 둘의 위치가 주어질 때 이와 같은 경로를 찾아내는 프로그램을 작성하세요.
Image1.jpg
입력
첫째 줄에 방의 너비를 나타내는 100이하의 자연수 n이 주어지고 다음 n줄에는 방의 상태가 입력된다.
지나갈 수 있는 위치는 0으로, 장애물이 있는 위치는 1로 표현된다. 다음 마지막 두 줄에는 톰의 위치와 제리의 위치가 주어진다.
각각의 위치는 행과 열 순이다.
출력
첫 줄에 방향을 바꾸는 회수를 출력한다. 만약 갈 수 있는 길이 하나도 없을 경우에는 -1를 출력한다.
예시 입력 1
10
0 0 0 0 0 0 0 0 0 0
0 1 1 0 0 0 0 1 1 1
0 1 1 0 1 1 0 0 0 0
0 1 1 0 0 1 0 1 1 0
0 0 0 0 0 1 1 1 0 0
0 1 0 0 0 0 0 0 0 0
0 1 1 1 1 0 0 0 1 1
0 1 0 0 0 0 0 0 0 0
0 0 0 0 0 1 1 1 0 0
0 1 1 1 1 0 0 0 0 0
1 1
10 9
예시 출력 1
4
*/

#define _CRT_SECURE_NO_WARNINGS
#define INF 2147000000

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Position {
	int i;
	int j;
	int direction; // 상: 0, 우: 1, 하: 2, 좌: 3
	Position() {};
	Position(int a, int b, int c) {
		i = a;
		j = b;
		direction = c;
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	freopen("input.txt", "rt", stdin);
	queue<Position> pQ;
	pair<int, int> start, end;
	int dy[4] = { 1,0,-1,0 }, dx[4] = { 0,1,0,-1 };
	int n, y, x, res = INF;
	cin >> n;
	vector<vector<int>> map(n, vector<int>(n));
	vector<vector<vector<int>>> flag(n, vector<vector<int>>(n, vector<int>(4, INF)));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
		}
	}
	cin >> y >> x;
	start.first = y - 1;
	start.second = x - 1;
	cin >> y >> x;
	end.first = y - 1;
	end.second = x - 1;
	for (int i = 0; i < 4; i++) {
		flag[start.first][start.second][i] = 1; // res - 1 주의
		pQ.push(Position(start.first, start.second, i));
	}
	while (!pQ.empty()) {
		Position now = pQ.front();
		pQ.pop();
		int i = now.i;
		int j = now.j;
		int direction = now.direction;
		for (int k = 0; k < 4; k++) {
			int ii = i + dy[k];
			int jj = j + dx[k];
			if (ii < 0 || ii >= n || jj < 0 || jj >= n ||
				map[ii][jj] == 1) continue;
			int distance = (direction == k ? flag[i][j][direction] : flag[i][j][direction] + 1);
			if (flag[ii][jj][k] > distance) {
				flag[ii][jj][k] = distance;
				pQ.push(Position(ii, jj, k));
			}
		}
	}
	for (int i = 0; i < 4; i++) {
		if (flag[end.first][end.second][i] != INF) {
			if (res > flag[end.first][end.second][i]) res = flag[end.first][end.second][i];
		}
	}
	cout << (res != INF ? res - 1 : -1);
	//log
	/*
	cout << "\n";
	for (int k = 0; k < 4; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cout << flag[i][j][k] << " ";
			}
			cout << "\n";
		}
		cout << "\n";
	}
	*/
	return 0;
}

/*
모범 답안
	시간복잡도
		O(N^2)
	공간복잡도
		O(N^2)
*/