/*
01. 백준 14503번(로봇 청소기)
문제
로봇 청소기가 주어졌을 때, 청소하는 영역의 개수를 구하는 프로그램을 작성하시오.
로봇 청소기가 있는 장소는 N×M 크기의 직사각형으로 나타낼 수 있으며, 1×1크기의 정사각형 칸으로 나누어져 있다. 각각의 칸은 벽 또는 빈 칸이다. 청소기는 바라보는 방향이 있으며, 이 방향은 동, 서, 남, 북중 하나이다. 지도의 각 칸은 (r, c)로 나타낼 수 있고, r은 북쪽으로부터 떨어진 칸의 개수, c는 서쪽으로 부터 떨어진 칸의 개수이다.
로봇 청소기는 다음과 같이 작동한다.
현재 위치를 청소한다.
현재 위치에서 현재 방향을 기준으로 왼쪽 방향부터 차례대로 인접한 칸을 탐색한다.
왼쪽 방향에 아직 청소하지 않은 공간이 존재한다면, 그 방향으로 회전한 다음 한 칸을 전진하고 1번부터 진행한다.
왼쪽 방향에 청소할 공간이 없다면, 그 방향으로 회전하고 2번으로 돌아간다.
네 방향 모두 청소가 이미 되어있거나 벽인 경우에는, 바라보는 방향을 유지한 채로 한 칸 후진을 하고 2번으로 돌아간다.
네 방향 모두 청소가 이미 되어있거나 벽이면서, 뒤쪽 방향이 벽이라 후진도 할 수 없는 경우에는 작동을 멈춘다.
로봇 청소기는 이미 청소되어있는 칸을 또 청소하지 않으며, 벽을 통과할 수 없다.
입력
첫째 줄에 세로 크기 N과 가로 크기 M이 주어진다. (3 ≤ N, M ≤ 50)
둘째 줄에 로봇 청소기가 있는 칸의 좌표 (r, c)와 바라보는 방향 d가 주어진다. d가 0인 경우에는 북쪽을, 1인 경우에는 동쪽을, 2인 경우에는 남쪽을, 3인 경우에는 서쪽을 바라보고 있는 것이다.
셋째 줄부터 N개의 줄에 장소의 상태가 북쪽부터 남쪽 순서대로, 각 줄은 서쪽부터 동쪽 순서대로 주어진다. 빈 칸은 0, 벽은 1로 주어진다. 지도의 첫 행, 마지막 행, 첫 열, 마지막 열에 있는 모든 칸은 벽이다.
로봇 청소기가 있는 칸의 상태는 항상 빈 칸이다.
출력
로봇 청소기가 청소하는 칸의 개수를 출력한다.
예제 입력 1
3 3
1 1 0
1 1 1
1 0 1
1 1 1
예제 출력 1
1
예제 입력 2
11 10
7 4 0
1 1 1 1 1 1 1 1 1 1
1 0 0 0 0 0 0 0 0 1
1 0 0 0 1 1 1 1 0 1
1 0 0 1 1 0 0 0 0 1
1 0 1 1 0 0 0 0 0 1
1 0 0 0 0 0 0 0 0 1
1 0 0 0 0 0 0 1 0 1
1 0 0 0 0 0 1 1 0 1
1 0 0 0 0 0 1 1 0 1
1 0 0 0 0 0 0 0 0 1
1 1 1 1 1 1 1 1 1 1
예제 출력 2
57
*/

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <queue>
using namespace std;

struct Info {
	int i;
	int j;
	int d;
	Info(int a, int b, int c) {
		i = a;
		j = b;
		d = c;
	}
};

void BFS(int, int, int);

int map[50][50];
int dy[4] = { -1,0,1,0 }, dx[4] = { 0,-1,0,1 }; // 반시계방향
int n, m, res;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	freopen("input.txt", "rt", stdin);
	int a, b, c;
	cin >> n >> m >> a >> b >> c;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}
	BFS(a, b, c);
	cout << res;
	return 0;
}

void BFS(int a, int b, int c) {
	queue<Info> infoQ;
	infoQ.push(Info(a, b, c));
	while (!infoQ.empty()) {
		int i = infoQ.front().i;
		int j = infoQ.front().j;
		int d = infoQ.front().d;
		infoQ.pop();
		if (map[i][j] == 0) {
			map[i][j] = 2;
			res++;
		}
		bool isBreak = false;
		for (int k = 1; k <= 4; k++) {
			int s = (d % 2 == 0 ? d : (d + 2) % 4); //시계방향->반시계방향
			int ii = i + dy[(s + k) % 4];
			int jj = j + dx[(s + k) % 4];
			if (map[ii][jj] == 0) {
				int nowD = (s + k) % 4;
				int dd = (nowD % 2 == 0 ? nowD : (nowD + 2) % 4); //반시계방향->시계방향
				infoQ.push(Info(ii, jj, dd));
				isBreak = true;
				break;
			}
		}
		if (!isBreak) {
			//후진
			int s = (d % 2 == 0 ? d : (d + 2) % 4); //시계방향->반시계방향
			int ii = i + dy[(s + 2) % 4];
			int jj = j + dx[(s + 2) % 4];
			if (map[ii][jj] != 1) {
				infoQ.push(Info(ii, jj, d));
			}
			//후진도 할 수 없는 경우 return;
			else {
				return;
			}
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