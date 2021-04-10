/*
13. 백준 6593(상범 빌딩)
문제
당신은 상범 빌딩에 갇히고 말았다. 여기서 탈출하는 가장 빠른 길은 무엇일까? 상범 빌딩은 각 변의 길이가 1인 정육면체(단위 정육면체)로 이루어져있다. 각 정육면체는 금으로 이루어져 있어 지나갈 수 없거나, 비어있어서 지나갈 수 있게 되어있다. 당신은 각 칸에서 인접한 6개의 칸(동,서,남,북,상,하)으로 1분의 시간을 들여 이동할 수 있다. 즉, 대각선으로 이동하는 것은 불가능하다. 그리고 상범 빌딩의 바깥면도 모두 금으로 막혀있어 출구를 통해서만 탈출할 수 있다.
당신은 상범 빌딩을 탈출할 수 있을까? 만약 그렇다면 얼마나 걸릴까?
입력
입력은 여러 개의 테스트 케이스로 이루어지며, 각 테스트 케이스는 세 개의 정수 L, R, C로 시작한다. L(1 ≤ L ≤ 30)은 상범 빌딩의 층 수이다. R(1 ≤ R ≤ 30)과 C(1 ≤ C ≤ 30)는 상범 빌딩의 한 층의 행과 열의 개수를 나타낸다.
그 다음 각 줄이 C개의 문자로 이루어진 R개의 행이 L번 주어진다. 각 문자는 상범 빌딩의 한 칸을 나타낸다. 금으로 막혀있어 지나갈 수 없는 칸은 '#'으로 표현되고, 비어있는 칸은 '.'으로 표현된다. 당신의 시작 지점은 'S'로 표현되고, 탈출할 수 있는 출구는 'E'로 표현된다. 각 층 사이에는 빈 줄이 있으며, 입력의 끝은 L, R, C가 모두 0으로 표현된다. 시작 지점과 출구는 항상 하나만 있다.
출력
각 빌딩에 대해 한 줄씩 답을 출력한다. 만약 당신이 탈출할 수 있다면 다음과 같이 출력한다.
Escaped in x minute(s).
여기서 x는 상범 빌딩을 탈출하는 데에 필요한 최단 시간이다.
만일 탈출이 불가능하다면, 다음과 같이 출력한다.
Trapped!
예제 입력 1
3 4 5
S....
.###.
.##..
###.#

#####
#####
##.##
##...

#####
#####
#.###
####E

1 3 3
S##
#E#
###

0 0 0
예제 출력 1
Escaped in 11 minute(s).
Trapped!
출처
Contest > University of Ulm Local Contest > University of Ulm Local Contest 1997 D번
*/

#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<queue>
using namespace std;

struct Position
{
	int z;
	int y;
	int x;
	Position(){}
	Position(int a, int b, int c) {
		z = a;
		y = b;
		x = c;
	}
};
void BFS();
char map[30][30][30];
int flag[30][30][30];
int d[30][30][30];
int dz[2] = { 1, -1 }, dy[4] = { 1,0,-1,0 }, dx[4] = { 0,1,0,-1 };
Position s, e;
int l, r, c;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	freopen("input.txt", "rt", stdin);
	while (1) {
		cin >> l >> r >> c;
		if (l == 0 && r == 0 && c == 0) break;
		for (int z = 0; z < l; z++) {
			for (int y = 0; y < r; y++) {
				for (int x = 0; x < c; x++) {
					cin >> map[z][y][x];
					flag[z][y][x] = (map[z][y][x] == '#' ? 1 : 0);
					d[z][y][x] = 0;
					if (map[z][y][x] == 'S') {
						s.z = z;
						s.y = y;
						s.x = x;
					}
					else if (map[z][y][x] == 'E') {
						e.z = z;
						e.y = y;
						e.x = x;
					}
				}
			}
		}
		BFS();
		if (d[e.z][e.y][e.x] > 0) {
			cout << "Escaped in " << d[e.z][e.y][e.x] - 1 << " minute(s)." << endl;
		}
		else {
			cout << "Trapped!" << endl;
		}
	}
	return 0;
}

void BFS() {
	queue<Position> Q;
	flag[s.z][s.y][s.x] = 1;
	d[s.z][s.y][s.x] = 1;
	Q.push(Position(s.z, s.y, s.x));
	while (!Q.empty()) {
		Position now = Q.front();
		Q.pop();
		int z = now.z;
		int y = now.y;
		int x = now.x;
		for (int k = 0; k < 4; k++) {
			int yy = y + dy[k];
			int xx = x + dx[k];
			if (yy < 0 || yy >= r || xx < 0 || xx >= c) continue;
			if (flag[z][yy][xx] == 0) {
				flag[z][yy][xx] = 1;
				d[z][yy][xx] = 1 + d[z][y][x];
				Q.push(Position(z, yy, xx));
			}
		}
		for (int k = 0; k < 2; k++) {
			int zz = z + dz[k];
			if (zz < 0 || zz >= l) continue;
			if (flag[zz][y][x] == 0) {
				flag[zz][y][x] = 1;
				d[zz][y][x] = 1 + d[z][y][x];
				Q.push(Position(zz, y, x));
			}
		}
	}
}