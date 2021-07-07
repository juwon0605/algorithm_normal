/*
문제 8-B
제목 LCS
내용
길이가 n인 문자열 Z = z1z2...zn의 길이 k인 부분서열(subsequence)이란
Z의 문자들로 이루어진 문자열 zi(1)...zi(k)이다(단 1 ≤ i(p) < i(p+1) ≤ n). 예를 들
어, Z = abcdeab일 때, abcde와 cab는 Z의 부분서열이며 dba는 부분서열이
아니다. 최장공통부분서열(Longest Common Subsequence, LCS)은 두 문
자열 X와 Y가 주어졌을 때, X와 Y 사이에 공통으로 존재하는 가장 긴 부
분서열이다. 두 문자열의 LCS는 유일하지 않을 수도 있다. 예를 들어,
acbabk와 acakbb의 LCS는 acak, acab, acbb이다. 두 문자열 X와 Y가 주
어졌을 때, X, Y의 LCS의 길이를 출력하는 프로그램을 작성하시오.
사용 할 수 있는 언어는 C, C++로 제한한다. 프로그램의 실행시간은 1초를
초과할 수 없다. C++의 경우 main 함수 내의 시작 지점에 다음 내용을 추
가함으로써 cin 입력 속도가 개선되는 경우도 있다.
std::ios::sync_with_stdio(false);
입력 형식
입력은 표준입력으로 다음과 같이 주어진다.
1. 첫 번째 줄에는 테스트케이스의 수 T가 주어진다. (1 ≤ T ≤ 1000)
2. 두 번째 줄에는 첫 번째 문자열 S1(길이 1,000 이하)이 주어진다.
3. 세 번째 줄에는 두 번째 문자열 S2(길이 1,000 이하)이 주어진다.
4. 그 이후에는 위의 2, 3 단계가 T-1번 반복된다.
출력 형식
출력은 표준출력으로 수행하며 총 T줄로 이루어진다. 각 줄에는 각 테스트
케이스 별로 LCS의 길이를 출력한다.
예
입력
2
acbabk
acakbb
acaykpzzk
capcakkzz
출력
4
6
*/

#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int dp[1001][1001];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	freopen("input.txt", "rt", stdin);
	string x, y;
	int t;
	cin >> t;
	while (t--) {
		cin >> x >> y;
		for (int i = 1; i <= y.size(); i++) {
			for (int j = 1; j <= x.size(); j++) {
				if (y[i - 1] != x[j - 1]) {
					dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
				}
				else {
					dp[i][j] = dp[i - 1][j - 1] + 1;
				}
			}
		}
		cout << dp[y.size()][x.size()] << endl;
	}
	return 0;
}

/*
모범 답안
	시간 복잡도
		O(TMN)
	공간 복잡도
		O(MN)
*/