/*
6. 백준 2580(스도쿠)
스도쿠는 18세기 스위스 수학자가 만든 '라틴 사각형'이랑 퍼즐에서 유래한 것으로 현재 많은 인기를 누리고 있다. 이 게임은 아래 그림과 같이 가로, 세로 각각 9개씩 총 81개의 작은 칸으로 이루어진 정사각형 판 위에서 이뤄지는데, 게임 시작 전 일부 칸에는 1부터 9까지의 숫자 중 하나가 쓰여 있다.


나머지 빈 칸을 채우는 방식은 다음과 같다.
1.각각의 가로줄과 세로줄에는 1부터 9까지의 숫자가 한 번씩만 나타나야 한다.
2.굵은 선으로 구분되어 있는 3x3 정사각형 안에도 1부터 9까지의 숫자가 한 번씩만 나타나야 한다.
위의 예의 경우, 첫째 줄에는 1을 제외한 나머지 2부터 9까지의 숫자들이 이미 나타나 있으므로 첫째 줄 빈칸에는 1이 들어가야 한다.


또한 위쪽 가운데 위치한 3x3 정사각형의 경우에는 3을 제외한 나머지 숫자들이 이미 쓰여있으므로 가운데 빈 칸에는 3이 들어가야 한다.


이와 같이 빈 칸을 차례로 채워 가면 다음과 같은 최종 결과를 얻을 수 있다.


게임 시작 전 스도쿠 판에 쓰여 있는 숫자들의 정보가 주어질 때 모든 빈 칸이 채워진 최종 모습을 출력하는 프로그램을 작성하시오.
입력
아홉 줄에 걸쳐 한 줄에 9개씩 게임 시작 전 스도쿠판 각 줄에 쓰여 있는 숫자가 한 칸씩 띄워서 차례로 주어진다. 스도쿠 판의 빈 칸의 경우에는 0이 주어진다. 스도쿠 판을 규칙대로 채울 수 없는 경우의 입력은 주어지지 않는다.
출력
모든 빈 칸이 채워진 스도쿠 판의 최종 모습을 아홉 줄에 걸쳐 한 줄에 9개씩 한 칸씩 띄워서 출력한다.
스도쿠 판을 채우는 방법이 여럿인 경우는 그 중 하나만을 출력한다.
제한
baekjoon의 백트래킹 알고리즘으로 풀 수 있는 입력만 주어진다. 다음은 그 알고리즘의 수행 시간이다.
C++14: 80ms
Java: 292ms
PyPy3: 1172ms
예제 입력 1
0 3 5 4 6 9 2 7 8
7 8 2 1 0 5 6 0 9
0 6 0 2 7 8 1 3 5
3 2 1 0 4 6 8 9 7
8 0 4 9 1 3 5 0 6
5 9 6 8 2 0 4 1 3
9 1 7 6 5 2 0 8 0
6 0 3 7 0 1 9 5 2
2 5 8 3 9 4 7 6 0
예제 출력 1
1 3 5 4 6 9 2 7 8
7 8 2 1 3 5 6 4 9
4 6 9 2 7 8 1 3 5
3 2 1 5 4 6 8 9 7
8 7 4 9 1 3 5 2 6
5 9 6 8 2 7 4 1 3
9 1 7 6 5 2 3 8 4
6 4 3 7 8 1 9 5 2
2 5 8 3 9 4 7 6 1
출처
Olympiad > 한국정보올림피아드 > 한국정보올림피아드시․도지역본선 > 지역본선 2006 > 초등부 5번
Olympiad > 한국정보올림피아드 > 한국정보올림피아드시․도지역본선 > 지역본선 2006 > 중등부 3번
*/

#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<vector>
using namespace std;

void DFS(int L);
bool valid(int i, int j, int k);
vector<pair<int, int>> zeroV;
int map[9][9];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	freopen("input.txt", "rt", stdin);
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cin >> map[i][j];
			if (map[i][j] == 0) zeroV.push_back(make_pair(i, j));
		}
	}
	DFS(0);
}

bool valid(int a, int b, int k) {
	for (int i = 0; i < 9; i++) {
		if (map[a][i] == k) return false;
		if (map[i][b] == k) return false;
	}
	for (int ii = (a / 3) * 3; ii < (a / 3) * 3 + 3; ii++) {
		for (int jj = (b / 3) * 3; jj < (b / 3) * 3 + 3; jj++) {
			if (map[ii][jj] == k) return false;
		}
	}
	return true;
}

void DFS(int L) {
	if (L == zeroV.size()) {
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				cout << map[i][j] << " ";
			}
			cout << endl;
		}
		exit(0);
	}
	else {
		int i = zeroV[L].first;
		int j = zeroV[L].second;
		for (int k = 1; k <= 9; k++) {
			if (valid(i, j, k)) {
				map[i][j] = k;
				DFS(L + 1);
				map[i][j] = 0;
			}
		}
	}
}

/*
모범 답안
	DFS로 앞에서부터 하나씩 1~9를 순열로 넣어보며 확인!
	만약 잘못 되었을 경우에는 L를 올라가서 다시 진행
	(백트래킹 알고리즘)

	(주의사항)
	DFS에서 L==n에 도달하여도 순열은 계속 진행됨!
	따라서 최초로 도달했을때 cout하고 exit(0)을 해야함!
*/

/*
모범 답안 반영 전
	바로 혹은 몇 번 뒤에 풀 수 있는 경우는 BFS로 풀게 구현했는데,
	숫자를 선택해서 정답을 만들어야하는 경우를 해결하지 못함!
	(아래 코드는 무한루프 발생)

#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<queue>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	freopen("input.txt", "rt", stdin);
	queue<pair<int, int>> zeroQ;
	int map[9][9];
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cin >> map[i][j];
			if (map[i][j] == 0) zeroQ.push(make_pair(i, j));
		}
	}
	while (!zeroQ.empty()) {
		pair<int, int> now = zeroQ.front();
		zeroQ.pop();
		int check[10] = { 0 };
		int cnt = 0;
		int i = now.first;
		int j = now.second;
		//1.가로 check
		for (int jj = 0; jj < 9; jj++) {
			if (map[i][jj] > 0) {
				cnt++;
				check[map[i][jj]]++;
			}
		}
		if (cnt == 8) {
			for (int k = 1; k <= 9; k++) {
				if (check[k] == 0) {
					map[i][j] = k;
				}
			}
			continue;
		}
		//2.세로 check
		fill(check, check + 10, 0);
		cnt = 0;
		for (int ii = 0; ii < 9; ii++) {
			if (map[ii][j] > 0) {
				cnt++;
				check[map[ii][j]]++;
			}
		}
		if (cnt == 8) {
			for (int k = 1; k <= 9; k++) {
				if (check[k] == 0) {
					map[i][j] = k;
				}
			}
			continue;
		}
		//3.정사각형 check
		fill(check, check + 10, 0);
		cnt = 0;
		for (int ii = (i / 3) * 3; ii < (i / 3) * 3 + 3; ii++) {
			for (int jj = (j / 3) * 3; jj < (j / 3) * 3 + 3; jj++) {
				if (map[ii][jj] > 0) {
					cnt++;
					check[map[ii][jj]]++;
				}
			}
		}
		if (cnt == 8) {
			for (int k = 1; k <= 9; k++) {
				if (check[k] == 0) {
					map[i][j] = k;
				}
			}
			continue;
		}
		//4.나중에 다시 탐색
		zeroQ.push(make_pair(i, j));
	}
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cout << map[i][j] << " ";
		}
		cout << "\n";
	}
	return 0;
}
*/