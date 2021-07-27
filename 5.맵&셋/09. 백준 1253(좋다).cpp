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
#include<algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	freopen("input.txt", "rt", stdin);
	int arr[2000];
	int n, left, right, now, res = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + n);
	for (int i = 0; i < n; i++) {
		now = arr[i];
		left = 0;
		right = n - 1;
		while (left < right) {
			if (arr[left] + arr[right] == now) {
				if (left != i && right != i) {
					res++;
					break;
				}
				else if (left == i) left++;
				else if (right == i) right--;
			}
			else if (arr[left] + arr[right] < now) left++;
			else right--;
		}
	}
	cout << res;
	return 0;
}

/*
모범 답안

	투포인트 알고리즘과 이진탐색을 활용해서 모든 상황에 대해 일반적인 풀이

	시간 복잡도
		O(N^2)
	공간 복잡도
		O(N)
*/

/*
모범 답안 반영 전

	모든 특수한 상황들을 생각해내고 각각 그 상황에 맞게 풀이
	map, set 연습 문제 푼다고 너무 억지로 map, set을 사용하려고 했음
	자유롭게 생각하면서 최적의 풀이를 찾아내자

	시간 복잡도
		O(N^2)
	공간 복잡도
		O(N)

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
*/