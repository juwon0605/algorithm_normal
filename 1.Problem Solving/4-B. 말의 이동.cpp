/*
문제 4-B
제목 말의 이동
내용
장기판 위에 한 개의 말이 놓여 있다. 말이 아래의 그림과 같이 크기가 7×7
(격자점 기준)인 장기판의 중앙에 놓여 있을 때, 장기판의 범위를 넘어가지
않는다는 조건 하에, 말이 1번 이동하여 도착할 수 있는 장소는 아래와 같이
빨강색으로 표시된 8곳이 존재한다. 즉 현재 말의 위치를 (x, y)라고 한다면
말이 1번 움직여서 갈 수 있는 위치는 (x+2, y+1), (x+2, y-1),
(x-2, y+1) , (x-2, y-1) , (x+1, y+2), (x+1, y-2) , (x-1, y+2) ,
(x-1, y-2) 이렇게 총 8가지가 존재한다. 말의 현재 위치와 최종적으로 도
착하려고 하는 위치 D가 좌표로 주어질 때, 말이 최소한 몇 번 움직여야 D
에 도착할 수 있는지 알고 싶다. 단, 말은 장기판 밖으로 벗어날 수 없으며,
장기판 위에는 말 하나만 존재한다. 또한 말이 목적지에 도착하지 못하는 경
우는 없다.
사용 할 수 있는 언어는 C, C++로 제한한다. 프로그램의 실행시간은 1초를
초과할 수 없다. C++의 경우 main 함수 내의 시작 지점에 다음 내용을 추
가하면 cin입력 속도가 개선되는 경우도 있다.
std::ios::sync_with_stdio(false);
입력 형식
입력은 표준입력으로 다음과 같이 주어진다.
1. 첫 번째 줄에는 테스트케이스의 수 T가 주어진다. (1 ≤ T ≤ 100)
2. 두 번째 줄에는 첫 번째 테스트케이스에 대한 장기판의 크기 L
(5 ≤ L ≤ 500)이 주어진다. 장기판의 크기는 L ×L이다.
3. 세 번째 줄에는 말의 현재 좌표를 나타내는 두 정수 x와 y
(0 ≤ x,y ≤ L - 1)가 공백 한 칸을 사이에 두고 주어진다.
4. 네 번째 줄에는 말이 최종적으로 도착할 좌표를 나타내는 두 정수 x와 y
(0 ≤ x,y ≤ L - 1)가 공백 한 칸을 사이에 두고 주어진다.
5. 그 이후에 각 테스트케이스마다 위의 2, 3, 4단계가 T-1번 반복된다.
출력 형식
출력은 표준출력으로 수행하며 총 T줄로 이루어진다. 각 줄에는 각 테스트
케이스 별로 말이 목적지에 도착하기 위해 필요한 최소 횟수를 출력한다.
예
입력
4
5
1 0
4 4
8
0 0
7 0
100
0 0
30 50
10
1 1
1 1
(empty line)
출력
3
5
28
0
(empty line)
*/

#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	freopen("input.txt", "rt", stdin);
	int dx[8] = { 1, 2, 2, 1, -1, -2, -2, -1 }, dy[8] = { 2, 1, -1, -2, -2, -1, 1, 2 };
	int t, l, x, y;
	cin >> t;
	while (t--) {
		cin >> l;
		vector<vector<int>> map(l, vector<int>(l));
		cin >> x >> y;
		queue<pair<int, int>> Q;
		Q.push(make_pair(x,y));
		cin >> x >> y;
		map[x][y] = -1;
		if (Q.front().first == x && Q.front().second == y) {
			cout << 0 << endl;
			continue;
		}
		while (!Q.empty()) {
			pair<int, int> now = Q.front();
			Q.pop();
			int i = now.first;
			int j = now.second;
			for (int k = 0; k < 8; k++) {
				int ii = i + dx[k];
				int jj = j + dy[k];
				if (ii < 0 || ii >= l || jj < 0 || jj >= l) continue;
				if (map[ii][jj] == -1) {
					cout << map[i][j] + 1 << endl;
					while (!Q.empty()) Q.pop();
					break;
				}
				else if (map[ii][jj] == 0) {
					map[ii][jj] = map[i][j] + 1;
					Q.push(make_pair(ii, jj));
				}
			}
		}
	}
	return 0;
}

/*
모범 답안
	시간 복잡도
		O(TL^2)
	공간 복잡도
		O(L)
*/