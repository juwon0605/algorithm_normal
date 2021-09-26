/*
3. 멀티태스킹(효율성)
설명
현수의 컴퓨터는 멀티태스킹이 가능하다. 처리해야 할 작업이 N개 들어오면 현수의 컴퓨터는 작업을 1부터 N까지의 번호를 부여하고 처리를 다음과 같이 한다.
1) 컴퓨터는 1번 작업부터 순서대로 1초씩 작업을 한다. 즉 각 작업을 1초만 작업하고 다음 작업을 하는 식이다.
2) 마지막 번호의 작업을 1초 했으면 다시 1번 작업으로 가서 다시 1초씩 후속 처리를 한다.
3) 처리가 끝난 작업은 작업 스케쥴에서 사라지고 새로운 작업은 들어오지 않는다.
그런데 현수의 컴퓨터가 일을 시작한 지 K초 후에 정전이 되어 컴퓨터가 일시적으로 멈추었다. 전기가 들어오고 나서 현수의 컴퓨터가 몇 번 작업부터
다시 시작해야 하는지 알아내는 프로그램을 작성하세요.
입력
첫 번째 줄에 작업의 개수 N(1<=N<=200,000)이 주어지고 그 다음 N줄에 걸쳐 각 작업을 처리하는데 걸리는 시간이 초단위로 주어진다.
한 작업을 처리하는데 필요한 시간은 100,000,000를 넘지 않는 자연수입니다.
마지막 줄에 정전이 발생한 시간 K(1<=K<=2 x 10^13)가 주어진다.
출력
첫 번째 줄에 몇 번 작업부터 다시 시작해야 하는지 작업 번호를 출력한다.
만약 더 이상 처리할 작업이 없다면 -1를 출력한다.
예시 입력 1
3
1
2
3
5
예시 출력 1
3
힌트
<입출력 설명>
• 0~1초 동안에 1번 작업을 처리한다. 남은 시간은 [0, 2, 3] 이다.
• 1~2초 동안 2번 작업을 처리한다. 남은 시간은 [0, 1, 3] 이다.
• 2~3초 동안 3번 작업을 처리한다. 남은 시간은 [0, 1, 2] 이다.
• 3~4초 동안 2번 작업을 처리한다(1번 작업은 다 처리했다). 남은 시간은 [0, 0, 2] 이다.
• 4~5초 동안 3번 작업을 처리한다. 남은 시간은 [0, 0, 1] 이다.
• 5초 후 정전이 발행했으므로 3번 작업을 해야 할 때 중단되었으므로, 전기가 돌아온 후로는 3번 작업부터 시작하면 된다.
*/

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool compare1(pair<int, long long> a, pair<int, long long> b);
bool compare2(pair<int, long long> a, pair<int, long long> b);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	freopen("input.txt", "rt", stdin);
	vector<pair<int, long long>> pV;
	long long k, num;
	int n;
	cin >> n;
	pV.push_back(make_pair(0, 0));
	for (int i = 0; i < n; i++) {
		cin >> num;
		pV.push_back(make_pair(i + 1, num));
	}
	cin >> k;
	sort(pV.begin(), pV.end(), compare2);
	for (int i = 1; i < n + 1; i++) {
		long long now = (pV[i].second - pV[i - 1].second) * (n + 1 - i);
		if (now <= k) {
			k -= now;
		}
		else {
			sort(pV.begin() + i, pV.end(), compare1);
			cout << pV[i + k % (n + 1 - i)].first;
			return 0;
		}
	}
	cout << -1;
	return 0;
}

bool compare1(pair<int, long long> a, pair<int, long long> b) {
	return a.first < b.first;
}
bool compare2(pair<int, long long> a, pair<int, long long> b) {
	return (a.second != b.second ? a.second < b.second : a.first < b.first);
}

/*
모범 답안
	시간복잡도
		O(NlogN)
	공간복잡도
		O(N)
*/