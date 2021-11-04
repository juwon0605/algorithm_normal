/*
4. 문자열점수
설명
알파벳 소문자로 구성된 길이 1 이상의 두 문자열 A, B가 있습니다. 이 문자열들의 임의의 위치에 공백을 삽입하여 두 문자열의 길이를 같게 만든 다음,
앞에서부터 한 글자씩 살펴보면서, 같은 위치에 있는 두 문자 A[i], B[i]에 대해서 다음과 같이 점수를 계산합니다.
(1) 두 문자가 같은 경우에는 n1(n1>0)점을 받게 됩니다. 단, 두 문자가 공백으로 같은 경우는 허용하지 않습니다.
(2) 두 문자 중 하나가 공백인 경우에는 n2(n2<0)점을 받게 됩니다.
(3) 두 문자가 모두 공백이 아니고 서로 다른 경우에는 n3(n3<0)점을 받게 된다.
예를 들어 n1=5, n2=-1, n3=-3이고 두 문자열이 abcb, acb 인 경우,
Image1.jpg
이 경우 앞에서부터 점수를 계산하면 각각 5, -1, 5, 5점이 되고 따라서 총점은 14점이 된다.
두 문자열이 주어지면 공백을 적절히 추가하여 얻을 수 있는 최대 총점을 구하는 프로그램을 작성하세요.
입력
첫째 줄에 세 정수 n1, n2, n3가 주어진다. 그리고 둘째 줄에 A가, 둘째 줄에 B가 주어진다.
각 문자열의 길이는 3,000자를 넘지 않으며 빈 문자열은 입력으로 주어지지 않는다.
출력
첫 째줄에 최대 총점을 출력한다.
예시 입력 1
5 -1 -3
abcb
acb
예시 출력 1
14
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
	string a, b;
	int n1, n2, n3;
	cin >> n1 >> n2 >> n3 >> a >> b;
	vector<vector<int>> dp(a.size() + 1, vector<int>(b.size() + 1));
	for (int i = 1; i <= a.size(); i++) {
		dp[i][0] = dp[i - 1][0] + n2;
	}
	for (int i = 1; i <= b.size(); i++) {
		dp[0][i] = dp[0][i - 1] + n2;
	}
	for (int i = 1; i <= a.size(); i++) {
		for (int j = 1; j <= b.size(); j++) {
			if (a[i - 1] == b[j - 1]) {
				dp[i][j] = dp[i - 1][j - 1] + n1;
			}
			else {
				dp[i][j] = dp[i - 1][j] + n2;
				dp[i][j] = max(dp[i][j], dp[i][j - 1] + n2);
				dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + n3);
				dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + n2 + n2);
			}
		}
	}
	cout << dp[a.size()][b.size()];
	return 0;
}

/*
모범 답안

	DP 과정에서 주어진 모든 경우의 수를 계산해나갈 수 있음!

	시간복잡도
		O(N^2)
	공간복잡도
		O(N^2)
*/

/*
모범 답안 반영 전1

	LCS를 구하고 나서 응용할 생각이었는데 오답이었음.
	LCS를 구하는 DP 과정에서 주어진 계산할 생각을 못했음!

	시간복잡도
		O(N^2)
	공간복잡도
		O(N^2)

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
	vector<pair<int, int>> pV;
	string a, b;
	int n1, n2, n3, lcs, starti, endi, startj, endj, res = 0;
	cin >> n1 >> n2 >> n3 >> a >> b;
	vector<vector<int>> dp(a.size() + 1, vector<int>(b.size() + 1));
	for (int i = 1; i <= a.size(); i++) {
		for (int j = 1; j <= b.size(); j++) {
			if (a[i - 1] == b[j - 1]) {
				dp[i][j] = dp[i - 1][j - 1] + 1;
				pV.push_back(make_pair(i, j));
			}
			else {
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
	}
	lcs = dp[a.size()][b.size()];
	res += lcs * n1;
	// lcs문자 외 모두 공백과 만나게 만듬
	if (2 * n2 > n3) {
		res += (a.size() - lcs) * n2;
		res += (b.size() - lcs) * n2;
	}
	// lcs문자 외 모두 최대한 공백이 아닌 서로 다른 문자가 만나게 만듬
	else {
		starti = pV[0].first;
		startj = pV[0].second;
		for (int i = 1; i < pV.size(); i++) {
			if (dp[pV[i].first][pV[i].second] == lcs) {
				endi = pV[i].first;
				endj = pV[i].second;
				break;
			}
		}
		res += (abs(starti - startj) + 1)*n2 + (min(starti, startj) + 1)*n3;
		int minLength = min(endi - starti, endj - startj);
		int lengthSub = abs((endi - starti) - (endj - startj));
		res += lengthSub * n2;
		res += (minLength - lcs)*n3;
		int sizeA = a.size();
		int sizeB = b.size();
		if (endi > endj) {
			res += abs(sizeA - (sizeB + lengthSub))*n2;
			res += min(a.size() - endi, b.size() + lengthSub - endi)*n3;
		}
		else {
			res += abs((sizeA + lengthSub) - sizeB)*n2;
			res += min(a.size() + lengthSub - endj, b.size() - endj)*n3;
		}
	}
	cout << res;
	return 0;
}
*/

/*
모범 답안 반영 전2

	오답 이후 새로운 방법을 생각했지만, 구현하지 못했음.

	시간복잡도
		O(N^2)
	공간복잡도
		O(N^2)

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
	vector<pair<int, int>> pV;
	string a, b;
	int n1, n2, n3, lcs, res = 0, subA, subB;
	cin >> n1 >> n2 >> n3 >> a >> b;
	pV.push_back(make_pair(-1, -1));
	vector<vector<int>> dp(a.size() + 1, vector<int>(b.size() + 1));
	for (int i = 1; i <= a.size(); i++) {
		for (int j = 1; j <= b.size(); j++) {
			if (a[i - 1] == b[j - 1]) {
				dp[i][j] = dp[i - 1][j - 1] + 1;
				pV.push_back(make_pair(i, j));
			}
			else {
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
	}
	lcs = dp[a.size()][b.size()];
	pV.push_back(make_pair(a.size(), b.size()));
	res += lcs * n1;
	// lcs문자 외 모두 공백과 만나게 만듬
	if (2 * n2 > n3) {
		res += (a.size() - lcs) * n2;
		res += (b.size() - lcs) * n2;
	}
	// lcs문자 외 모두 최대한 공백이 아닌 서로 다른 문자가 만나게 만듬
	else {
		//pV에서 lcs를 만드는 a, b의 인덱스만을 어떻게 선별해야할지 모르겠음

		//lcs를 만드는 a, b의 인덱스를 선별했다면 아래와 같이 계산
		for (int i = 0; i < pV.size() - 1; i++) {
			subA = pV[i + 1].first - pV[i].first - 1;
			subB = pV[i + 1].second - pV[i].second - 1;
			res += n2 * abs(subA - subB);
			res += n3 * min(subA, subB);
		}
	}
	cout << res;
	return 0;
}
*/