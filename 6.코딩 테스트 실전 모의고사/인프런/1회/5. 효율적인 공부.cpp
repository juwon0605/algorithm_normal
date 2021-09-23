/*
5. 효율적인 공부
설명
철수는 과학적으로 공부하기 위해 전문 병원에서 철수의 신체 리듬에 따라 공부의 효율성을 표시한 표를 받았다.
표는 N(1<=N<=1,000,000)시간의 일정을 겹쳐지는 M(1<=M<=1,000)구간별로 공부의 효율성이 표시되어 있다.
각 구간은 시작시간(0<=st<N)과 끝나는 시간(st<et<=N) 그리고 해당 구간에서의 공부의 효율성이 주어진다.
철수는 한 구간을 공부하고 나면 꼭 휴식시간(1<=R<=N)을 가져야만 합니다.
철수가 N시간동안 공부를 할 때 각 구간을 잘 선택해서 공부를 열심히 한다면 가장 높은 효율성을 얼마인지 출력하는 프로그램을 작성하세요.
입력
첫째 줄은 세 개의 정수 N, M, R.
둘째 줄부터 M+1줄 까지는 각 구간의 시작시간 끝나는 시간 그리고 해당구간의 공부효율성이 주어집니다.
출력
첫 번째 줄에 가장 높은 효율성을 출력하세요.
예시 입력 1
13 5 2
3 5 20
4 7 16
1 2 5
11 13 7
9 10 6
예시 출력 1
28
*/

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Info
{
	int st;
	int et;
	int num;
	Info(int a, int b, int c) {
		st = a;
		et = b;
		num = c;
	}
	bool operator< (const Info &b) const {
		return (et != b.et ? et < b.et : st < b.st);
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	freopen("input.txt", "rt", stdin);
	vector<Info> infoV;
	int n, m, r, st, et, num;
	cin >> n >> m >> r;
	vector<int> dp(m);
	while (m--) {
		cin >> st >> et >> num;
		infoV.push_back(Info(st, et, num));
	}
	sort(infoV.begin(), infoV.end());
	dp[0] = infoV[0].num;
	for (int i = 1; i < infoV.size(); i++) {
		dp[i] = infoV[i].num;
		for (int j = i - 1; j >= 0; j--) {
			if (infoV[j].et + r <= infoV[i].st && dp[j] + infoV[i].num > dp[i]) {
				dp[i] = dp[j] + infoV[i].num;
			}
		}
		dp[i] = max(dp[i - 1], dp[i]);
	}
	cout << dp[infoV.size() - 1];
	return 0;
}

/*
모범 답안
	시간복잡도
		O(M^2) (N > M)
	공간복잡도
		O(M) (N > M)
*/

/*
모범 답안 반영 전
	시간복잡도
		O(MN) (N > M)
	공간복잡도
		O(N) (N > M)

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Info
{
	int st;
	int et;
	int num;
	Info(int a, int b, int c) {
		st = a;
		et = b;
		num = c;
	}
	bool operator< (const Info &b) const {
		return (et != b.et ? et < b.et : st < b.st);
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	freopen("input.txt", "rt", stdin);
	vector<Info> infoV;
	int n, m, r, st, et, num;
	cin >> n >> m >> r;
	vector<int> dp(n + 1 + r + 1);
	while (m--) {
		cin >> st >> et >> num;
		infoV.push_back(Info(st, et, num));
	}
	sort(infoV.begin(), infoV.end());
	for (int i = 0; i < infoV.size(); i++) {
		st = infoV[i].st;
		et = infoV[i].et;
		num = infoV[i].num;
		dp[et + r] = max(dp[et + r], dp[st] + num);
		for (int i = et + r + 1; i < n + r + 2; i++) {
			dp[i] = max(dp[i], dp[i - 1]);
		}
	}
	cout << dp[n + r + 1];
	return 0;
}
*/