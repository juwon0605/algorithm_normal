/*
문제 9-B
제목 배낭싸기
내용
인하마을에 살고 있는 강인하는 비룡마을로 이사를 가려 한다. 그런데 강인
하는 소유하고 있던 N개의 모든 물건을 전부 비룡마을로 가지고 갈 수 없을
수도 있다. 왜냐하면 배낭 하나에 담을 수 있는 무게가 K kg으로 제한되어
있고 한 번 비룡마을로 이사를 가면 다시 인하마을로 되돌아 올 수 없기 때
문이다. 단, N개의 물건마다 각각 얼마인지 가치가 매겨져 있으며, 물건을
쪼개어 일부분만 배낭에 넣는 것은 불가능하다. 배낭에 담은 물건들의 가치의
합이 최대가 되도록 배낭을 싸는 방법을 강인하에게 알려주자.
사용 할 수 있는 언어는 C, C++로 제한한다. 프로그램의 실행시간은 1초를
초과할 수 없다. C++의 경우 main 함수 내의 시작 지점에 다음 내용을 추
가함으로써 cin 입력 속도가 개선되는 경우도 있다.
std::ios::sync_with_stdio(false);
입력 형식
입력은 표준입력으로 다음과 같이 주어진다.
1. 첫 번째 줄에는 테스트케이스의 수 T가 주어진다. (1 ≤ T ≤ 10)
2. 두 번째 줄에는 첫 번째 테스트케이스에 대해 강인하가 소유하고 있는 물
건의 개수 N(1 ≤ N ≤ 500)과 강인하의 배낭이 버틸 수 있는 무게 K
(1 ≤ K ≤ 100,000)가 빈 칸 하나를 사이에 두고 주어진다.
3. 세 번째 줄에는 각 물건의 무게 W(1 ≤ W ≤ 10,000)가 빈 칸 하나를 사
이에 두고 순서대로 주어진다.
4. 네 번째 줄에는 각 물건의 가치 V(1 ≤ V ≤ 100,000)가 빈 칸 하나를 사
이에 두고 순서대로 주어진다.
5. 그 이후에는 위의 2, 3, 4단계가 T-1번 반복된다.
출력 형식
출력은 표준출력으로 수행하며 총 T줄로 이루어진다. 각 줄에는 각 테스트
케이스 별로 배낭에 담은 물건들의 가치의 합의 최대값을 출력한다.
예
입력
2
4 7
6 4 3 5
13 8 6 12
5 11
7 2 8 9 3
6 8 12 4 9
출력
14
21
*/

#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct Item {
	int weight;
	int value;
	Item() {};
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	freopen("input.txt", "rt", stdin);
	vector<Item> itemV(500);
	int t, n, k;
	cin >> t;
	while (t--) {
		cin >> n >> k;
		vector<int> dp(k + 1);
		for (int i = 0; i < n; i++) {
			cin >> itemV[i].weight;
		}
		for (int i = 0; i < n; i++) {
			cin >> itemV[i].value;
		}
		for (int i = 0; i < n; i++) {
			for (int j = k; j - itemV[i].weight >= 0; j--) {
				dp[j] = max(dp[j], dp[j - itemV[i].weight] + itemV[i].value);
			}
		}
		cout << dp[k] << endl;
	}
	return 0;
}

/*
모범 답안
	시간 복잡도
		O(TNK)
	공간 복잡도
		O(K) (N<K)
*/