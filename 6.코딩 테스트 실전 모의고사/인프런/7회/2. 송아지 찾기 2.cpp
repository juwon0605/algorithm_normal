/*
2. 송아지 찾기 2
설명
현수는 송아지를 잃어버렸다. 다행히 송아지에는 위치추적기가 달려 있다.
현수의 위치와 송아지의 위치가 수직선상의 좌표 점으로 주어지면 현수는 현재 위치에서 송아지의 위치까지 다음과 같은 방법으로 이동한다.
송아지는 움직이지 않고 제자리에 있다.
현수는 스카이 콩콩을 타고 가는데 한 번의 점프로 앞으로 1, 뒤로 1, 앞으로 5를 이동할 수 있다.
단, 수직선 좌표 점중에 K개는 웅덩이여서 스카이 콩콩을 탈 수가 없다. 웅덩이를 피해서 최소 몇 번의 점프로
현수가 송아지의 위치까지 갈 수 있는지 구하는 프로그램을 작성하세요.
입력
첫 번째 줄에 현수의 위치 S와 송아지의 위치 E, 그리고 웅덩이의 개수 K(1<=K<=1,000)가 주어진다.
두 번째 줄에 K개의 웅덩이 좌표가 주어진다. 직선의 좌표 점은 1부터 10,000까지이다.
출력
점프의 최소횟수를 구한다. 답은 1이상입니다.
예시 입력 1
5 14 3
7 11 15
예시 출력 1
3
*/

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	freopen("input.txt", "rt", stdin);
	vector<int> map(10001);
	vector<int> flag(10001);
	queue<int> Q;
	int dx[3] = { 1,-1,5 };
	int s, e, k, num, res;
	cin >> s >> e >> k;
	for (int i = 0; i < k; i++) {
		cin >> num;
		map[num] = 1;
	}
	Q.push(s);
	flag[s] = 1;
	while (!Q.empty()) {
		int now = Q.front();
		Q.pop();
		for (int t = 0; t < 3; t++) {
			int next = now + dx[t];
			if (next == e) {
				cout << flag[now];
				return 0;
			}
			if (next <= 0 || next > 10000 ||
				map[next] == 1 || flag[next] > 0) continue;
			Q.push(next);
			flag[next] = flag[now] + 1;
		}
	}
	return 0;
}

/*
모범 답안
	시간복잡도
		O(N)
	공간복잡도
		O(N)
*/

/*
주의할 점

	송아지가 웅덩이에 있는 테스트케이스가 있어서
	BFS 탐색하면서 next == e를 확인해주어야한다!
*/