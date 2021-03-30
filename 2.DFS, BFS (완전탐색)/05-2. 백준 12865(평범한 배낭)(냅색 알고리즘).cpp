/*
5-2. 백준 12865(평범한 배낭)(냅색 알고리즘)
이 문제는 아주 평범한 배낭에 관한 문제이다.
한 달 후면 국가의 부름을 받게 되는 준서는 여행을 가려고 한다. 세상과의 단절을 슬퍼하며 최대한 즐기기 위한 여행이기 때문에, 가지고 다닐 배낭 또한 최대한 가치 있게 싸려고 한다.
준서가 여행에 필요하다고 생각하는 N개의 물건이 있다. 각 물건은 무게 W와 가치 V를 가지는데, 해당 물건을 배낭에 넣어서 가면 준서가 V만큼 즐길 수 있다. 아직 행군을 해본 적이 없는 준서는 최대 K만큼의 무게만을 넣을 수 있는 배낭만 들고 다닐 수 있다. 준서가 최대한 즐거운 여행을 하기 위해 배낭에 넣을 수 있는 물건들의 가치의 최댓값을 알려주자.
입력
첫 줄에 물품의 수 N(1 ≤ N ≤ 100)과 준서가 버틸 수 있는 무게 K(1 ≤ K ≤ 100,000)가 주어진다. 두 번째 줄부터 N개의 줄에 거쳐 각 물건의 무게 W(1 ≤ W ≤ 100,000)와 해당 물건의 가치 V(0 ≤ V ≤ 1,000)가 주어진다.
입력으로 주어지는 모든 수는 정수이다.
출력
한 줄에 배낭에 넣을 수 있는 물건들의 가치합의 최댓값을 출력한다.
예제 입력 1
4 7
6 13
4 8
3 6
5 12
예제 출력 1
14
*/

//#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//freopen("input.txt", "rt", stdin);
	int dp[100001] = { 0 };
	int n, k, weight, value;
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> weight >> value;
		for (int j = k; j >= weight; j--) {
			dp[j] = max(dp[j], value + dp[j - weight]);
		}
	}
	cout << dp[k];
	return 0;
}

/*
모범 답안 반영 전
	(중요)
	0-1 냅색의 경우에도 dp를 역순으로 진행하면 1차원 배열로 표현 가능!
	메모리 대폭 감소!
	(실제로는 연산 속도도 대폭 개선!)

//#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int dp[101][100001];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//freopen("input.txt", "rt", stdin);
	int n, k, weight, value;
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> weight >> value;
		for (int j = 0; j <= k; j++) {
			if (j < weight) {
				dp[i][j] = dp[i-1][j];
			}
			else {
				dp[i][j] = max(dp[i-1][j], value + dp[i-1][j-weight]);
			}
		}
	}
	cout << dp[n][k];
	return 0;
}
*/