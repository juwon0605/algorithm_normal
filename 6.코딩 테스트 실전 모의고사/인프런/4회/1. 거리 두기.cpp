/*
1. 거리 두기
설명
현수는 영화관에 도착했습니다. 영화상영 시간보다 약간 늦은 현수는 남은 좌석을 빨리 선택하고 영화를 보려고 합니다.
현수에게 일렬로된 좌석정보가 주어지면, 이미 앉아 있는 사람들 중 가장 가까운 사람과 최대한 멀리 떨어져 앉을 자석을 선택해야 합니다.
여러분이 도와주세요.
입력
첫 줄에 일렬에 있는 총 좌석수 N(3<=N<=100)가 주어집니다.
두 번째 줄에 N개의 좌석의 정보가 주어집니다. 1은 이미 사람이 앉은 좌석이고 0의 빈 좌석입니다.
출력
첫 줄에 현수가 이미 앉은 사람과 최대한 멀리 앉을 수 있는 거리를 출력합니다.
예시 입력 1
10
1 0 0 0 1 0 0 1 0 1
예시 출력 1
2
*/

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	freopen("input.txt", "rt", stdin);
	vector<int> V;
	int n, num, cnt = 0, maxCnt = -1, startCnt = 0, endCnt = 0, res;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> num;
		V.push_back(num);
		if (num == 1) cnt = 0;
		else {
			cnt++;
			if (maxCnt < cnt) maxCnt = cnt;
		}
	}
	for (int i = 0; i < n; i++) {
		if (V[i] == 1) break;
		else startCnt++;
	}
	for (int i = n - 1; i >= 0; i--) {
		if (V[i] == 1) break;
		else endCnt++;
	}
	res = (startCnt > endCnt ? startCnt : endCnt);
	if (res < (maxCnt - 1) / 2 + 1) res = (maxCnt - 1) / 2 + 1;
	cout << res;
	return 0;
}

/*
모범 답안
	시간복잡도
		O(N)
	공간복잡도
		O(N)
*/