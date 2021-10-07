/*
1. 돌다리 건너기
설명
철수는 학교에 가는데 개울을 만났습니다. 개울은 N개의 돌로 다리를 만들어 놓았습니다.
철수는 돌 다리를 건널 때 한 번에 한 칸 또는 두 칸씩 건너뛰면서 돌다리를 건널 수 있습니다.
각 돌은 밟기 위한 비용이 있습니다. 철수가 개울을 건너기 위해 필요한 최소비용을 구하는 프로그램을 작성하세요.
Image1.jpg
입력
첫째 줄은 돌의 개수인 자연수 N(3≤N≤45)이 주어집니다.
두 번째 줄에 각 돌을 밟기 위한 비용이 철수가 있는 곳부터 차례대로 주어집니다.
비용은 100이하의 자연수입니다.
출력
첫 번째 줄에 개울을 건너는데 필요한 최소비용을 출력하세요.
예시 입력 1
7
2 2 50 2 3 50 5
예시 출력 1
12
*/

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	freopen("input.txt", "rt", stdin);
	int n;
	cin >> n;
	vector<int> costV(n + 1);
	vector<int> dp(n + 1, 2147000000);
	for (int i = 1; i <= n; i++) {
		cin >> costV[i];
	}
	dp[0] = 0;
	dp[1] = costV[1];
	for (int i = 2; i <= n; i++) {
		dp[i] = min(dp[i - 1], dp[i - 2]) + costV[i];
	}
	cout << min(dp[n - 1], dp[n]);
	return 0;
}

/*
모범 답안
	시간복잡도
		O(N)
	공간복잡도
		O(N)
*/