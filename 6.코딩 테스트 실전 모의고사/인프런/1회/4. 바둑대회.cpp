/*
4. 바둑대회
설명
엘리트 기원은 팀전으로 치러지는 바둑대회를 참가할 예정이다. 이 대회는 총 N(짝수)명이 출전하며 흰 돌로 출전하는 선수 N/2명,
검은 돌로 출전하는 선수 N/2명 해서 총 N명이다.
한 선수는 흰돌의 선수로 나거든지, 아니면 검은 돌의 선수로 나가든지 해야만 한다. 한 선수가 둘 다 출전할 수 없다.
각 선수들의 흰돌로 했을 때 능력과 검은돌로 했을 때 능력이 주어지면 최상의 선택으로 흰 돌 N/2명, 검은 돌 N/2명,
총 N명의 선수를 뽑아야 한다. 여기서 최상의 선택이란 흰돌팀과 검은돌팀의 능력차가 최소가 되게 하는 것이다.
흰돌팀의 능력치는 흰돌팀 N/2명 선수들의 흰돌로 했을 때의 능력치의 총합니다. 검은돌팀의 능력치도 흰돌팀과 같은 방법입니다.
입력
첫 번째 줄에 참가하는 인원수 N(4<=N<=16)이 주어진다.
그 다음 줄부터 각 선수의 능력치가 주어진다. 각 줄의 첫 번째 숫자는 흰 돌로 했을 때 능력치이고,
두 번째 수는 검은 돌로 했을 때 능력치이다. 각 선수의 능력치는 100,000을 넘지 않는다.
출력
첫 번째 줄에 흰돌팀과 검은돌팀의 능력차의 최소를 출력한다.
예시 입력 1
6
87 84
66 78
94 94
93 87
72 92
78 63
예시 출력 1
2
*/

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>
using namespace std;

void DFS(int, int, int);

int statArr[2][16];
int flag[16];
int n, res = 2147000000;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	freopen("input.txt", "rt", stdin);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> statArr[0][i];
		cin >> statArr[1][i];
	}
	DFS(0, 0, 0);
	cout << res;
	return 0;
}

void DFS(int L, int white, int black) {
	if (L == n) {
		int sum1 = 0, sum2 = 0;
		for (int i = 0; i < n; i++) {
			if (flag[i] == 0) sum1 += statArr[0][i];
			else sum2 += statArr[1][i];
		}
		res = min(res, abs(sum1 - sum2));
	}
	else {
		if (white < n / 2) {
			flag[L] = 0;
			DFS(L + 1, white + 1, black);
		}
		if (black < n / 2) {
			flag[L] = 1;
			DFS(L + 1, white, black + 1);
		}
	}
}
/*
모범 답안
	시간복잡도
		O(2^N)
	공간복잡도
		O(N)
*/