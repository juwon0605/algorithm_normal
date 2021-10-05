/*
2. 공통원소 최댓값
설명
N개의 원소를 갖는 같은 크기의 A, B, C 세 개의 집합이 주어집니다.
세 집합의 공통원소 중 가장 큰 숫자를 출력하는 프로그램을 작성하세요.세 집합의 공통원소는 반드시 존재합니다.
입력
첫 번째 줄에 세 집합의 크기인 자연수 N(3<=N<=20,000)이 주어집니다.
두 번째 줄부터 세 줄에 걸쳐 A, B, C집합의 원소가 한 줄에 한 집합씩 입력됩니다.
출력
세 집합의 공통원소 중 가장 큰 값을 출력합니다. 공통원소가 존재하지 않으면 -1를 출력합니다.
예시 입력 1
10
39 31 32 75 75 7 89 21 7 67
4 19 52 75 35 100 4 26 24 69
82 53 22 64 58 80 94 75 51 69
예시 출력 1
75
*/

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	freopen("input.txt", "rt", stdin);
	vector<unordered_set<int>> uSV(3);
	unordered_map<int, int> uM;
	int n, num, res = -1;
	cin >> n;
	for (int k = 0; k < 3; k++) {
		for (int i = 0; i < n; i++) {
			cin >> num;
			uSV[k].insert(num);
		}
	}
	for (int k = 0; k < 3; k++) {
		for (auto iter = uSV[k].begin(); iter != uSV[k].end(); iter++) {
			uM[*iter]++;
		}
	}
	for (auto iter = uM.begin(); iter != uM.end(); iter++) {
		if (iter->second == 3 && res < iter->first) res = iter->first;
	}
	cout << res;
	return 0;
}

/*
모범 답안
	시간복잡도
		O(N)
	공간복잡도
		O(N)
*/