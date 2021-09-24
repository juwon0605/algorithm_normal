/*
2. 오렌지 나무
설명
세종대왕은 현수에게 현수가 다스릴 수 있는 영지를 하사하기로 했습니다. 전체 땅은 사각형으로 표시되고, 그 일부인 정사각형의 땅을 하사합니다.
그 사각형의 땅 중에서 세종대왕이 현수가 다스릴 수 있는 땅의 크기(정사각형 한 변의 길이)를 정해주면 전체 땅 중에서 그 크기의 땅의 위치를 현수가 정하면 되는 것입니다.
정사각형의 땅은 가로, 세로가 x축, y축과 수평을 이루어야 합니다.
체 땅은 2차원 평면좌표 형태로 표현됩니다. 전체 땅 안에는 많은 오렌지 나무가 심겨져 있다. 각 오렌지 나무는 아래 그림처럼 좌표로 표현됩니다.
좌표는 0과 양의 정수로만 표현됩니다.
현수는 오렌지를 무척 좋아하여 오렌지 나무가 가장 많이 포함되는 지역을 선택하고 싶어 합니다. 정사각형 경계선(모서리)에 있는 오렌지 나무도 포함합니다.
현수가 얻을 수 있는 영지의 오렌지 나무 최대 개수를 출력하는 프로그램을 작성하세요. 아래 그림과 같은 땅의 정보가 주어지고,
현수가 하사받을 땅의 크기인 정사각형 한 변의 길이가 3이라면 현수가 얻을 수 있는 최대 오렌지 나무의 개수는 5입니다.
Image1.jpg
입력
첫 줄에 전체 땅의 크기를 나태내는 W(가로길이)와 H(세로길이), T, S가 입력됩니다.
T는 오렌지 나무의 개수이고, S는 현수가 선택할 수 있는 영지의 크기를 나타내는 정사각형 한 변의 길이입니다.
(3<=W, H<=100,000) (1<=T<=100) (1<=S<=W, H)
두 번째 줄부터 T개의 오렌지 나무 위치 정보가 주어집니다.
출력
첫 번째 줄에 현수가 얻을 수 있는 오렌지 나무의 최대 개수를 출력하세요.
예시 입력 1
10 9 8 3
3 4
6 3
5 7
6 6
9 5
6 9
7 8
8 9
예시 출력 1
5
*/

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	freopen("input.txt", "rt", stdin);
	vector<pair<int, int>> pV;
	int w, h, t, s, x, y, max = 0, cnt;
	cin >> w >> h >> t >> s;
	while (t--) {
		cin >> x >> y;
		pV.push_back(make_pair(x, y));
	}
	for (int i = 0; i < pV.size(); i++) {
		for (int j = 0; j < pV.size(); j++) {
			x = pV[i].first;
			y = pV[j].second;
			cnt = 0;
			for (int k = 0; k < pV.size(); k++) {
				int xx = pV[k].first;
				int yy = pV[k].second;
				if (x <= xx && xx <= x + s
					&& y <= yy && yy <= y + s) {
					cnt++;
				}
			}
			if (max < cnt) max = cnt;
		}
	}
	cout << max;
	return 0;
}

/*
모범 답안
	시간복잡도
		O(M^3) (N > M)
	공간복잡도
		O(M) (N > M)
*/

/*
모범 답안 반영 전

	너무 시간복잡도 표현에 얽매였다. 변수의 크기에 따른 실제 연산수를 고려하자!

	시간복잡도
		O(N^2)
	공간복잡도
		O(N^2)

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//freopen("input.txt", "rt", stdin);
	int w, h, t, s, x, y, res = 0;
	cin >> w >> h >> t >> s;
	s++; // 변의 길이
	//vector<vector<char>> map(h + 1, vector<char>(w + 1));
	vector<vector<char>> dp(h + 1, vector<char>(w + 1));
	while (t--) {
		cin >> x >> y;
		//map[y][x] = 1;
		dp[y][x] = 1;
	}
for (int i = 1; i < h + 1; i++) {
	for (int j = 1; j < w + 1; j++) {
		dp[i][j] += dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1];
	}
}
for (int i = s; i < h + 1; i++) {
	for (int j = s; j < w + 1; j++) {
		if (res < dp[i][j] - dp[i - s][j] - dp[i][j - s] + dp[i - s][j - s]) {
			res = dp[i][j] - dp[i - s][j] - dp[i][j - s] + dp[i - s][j - s];
		}
	}
}
cout << res;
return 0;
}
*/