/*
09. 백준 1253(좋다)
문제
N개의 수 중에서 어떤 수가 다른 수 두 개의 합으로 나타낼 수 있다면 그 수를 “좋다(GOOD)”고 한다.
N개의 수가 주어지면 그 중에서 좋은 수의 개수는 몇 개인지 출력하라.
수의 위치가 다르면 값이 같아도 다른 수이다.
입력
첫째 줄에는 수의 개수 N(1 ≤ N ≤ 2,000), 두 번째 줄에는 i번째 수를 나타내는 Ai가 N개 주어진다. (|Ai| ≤ 1,000,000,000, Ai는 정수)
출력
좋은 수의 개수를 첫 번째 줄에 출력한다.
예제 입력 1
10
1 2 3 4 5 6 7 8 9 10
예제 출력 1
8
힌트
3,4,5,6,7,8,9,10은 좋다.
*/

#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<unordered_map>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	freopen("input.txt", "rt", stdin);
	unordered_map<int, int> uM;
	int n, num, res = 0;
	cin >> n;
	while (n--) {
		cin >> num;
		uM[num]++;
	}
	for (auto i = uM.begin(); i != uM.end(); i++) {
		if (i->first != 0) {
			if (i->second >= 2 && uM.find(0) != uM.end()) {
				res += i->second;
			}
			else if (i->first % 2 == 0 && uM.find((i->first)/2) != uM.end() && uM[(i->first)/2] >=2) {
				res += i->second;
			}
			else {
				for (auto j = uM.begin(); j != uM.end(); j++) {
					if (i == j) continue;
					if (i->first == 2 * (j->first)) continue;
					if (uM.find(i->first - j->first) != uM.end()) {
						res += i->second;
						break;
					}
				}
			}
		}
		else {
			if (i->second >= 3) {
				res += i->second;
			}
			else {
				for (auto j = uM.begin(); j != uM.end(); j++) {
					if (i == j) continue;
					if (uM.find(i->first - j->first) != uM.end()) {
						res += i->second;
						break;
					}
				}
			}

		}
	}
	cout << res;
	return 0;
}

/*
모범 답안
	시간복잡도
		O(N^2)
	공간복잡도
		O(N)
*/

/*
모범 답안 반영 전

*/