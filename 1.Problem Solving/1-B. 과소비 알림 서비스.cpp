/*
문제 1-B
제목 과소비 알림 서비스
내용
은행 A에서 고객의 현명한 소비습관을 장려하기 위해 과소비 방지 알림 서비스를
만들려고 한다. 특정 날짜에 고객이 지출한 금액이 이전 d일 동안의 고객의 지출액
의 중앙값 대비 2배 이상인 경우 고객에게 과소비 알림을 보낸다. n일 동안 고객의
일일 지출 금액들이 주어졌을 때, 고객이 총 몇 번의 과소비 알림을 받는지를 출력
하시오. Note: 중앙값(median)은 모든 숫자를 오름차순으로 정렬하여 찾을 수 있다. 홀수
개의 원소가 있으면 가운데 숫자가 선택된다. 짝수 개의 원소가 있으면 중앙값은
두 중간 값의 평균으로 정의된다.
1, 3, 3, 6, 7, 8, 9
Median = 6
1, 2, 3, 4, 5, 6, 8, 9
Median = (4+5)/2 = 4.5
예를 들어, n = 5일 동안의 지출액이 [10,20,30,40,50]일 때 이전 d = 3일 동안의
지출액을 고려하여 알림을 보낸다면, 4일째부터 해당 알림 서비스는 작동이 된다
(즉, 이전 날짜가 3일이 안되는 경우 과소비 알림 서비스 고려 대상이 아니다). 4일
째에 이전 3일 동안의 지출액은 [10,20,30]이며, 해당 지출액의 중앙값은 20으로 4
일째의 지출액과 비교했을 때, “40 ≥ 2 × 20”이 참이 되기 때문에 과소비 알림을
보낸다. 다음 날인 5일째에는 이전 3일 동안의 지출액은 [20,30,40]으로 5일째의
지출액과 비교했을 때, “50 ≥ 2 × 30”이 거짓이 되기에 알림을 보내지 않는다. 결과
적으로 해당 5일 동안 해당 고객은 1번의 알림만을 받는다.

사용할 수 있는 언어는 C, C++로 제한한다. 프로그램의 실행 시간은 3초를 초과할
수 없다. C++의 경우 main 함수 내의 시작 지점에 다음 내용을 추가함으로써 cin
입력 속도를 개선할 수 있다.
std::ios::sync_with_stdio(false);
입력 형식
첫 번째 줄에는 테스트케이스의 수 T(0 < T ≤ 100)가 주어진다. 각 테스트케이스
의 첫 번째 줄에는 총 날짜 수 n(1 ≤ n ≤ 2 × 10^5)일과 고려할 지출 날짜 범위 d
(1 ≤ d ≤ n)일이 공백 하나를 사이에 두고 주어진다. 각 테스트케이스의 두 번째
줄에는 i(1 ≤ i ≤ n)일에 지출한 금액 expenditure[i](0 ≤ expenditure[i] ≤ 200)
이 차례로 공백 하나를 사이에 두고 주어진다. 이후에 같은 형태의 테스트케이스가
T-1개 더 반복된다.
출력 형식
출력은 표준출력으로 수행하며 총 줄로 이루어진다. 각 테스트케이스 별로 한 줄
에 몇 번의 알람을 받는지를 출력한다.
예
입력
2
9 5
2 3 4 2 3 6 8 4 5
5 4
1 2 3 4 4
(empty line)
출력
2
0
(empty line)
*/

#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

double calMedian(int);
vector<int> costCntV(201);
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	freopen("input.txt", "rt", stdin);
	double median;
	int t, n, d, res, cost, k;
	cin >> t;
	while (t--) {
		fill(costCntV.begin(), costCntV.end(), 0);
		res = 0;
		k = 0;
		cin >> n >> d;
		vector<int> costV(n);
		for (int i = 0; i < d; i++) {
			cin >> cost;
			costV[i] = cost;
			costCntV[cost]++;
		}
		for (int i = d; i < n; i++) {
			cin >> cost;
			costV[i] = cost;
			median = calMedian(d);
			if (median * 2 <= cost) res++;
			costCntV[costV[k++]]--;
			costCntV[cost]++;
		}
		cout << res << endl;
	}
	return 0;
}

double calMedian(int d) {
	int cnt = 0;
	if (d % 2 == 1) {
		for (int i = 0; i <= 200; i++) {
			if (costCntV[i] > 0) cnt += costCntV[i];
			if (cnt >= d / 2 + 1) return i;
		}
	}
	else {
		int first = 0;
		int second = 0;
		for (int i = 0; i <= 200; i++) {
			if (costCntV[i] > 0) cnt += costCntV[i];
			if (cnt >= d / 2 && first == 0) {
				first = i;
			}
			if (cnt >= d / 2 + 1 && second == 0) {
				second = i;
				return (first + second) / 2.0;
			}
		}
	}
}

/*
모범 답안
	시간 복잡도
		O(kN) (k=200)
	공간 복잡도
		O(N) (k<<N)

	(중요)
	주어진 데이터 값의 범위(k)가 정렬해야하는 대상(N)보다 훨씬 작다면,
	데이터 값을 기준으로 문제를 해결하기!

	(계수 정렬)(Counting Sort)
	시간 복잡도 O(N+k)
	데이터의 범위(k)가 제한되어 있을 때 수행 가능
	비교를 수행하지 않고 Counting을 통해 정렬한다
	k가 N보다 훨씬 작다면 시간 복잡도 O(N)에 수렴하여 O(NlogN)정렬보다 유리하다.
	단, 정렬을 위해 추가 메모리가 필요하며
	데이터의 범위가 밀집하지 않을 때 심각한 메모리 낭비가 발생한다.
	
*/

/*
모범 답안 반영 전
	시간 복잡도
		O(N * dlogd) (3<=d<=N)
	공간 복잡도
		O(N)

	(결과)
	마지막 testcase(n = 200000, d = 10000)에서 time_limit!
	(실행시간 3초 제한인데, 30초 정도 소요됨)

#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	freopen("input.txt", "rt", stdin);
	double median = 0;
	int t, n, d, cnt = 0, cost;
	cin >> t;
	while (t--) {
		cnt = 0;
		cin >> n >> d;
		vector<int> dV(n);
		vector<int> copyV(d);
		for (int i = 0; i < d; i++) {
			cin >> cost;
			dV[i] = cost;
			copyV[i] = cost;
		}
		sort(copyV.begin(), copyV.end());
		median = (d % 2 == 1 ? copyV[d / 2] : (copyV[d / 2 - 1] + copyV[d / 2]) / 2.0);
		int copyStart = 1;
		for (int i = d; i < n; i++) {
			cin >> cost;
			if (median * 2 <= cost) cnt++;
			dV[i] = cost;
			int k = 0;
			for (int j = copyStart++; j <= i; j++) {
				copyV[k++] = dV[j];
			}
			sort(copyV.begin(), copyV.end());
			median = (d % 2 == 1 ? copyV[d / 2] : (copyV[d / 2 - 1] + copyV[d / 2]) / 2.0);
		}
		cout << cnt << endl;
	}
	return 0;
}
*/