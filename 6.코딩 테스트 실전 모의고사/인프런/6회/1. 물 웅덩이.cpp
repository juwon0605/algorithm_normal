/*
1. 물 웅덩이
설명
여름 장마철!!! 철수의 학교에는 비가 억수같이 내렸다.
비가 멈추고 난 후 교장 선생님은 운동장을 둘러보았는데 여기 저기 물 웅덩이가 생겨 학생들이 쉬는 시간에 운동장에서
뛰어 놀지 못 할 것 같아 웅덩이를 흙으로 메우려고 한다.
우선 운동장에 물 웅덩이가 몇 개나 있는지 교장선생님은 알고 싶다.
여러분이 교장선생님을 도와 운동장에 물 웅덩이가 몇 개나 있는지 알아내는 프로그램을 작성하세요.
학교의 운동장은 R*C크기의 격자로 주어지며, 각 웅덩이는 #으로 표기하되 그 크기는 1개 아니면 상하좌우로 연결된 2개로 표현된다.
정상적인 곳은 ‘.’으로 표현된다.
입력
첫 줄에 정수 R(1<=R<=100)과 C(1<=C<=100)가 입력된다. 그 다음줄부터 R*C의 운동장 정보가 입력된다.
출력
웅덩이의 개수를 출력한다.
예시 입력 1
6 7
.#....#
..#...#
..#..#.
...##..
.#....#
.#..#.#
예시 출력 1
8
*/

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
using namespace std;

int map[101][101];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	freopen("input.txt", "rt", stdin);
	int r, c, cnt = 0;
	char ch;
	cin >> r >> c;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> ch;
			if (ch == '#') map[i][j] = 1;
		}
	}
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (map[i][j] == 1) {
				map[i][j] = 0;
				cnt++;
				map[i + 1][j] = 0;
				map[i][j + 1] = 0;
			}
		}
	}
	cout << cnt;
	return 0;
}

/*
모범 답안

	위에서 아래로, 왼쪽에서 오른쪽으로 하니씩 완전탐색하면,
	상, 하, 좌, 우 모두 볼 필요없이 우, 하 방향만 보면 됨!

	시간복잡도
		O(N^2)
	공간복잡도
		O(N^2)
*/

/*
모범 답안 반영 전

	시간복잡도
		O(N^2)
	공간복잡도
		O(N^2)

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	freopen("input.txt", "rt", stdin);
	int map[100][100];
	int dy[4] = { 1,0,-1,0 }, dx[4] = { 0,1,0,-1 };
	int r, c, cnt = 0;
	char ch;
	cin >> r >> c;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> ch;
			map[i][j] = (ch == '.' ? 0 : 1);
		}
	}
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (map[i][j] == 1) {
				map[i][j] = 0;
				cnt++;
				for (int k = 0; k < 4; k++) {
					int ii = i + dy[k];
					int jj = j + dx[k];
					if (ii < 0 || ii >= r || jj < 0 || jj >= c) continue;
					if (map[ii][jj] == 1) {
						map[ii][jj] = 0;
						break;
					}
				}
			}
		}
	}
	cout << cnt;
	return 0;
}
*/