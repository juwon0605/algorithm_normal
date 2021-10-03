/*
5. 팀 만들기
설명
현수는 바둑팀 감독입니다. 현수의 팀에는 바둑선수가 9명 있습니다.
현수는 대회에 출전하기 위해 9명의 선수를 3명씩 3개의 팀으로 만들어서 대회에 출전하려고 합니다.
9명의 바둑선수는 각각 정수로 표현되는 바둑실력을 가지고 있습니다.
현수가 최상의 팀을 만드는 방법은 9명을 3팀으로 만들었을 때 가장 실력이 높은 팀과 가장 실력이 낮은 팀의 실력차가 가장 작도록 해야 합니다.
각 팀의 실력은 해당 팀의 선수들의 실력을 모두 합한 값입니다.
9명의 바둑실력이 주어지면 현수가 최상의 팀을 만들었을 때 가장 실력이 높은 팀과 가장 낮은 팀의 실력차를 출력하는 프로그램을 작성하세요.
입력
첫 번째 줄에 9명의 실력(1~100)이 정수로 주어집니다.
출력
첫 번째 줄에 가장 실력이 높은 팀과 가장 실력이 낮은 팀의 실력차를 출력합니다.
예시 입력 1
1 2 3 4 5 6 7 8 9
예시 출력 1
0
힌트
출력설명
(1, 6, 8), (2, 4, 9), (3, 5, 7) 실력을 갖은 선수들로 3팀을 만들면 3팀 모두 팀실력이 15로 동일하다.
*/

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

void DFS(int, int, int, int);
int flag[9];
int statArr[9];
int res = 2147000000;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	freopen("input.txt", "rt", stdin);
	for (int i = 0; i < 10; i++) {
		cin >> statArr[i];
	}
	DFS(0, 0, 0, 0);
	cout << res;
	return 0;
}

void DFS(int L, int team1, int team2, int team3) {
	if (L == 9) {
		int sum1 = 0, sum2 = 0, sum3 = 0;
		for (int i = 0; i < 9; i++) {
			if (flag[i] == 1) sum1 += statArr[i];
			else if (flag[i] == 2) sum2 += statArr[i];
			else sum3 += statArr[i];
		}
		int maxSum = max(sum1, max(sum2, sum3));
		int minSum = min(sum1, min(sum2, sum3));
		res = min(res, maxSum - minSum);
	}
	else {
		if (team1 < 3) {
			flag[L] = 1;
			DFS(L + 1, team1 + 1, team2, team3);
		}
		if (team2 < 3) {
			flag[L] = 2;
			DFS(L + 1, team1, team2 + 1, team3);
		}
		if (team3 < 3) {
			flag[L] = 3;
			DFS(L + 1, team1, team2, team3 + 1);
		}
	}
}

/*
모범 답안
	시간복잡도
		O(1) (9C3 * 6C3 * 3C3)
	공간복잡도
		O(1) (9)
*/