/*
4. 사막의 벼농사
설명
현수는 쿠웨이트에 있는 사막에 벼농사가 되도록 하기 위해 바다에 있는 물을 증류해서 사막으로 보내려고 합니다.
거대한 송수관 공사를 해야 하는데 각 파이프의 길이와 용량이 각기 다릅니다.
바다에서 사막까지의 길이 L이 주어지고, N개의 파이프의 길이와 용량이 주어지면 단위시간에 송수관의 최대 용량을 구하는 프로그램을 작성하세요.
여러개의 파이프를 연결하여 송수관을 만들었을 때 단위시간 송수관의 용량은 송수관을 구성하는 파이프 중 가장 작은 용량이 됩니다.
만약 바다에서 사막까지의 길이가 6이고, 현수가 가지고 있는 파이프의 개수가 4개이고 각기 다음과 같은 길이와 용량을 가지고 있다면
3 6
2 7
4 8
1 5
3+2+1=6 길이를 만든다면 최대용량은 5이고, 2+4=6 길이를 만든다면 최대용량은 7이 됩니다.
즉 현수가 바다에서 사막으로 보낼 수 있는 송수관의 최대 용량은 7입니다.
입력
첫째 줄에 L(5<=L<=300)과 N(3<=N<=20)가 주어진다.
두번째 줄부터 N개의 파이프의 길이와 용량이 차례로 주어진다.
출력
첫 번째 줄에 송수관의 최대용량을 출력합니다.
예시 입력 1
6 4
3 6
2 7
4 8
1 5
예시 출력 1
7
*/

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>
using namespace std;

void DFS(int, int, int);
int lengthArr[20];
int speedArr[20];
int l, n, res = -1;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	freopen("input.txt", "rt", stdin);
	cin >> l >> n;
	for (int i = 0; i < n; i++) {
		cin >> lengthArr[i];
		cin >> speedArr[i];
	}
	DFS(0, 0, 2147000000);
	cout << res;
	return 0;
}

void DFS(int L, int length, int speed) {
	if (length > l) return;
	if (L == n) {
		if (length == l && res < speed) {
			res = speed;
		}
	}
	else {
		DFS(L + 1, length + lengthArr[L], min(speed, speedArr[L]));
		DFS(L + 1, length, speed);
	}
}

/*
모범 답안
	시간복잡도
		O(2^N)
	공간복잡도
		O(N)
*/