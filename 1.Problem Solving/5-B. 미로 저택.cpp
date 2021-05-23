/*
문제 5-B
제목 미로 저택
내용
김인하는 거대한 미로 저택에 들어가게 되었다. 미로 저택은 M × N크기의
격자(grid) 형태로 복도 없이 모두 방으로 구성되어 있다. 미로 저택의 각 방
은 열린 방, 폐쇄된 방, 보안 카드가 놓여있는 방, 보안 장치로 잠긴 방 중
하나이다. 김인하는 자신을 기준으로 상하좌우 방향에 존재하는 방을 한 칸
씩 이동할 수 있다.(대각선 방향으로는 이동할 수 없다.) 단, 열린 방은 어느
방향에서나 자유롭게 이동할 수 있으며, 폐쇄된 방은 어느 방향에서도 방안
으로 이동할 수 없다. 어떤 방에는 하나의 보안 카드가 놓여 있으며, 보안 장
치로 잠긴 방은 특정 보안 카드가 있을 때에만 보안 장치를 해제하고 방 안
으로 이동이 가능하다. 보안 카드들에는 서로 다른 소문자 알파벳, 보안 장치
들에는 서로 다른 대문자 알파벳이 한 글자씩 적혀있다. 보안 장치로 잠긴
방 안으로 이동하기 위해서는 같은 알파벳의 보안 카드를 먼저 획득해야 한
다. 예를 들어, 보안 장치 “A”가 설치된 방은 보안 카드 “a”를 먼저 획득해
야 해제 및 이동이 가능하다.
 김인하는 미로 저택의 구조를 쉽게 파악할 수 있도록 미로 저택 지도를 미
리 만들어 두었다. 미로 저택 지도는 M × N 크기의 행렬로 구성되어 있으며,
김인하가 출발할 방을 “@”, 열린 방을 “*”, 폐쇄된 방을 “#”, 보안 카드가
있는 방을 소문자 알파벳(“a”~“f”), 보안 장치로 잠긴 방을 대문자 알파벳
(“A”~”F”) 기호로 표시했다(여기서, 보안 장치와 보안 카드 이름은 “A(a)”부
터 “F(f)”까지 최대 6개만 사용한다). 단, 김인하가 출발하는 방은 열린 방이
다.
 김인하는 미로 저택 지도를 보고 저택에 숨겨져 있는 모든 보안 카드를 획
득할 수 있는 최소 이동 횟수를 알고 싶다(단, 모든 보안 장치를 해제할 필요
는 없으며 보안 카드를 획득하는 순서는 상관하지 않는다.) 예를 들어 미로
저택과 미로 저택 지도가 위 그림과 같이 구성되어 있다고 하자. 이때, 김인
하는 위에 표시된 경로를 통해 8번을 이동함으로써 보안 카드(“a”, “b”)를 모
두 획득할 수 있다.
 M × N크기의 미로 저택 지도가 주어질 때, 김인하가 모든 보안 카드를 획
득할 수 있는 최소 이동 횟수를 출력하는 프로그램을 작성하시오. 단, 김인하
가 모든 보안 카드를 획득할 수 없는 경우에는 –1을 출력한다.
사용할 수 있는 언어는 C, C++로 제한한다. 프로그램의 실행 시간은 5초를
초과할 수 없다. C++의 경우 main 함수 내의 시작 지점에 다음 내용을 추가
함으로써 cin 입력 속도가 개선되는 경우도 있다.
std::ios::sync_with_stdio(false);
입력 형식
입력은 표준입력으로 다음과 같이 주어진다. 첫 줄에는 테스트케이스의 수
T (≤ 100)가 주어진다. 각 테스트케이스의 첫 번째 줄에는 미로 저택 지도의
행의 크기(2 ≤ M ≤ 20)와 열의 크기(2 ≤ N ≤ 20)가 공백을 하나 사이에 두
고 주어진다. 각 테스트케이스의 두 번째 줄부터 M + 1 번째 줄까지 미로 저
택 지도에 표시된 N개 방의 기호가 공백 하나를 사이에 두고 주어진다. 이
후에 T - 1개 테스트케이스도 같은 형식으로 주어진다.
출력 형식
출력은 표준출력으로 표시하며, 총 T줄로 구성된다. 각 테스트케이스 별로
모든 보안 카드를 획득할 수 있는 최소 이동 횟수를 출력한다. 만약, 모든 보
안 카드를 획득할 수 없는 경우에는 –1을 출력한다.
예
입력
4
3 5
@ * a * #
# B # * #
b * A * *
3 5
@ * * a A
* * B # *
* * * * b
2 4
@ A * a
* * # *
3 5
@ * * a B
* * A # *
* * * * b
(empty line)
출력
8
6
-1
8
(empty line)
*/

#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<queue>
using namespace std;

void BFS(int, int);
char map[20][20];
int flag[20][20];
int findCard[6], cardFlag[6];
int dy[4] = { 1,0,-1,0 }, dx[4] = { 0,1,0,-1 };
pair<int, int> start;
int m, n, cardNum, cnt, res;
bool isFinish;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	freopen("input.txt", "rt", stdin);
	int t;
	cin >> t;
	while (t--) {
		cin >> m >> n;
		fill(findCard, findCard + 6, 0);
		cardNum = 0;
		cnt = 0;
		res = 0;
		isFinish = false;
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				cin >> map[i][j];
				if (map[i][j] == '@') {
					start.first = i;
					start.second = j;
				}
				else if (map[i][j] >= 97 && map[i][j] <= 102) {
					cardNum++;
				}
			}
		}
		while (!isFinish) {
			for (int i = 0; i < m; i++) {
				for (int j = 0; j < n; j++) {
					flag[i][j] = 0;
				}
			}
			fill(cardFlag, cardFlag + cardNum, 0);
			BFS(start.first, start.second);
		}
		cout << (cnt == cardNum ? res : -1) << endl;
	}
	return 0;
}

void BFS(int y, int x) {
	queue<pair<int, int>> Q;
	flag[y][x] = 1;
	if (map[y][x] >= 97 && map[y][x] < 97 + cardNum) {
		cardFlag[map[y][x] - 97] = 1;
	}
	Q.push(make_pair(y, x));
	while (!Q.empty()) {
		pair<int, int> now = Q.front();
		Q.pop();
		int i = now.first;
		int j = now.second;
		for (int k = 0; k < 4; k++) {
			int ii = i + dy[k];
			int jj = j + dx[k];
			if (ii < 0 || ii >= m || jj < 0 || jj >= n ||
				flag[ii][jj] > 0 || map[ii][jj] == '#') continue;
			if (map[ii][jj] >= 97 && map[ii][jj] < 97 + cardNum) {
				if (findCard[map[ii][jj] - 97] == 0) {
					findCard[map[ii][jj] - 97] = 1;
					res += flag[i][j];
					cnt++;
					start.first = ii;
					start.second = jj;
					if (cnt == cardNum) isFinish = true;
					return;
				}
				else if(cardFlag[map[ii][jj] - 97] == 0){
					cardFlag[map[ii][jj] - 97] = 1;
					flag[ii][jj] = flag[i][j] + 1;
					Q.push(make_pair(ii, jj));
				}
			}
			else if (map[ii][jj] >= 65 && map[ii][jj] < 65 + cardNum) {
				if (cardFlag[map[ii][jj] - 65] == 1 || findCard[map[ii][jj] - 65] == 1) {
					flag[ii][jj] = flag[i][j] + 1;
					Q.push(make_pair(ii, jj));
				}
			}
			else {
				flag[ii][jj] = flag[i][j] + 1;
				Q.push(make_pair(ii, jj));
			}
		}
	}
	isFinish = true;
}

/*
모범 답안
	시간 복잡도
		O(MN)
	공간 복잡도
		O(MN)
*/