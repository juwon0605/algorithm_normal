/*
3. 최대공통부분문자열(LCS)
설명
최대 공통 부분 문자열이란 두 문자열 acbehf와 , abefc의 공통의 부분 문자열 중에서 가장 긴 것을 의미한다.
여기서 최대 공통 부분 문자열은 abef 이다.
두 문자열이 주어지면 두 문자열의 최대공통부분문자열의 길이를 출력하는 프로그램을 작성하세요.
입력
첫 번째 줄은 최대 공통 부분 문자열의 첫 번째 문자열이고, 둘째 줄은 두 번째 문자열이 주어진다.
두 문자열의 길이는 1000을 넘지 않으며 소문자로 주어진다.
출력
첫 번째 줄에 최대공통부분문자열의 길이를 출력합니다.
예시 입력 1
acbehf
abefc
예시 출력 1
4
*/

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	freopen("input.txt", "rt", stdin);
	vector<vector<int>> dp(1001, vector<int>(1001));
	string str1, str2;
	cin >> str1 >> str2;
	for (int i = 1; i <= str1.size(); i++) {
		for (int j = 1; j <= str2.size(); j++) {
			if (str1[i - 1] == str2[j - 1]) {
				dp[i][j] = dp[i-1][j-1] + 1;
			}
			else {
				dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
			}
		}
	}
	cout << dp[str1.size()][str2.size()];
	return 0;
}

/*
모범 답안
	시간복잡도
		O(N^2)
	공간복잡도
		O(N^2)
*/