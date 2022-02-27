/*
징검다리
문제 설명
출발지점부터 distance만큼 떨어진 곳에 도착지점이 있습니다. 그리고 그사이에는 바위들이 놓여있습니다. 바위 중 몇 개를 제거하려고 합니다.
예를 들어, 도착지점이 25만큼 떨어져 있고, 바위가 [2, 14, 11, 21, 17] 지점에 놓여있을 때 바위 2개를 제거하면 출발지점, 도착지점, 바위 간의 거리가 아래와 같습니다.

제거한 바위의 위치	각 바위 사이의 거리	거리의 최솟값
[21, 17]	[2, 9, 3, 11]	2
[2, 21]	[11, 3, 3, 8]	3
[2, 11]	[14, 3, 4, 4]	3
[11, 21]	[2, 12, 3, 8]	2
[2, 14]	[11, 6, 4, 4]	4
위에서 구한 거리의 최솟값 중에 가장 큰 값은 4입니다.

출발지점부터 도착지점까지의 거리 distance, 바위들이 있는 위치를 담은 배열 rocks, 제거할 바위의 수 n이 매개변수로 주어질 때, 바위를 n개 제거한 뒤 각 지점 사이의 거리의 최솟값 중에 가장 큰 값을 return 하도록 solution 함수를 작성해주세요.

제한사항
도착지점까지의 거리 distance는 1 이상 1,000,000,000 이하입니다.
바위는 1개 이상 50,000개 이하가 있습니다.
n 은 1 이상 바위의 개수 이하입니다.
입출력 예
distance	rocks	n	return
25	[2, 14, 11, 21, 17]	2	4
입출력 예 설명
문제에 나온 예와 같습니다.

출처

※ 공지 - 2020년 2월 17일 테스트케이스가 추가되었습니다.
*/

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int getMinOfRemove(vector<int>, int);

int solution(int distance, vector<int> rocks, int n) {
	sort(rocks.begin(), rocks.end());
	vector<int> intervalV;
	intervalV.push_back(rocks[0]);
	for (int i = 0; i < rocks.size() - 1; i++) {
		intervalV.push_back(rocks[i + 1] - rocks[i]);
	}
	intervalV.push_back(distance - rocks.back());

	int left = 1;
	int right = distance;
	int mid;
	while (left < (mid = (left + right) / 2)) {
		if (getMinOfRemove(intervalV, mid) > n) {
			right = mid - 1;
		}
		else {
			left = mid;
		}
	}

	return getMinOfRemove(intervalV, right) > n ? mid : right;
}

int getMinOfRemove(vector<int> intervalV, int mid) {
	queue<int> intervalQ;
	for (int interval : intervalV) {
		intervalQ.push(interval);
	}

	int before = 0;
	int cnt = 0;
	while (!intervalQ.empty()) {
		int now = intervalQ.front();
		intervalQ.pop();
		if (now + before < mid) {
			++cnt;
			before += now;
		}
		else {
			before = 0;
		}
	}

	return cnt;
}

/*
모범 답안
	
	프로그래머스 고득점키트 이분탐색 입국심사때는 right = mid였고 left = mid + 1이었다.
	이 경우에 3 ,4, 5를 예를 들어 4가 된다면 3, 3, 4가 되고
	3이 되면 3, 3, 3으로, 3이 안 되도 4, 4, 4로 결국 완전 이분 탐색이 가능했다.

	하지만 이 문제의 경우 left = mid였고 right = mid - 1이다.
	이 경우에 3, 4, 5를 예를 들어 4가 된다면 4, 4, 5가 되고
	4가 되도 4, 4, 5로 다시 계속 4를 탐색하게 되어 결국 5를 탐색하지 않는다.
	따라서 이 경우에는 마지막에 right를 한 번 더 확인해줘야한다!

	시간복잡도
		O(NlogM) (N: 바위의 갯수, M: 출발지점부터 도착지점까지의 거리)
	공간복잡도
		O(N)
*/