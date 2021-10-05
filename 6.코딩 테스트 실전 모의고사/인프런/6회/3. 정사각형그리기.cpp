/*
3. 정사각형 그리기
설명
엘리트 정보센터에서 학생들에게 0과 1이 잔뜩 적힌 종이를 주면서 그 안에서 1을 이용해서 만들 수 있는
정사각형의 개수가 모두 몇 개 인지 조사해 오라고 하셨다.
예를 들어 종이의 내용이 다음과 같다면
Image1.jpg
크기가 1인 정사각형은 26개, 크기가 2인 정사각형은 11개, 크기가 3인 정사각형은 2개가 있다.
이에 여러분은 종이의 적힌 값을 입력할 경우 모든 정사각형의 개수를 세어주는 프로그램을 작성하세요.
입력
첫 줄에는 종이의 세로(N), 가로(M)의 크기가 들어온다. (1<=n, m<=1000) 그 다음 N줄에 종이에 적힌 숫자가 차례로 들어온다.
출력
크기가 작은 정사각형부터 크기와 개수를 차례로 출력한다.
예시 입력 1
6 8
00001010
00011110
00011000
00011110
11111110
11111110
예시 출력 1
1 26
2 11
3 2
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
	int n, m, sum = 0;
	char c;
	cin >> n >> m;
	vector<vector<int>> map(n + 1, vector<int>(m + 1));
	vector<vector<int>> dp(n + 1, vector<int>(m + 1));
	vector<int> resV(min(n, m) + 1);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> c;
			if (c == '1') map[i][j] = 1;
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (map[i][j] == 1) {
				dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) + 1;
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			resV[dp[i][j]]++;
		}
	}
	for (int i = 1; i <= min(n, m); i++) {
		if (resV[i] == 0) break;
		sum += resV[i];
	}
	for (int i = 1; i <= min(n, m); i++) {
		if (resV[i] == 0) break;
		cout << i << " " << sum << "\n";
		sum -= resV[i];
	}
	return 0;
}

/*
모범 답안
	시간복잡도
		O(N^2)
	공간복잡도
		O(N^2)
*/

/*
모범 답안 반영 전

	시간복잡도
		O(N^3)
	공간복잡도
		O(N^2)

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	freopen("input.txt", "rt", stdin);
	int n, m;
	char c;
	cin >> n >> m;
	vector<vector<int>> map(n + 1, vector<int>(m + 1));
	vector<vector<int>> dp(n + 1, vector<int>(m + 1));
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> c;
			if (c == '1') map[i][j] = 1;
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + map[i][j];
		}
	}
	for (int k = 1; k <= min(n, m); k++) {
		int cnt = 0;
		for (int i = 0 + k; i <= n; i++) {
			for (int j = 0 + k; j <= m; j++) {
				if (dp[i][j] - dp[i - k][j] - dp[i][j - k] + dp[i - k][j - k] == k * k) cnt++;
			}
		}
		if (cnt > 0) cout << k << " " << cnt << "\n";
	}
	return 0;
}
*/

/*
주의할 점

	더블 스크린으로 문제 페이지를 반으로 줄였더니 1000이 짤려서 100으로 잘못봐서
	O(N^5)으로 구현하고 채점시 컴파일 에러가 어디서 발생하는지 30분 동안 찾았다...
	문제를 최대한 꼼꼼히 읽고, 알고리즘을 생각하고 문제를 풀자!
	문제가 안 풀리더라도 실수한 부분이 없나 먼저 확인해보고, 문제를 다시 읽어보자!

	시간복잡도
		O(N^5)
	공간복잡도
		O(N^2)

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	freopen("input.txt", "rt", stdin);
	int map[100][100];
	int n, m;
	char c;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> c;
			map[i][j] = (c == '0' ? 0 : 1);
		}
	}
	for (int k = 0; k < min(n, m); k++) {
		int cnt = 0;
		for (int i = 0; i + k < n; i++) {
			for (int j = 0; j + k < m; j++) {
				bool valid = true;
				for (int ii = 0; ii < k + 1; ii++) {
					for (int jj = 0; jj < k + 1; jj++) {
						if (map[i + ii][j + jj] == 0) {
							valid = false;
							break;
						}
					}
					if (!valid) break;
				}
				if (valid) cnt++;
			}
		}
		if (cnt > 0) cout << k + 1 << " " << cnt << "\n";
	}
	return 0;
}
*/