/*
10. 백준15684(사다리 조작)
문제
사다리 게임은 N개의 세로선과 M개의 가로선으로 이루어져 있다. 인접한 세로선 사이에는 가로선을 놓을 수 있는데, 각각의 세로선마다 가로선을 놓을 수 있는 위치의 개수는 H이고, 모든 세로선이 같은 위치를 갖는다. 아래 그림은 N = 5, H = 6 인 경우의 그림이고, 가로선은 없다.


초록선은 세로선을 나타내고, 초록선과 점선이 교차하는 점은 가로선을 놓을 수 있는 점이다. 가로선은 인접한 두 세로선을 연결해야 한다. 단, 두 가로선이 연속하거나 서로 접하면 안 된다. 또, 가로선은 점선 위에 있어야 한다.


위의 그림에는 가로선이 총 5개 있다. 가로선은 위의 그림과 같이 인접한 두 세로선을 연결해야 하고, 가로선을 놓을 수 있는 위치를 연결해야 한다.
사다리 게임은 각각의 세로선마다 게임을 진행하고, 세로선의 가장 위에서부터 아래 방향으로 내려가야 한다. 이때, 가로선을 만나면 가로선을 이용해 옆 세로선으로 이동한 다음, 이동한 세로선에서 아래 방향으로 이동해야 한다.
위의 그림에서 1번은 3번으로, 2번은 2번으로, 3번은 5번으로, 4번은 1번으로, 5번은 4번으로 도착하게 된다. 아래 두 그림은 1번과 2번이 어떻게 이동했는지 나타내는 그림이다.

1번 세로선	2번 세로선

사다리에 가로선을 추가해서, 사다리 게임의 결과를 조작하려고 한다. 이때, i번 세로선의 결과가 i번이 나와야 한다. 그렇게 하기 위해서 추가해야 하는 가로선 개수의 최솟값을 구하는 프로그램을 작성하시오.
입력
첫째 줄에 세로선의 개수 N, 가로선의 개수 M, 세로선마다 가로선을 놓을 수 있는 위치의 개수 H가 주어진다. (2 ≤ N ≤ 10, 1 ≤ H ≤ 30, 0 ≤ M ≤ (N-1)×H)
둘째 줄부터 M개의 줄에는 가로선의 정보가 한 줄에 하나씩 주어진다.
가로선의 정보는 두 정수 a과 b로 나타낸다. (1 ≤ a ≤ H, 1 ≤ b ≤ N-1) b번 세로선과 b+1번 세로선을 a번 점선 위치에서 연결했다는 의미이다.
가장 위에 있는 점선의 번호는 1번이고, 아래로 내려갈 때마다 1이 증가한다. 세로선은 가장 왼쪽에 있는 것의 번호가 1번이고, 오른쪽으로 갈 때마다 1이 증가한다.
입력으로 주어지는 가로선이 서로 연속하는 경우는 없다.
출력
i번 세로선의 결과가 i번이 나오도록 사다리 게임을 조작하려면, 추가해야 하는 가로선 개수의 최솟값을 출력한다. 만약, 정답이 3보다 큰 값이면 -1을 출력한다. 또, 불가능한 경우에도 -1을 출력한다.
예제 입력 1
2 0 3
예제 출력 1
0
예제 입력 2
2 1 3
1 1
예제 출력 2
1
예제 입력 3
5 5 6
1 1
3 2
2 3
5 1
5 4
예제 출력 3
3
예제 입력 4
6 5 6
1 1
3 2
1 3
2 5
5 5
예제 출력 4
3
예제 입력 5
5 8 6
1 1
2 2
3 3
4 4
3 1
4 2
5 3
6 4
예제 출력 5
-1
예제 입력 6
5 12 6
1 1
1 3
2 2
2 4
3 1
3 3
4 2
4 4
5 1
5 3
6 2
6 4
예제 출력 6
-1
예제 입력 7
5 6 6
1 1
3 1
5 2
4 3
2 3
1 4
예제 출력 7
2
*/

#define _CRT_SECURE_NO_WARNINGS
#define INF 2147000000

#include<iostream>
#include<algorithm>
using namespace std;

int DFS(int, int);
bool valid();
int map[31][11];
int n, h, res = INF;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	freopen("input.txt", "rt", stdin);
	int m, a, b;
	cin >> n >> m >> h;
	if (m == 0) {
		cout << 0;
		return 0;
	}
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		map[a][b] = 1;
		map[a][b + 1] = 2;
	}
	res = DFS(0, 0);
	cout << (res != INF ? res : -1);
	return 0;
}

int DFS(int pos, int accum) {
	if (accum == 3 || pos >= n * h) {
		return (valid() ? accum : INF);
	}
	else {
		int left = INF;
		int right = INF;
		int i = pos / n + 1;
		int j = pos % n + 1;
		if (j != n && map[i][j] == 0 && map[i][j + 1] == 0) {
			map[i][j] = 1;
			map[i][j + 1] = 2;
			left = DFS(pos + 2, accum + 1);
			map[i][j] = 0;
			map[i][j + 1] = 0;
		}
		right = DFS(pos + 1, accum);
		return min(left, right);
	}
}

bool valid() {
	for (int i = 1; i <= n; i++) {
		int now = i;
		for (int j = 1; j <= h; j++) {
			if (map[j][now] == 1) {
				now += 1;
			}
			else if (map[j][now] == 2) {
				now -= 1;
			}
		}
		if (now != i) return false;
	}
	return true;
}

/*
모범 답안
	(팁)
	이차원 배열에서 DFS(int pos)를 구현할 때
	/과 %를 사용하여 i와 j를 나타낼 수 있다!
	(i = pos / n, j = pos % n)
*/

/*
모범 답안 반영 전

	예제는 풀리나 채점에서 시간 초과됨
	가로로 진행하는 과정에서 뒤에 세로 방향 연산들의 중복이 발생하여
	메모이제이션을 구현하려고 했으나 풀이의 틀린점을 발견함!

	가로로 진행하는 방향과 세로로 진행하는 방향을 나누어 생각해서 어려웠음
	진행 방향이 아니라 놓을 수 있는 자리를 기준으로
	놓냐/안놓냐를 DFS로 완전 탐색해서 문제 해결!

	아래는 다음 새로운 세로방향으로 진행할때 이미 지나간 가로방향을 다시 선택할 수 없어서
	모든 경우의 수를 탐색할 수 없으므로 잘못된 풀이!

#include<iostream>
using namespace std;

void DFS(int, int);
bool valid(int);
int save[31][11];
int map[31][11];
int n, h, m, res = 2147000000;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	freopen("input.txt", "rt", stdin);
	int a, b;
	cin >> n >> m >> h;
	if (m == 0) {
		cout << 0;
		return 0;
	}
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		map[a][b] = 1;
		map[a][b + 1] = 2;
	}
	DFS(1, 0);
	if (res > 3) {
		cout << -1;
		return 0;
	}
	cout << (res != 2147000000 ? res : -1);
	return 0;
}

void DFS(int b, int accum) {
	if (accum > 3) return;
	if (b == n) {
		for (int i = 1; i <= n; i++) {
			if (!valid(i)) return;
		}
		if (res > accum) res = accum;
	}
	else {
		for (int i = 1; i <= h; i++) {
			if (map[i][b] == 0 && map[i][b + 1] == 0) {
				map[i][b] = 1;
				map[i][b + 1] = 2;
				DFS(b + 1, accum + 1);
				map[i][b] = 0;
				map[i][b + 1] = 0;
				DFS(b + 1, accum);
			}
		}
	}
}

bool valid(int b) {
	int now = b;
	for (int i = 1; i <= h; i++) {
		if (map[i][now] == 1) {
			now += 1;
		}
		else if (map[i][now] == 2) {
			now -= 1;
		}
	}
	return (now == b ? true : false);
}
*/