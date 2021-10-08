/*
3. 조 나누기
설명
현수네 동아리는 수학동아리입니다. 동아리 회장은 수학성적을 올리기 위해 동아리 회원을 M개의 조로 나누어 각 조별로 서로 도우며 공부하기로 했습니다.
동아리는 여러 학년이 섞여 있는데 동아리 회장은 조원들간의 친밀감을 높여주기 위해 비슷한 나이끼로 한 조가 되도록 동아리 회원들을 나이순으로 정렬한
다음 적당히 나누어 M개의 조를 만들려고 합니다. 다음 그림은 동아리 회원을 나이순으로 정렬한 각 회원의 수학성적입니다.
M개의 조가 잘 짜졌다라고 하려면 각 조의 성적의 합 중 최대값이 최소가 되도록 하는 것입니다.
예를 들어 아래 순서를 3개의 조로 나눈 다면
Image1.jpg
위와 같이 나누면 (50+20), (30+70), (20+60+30) 로 각 조의 합은 각각 70, 100, 110이 되어 그 중 최대값은 110이 된다.
하지만 아래와 같이 3개의 조로 나누면
Image1.jpg
각 조의 합이 각각 100, 90, 90이 되어 그 중 최댓값은 100이 된다. 각 조의 합의 최댓값을 100보다 더 작게 만들 수 없다.
각 조의 합 중 최대값이 최소가 되도록 M개의 조로 나누었을 때, 그 최대값을 출력하는 프로그램을 작성하세요.
입력
첫째 줄에 학생수 N과 조의 개수 M이 주어진다. 둘째 줄에는 나이순으로 정렬된 각 학생의 수학점수가 주어진다.
N은 300이하의 자연수, M은 N이하의 자연수이며, 각 학생의 점수는 100이하의 자연수이다.
출력
각 조의 합 중 최대값이 최소가 되도록 M개의 조로 나누었을 때 그 최대값을 출력한다.
예시 입력 1
7 3
50 20 30 70 20 60 30
예시 출력 1
100
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
	int numArr[300];
	int n, m, res, start = 100, mid, end, sum = 0, cnt;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> numArr[i];
		sum += numArr[i];
		start = max(start, numArr[i]);
	}
	end = sum;
	while (start <= end) {
		mid = (start + end) / 2;
		sum = 0;
		cnt = 1;
		for (int i = 0; i < n; i++) {
			if (sum + numArr[i] > mid) {
				sum = numArr[i];
				cnt++;
			}
			else {
				sum += numArr[i];
			}
		}
		if (cnt > m) {
			start = mid + 1;
		}
		else {
			res = mid;
			end = mid - 1;
		}
	}
	cout << res;
	return 0;
}

/*
모범 답안
	시간복잡도
		O(NlogK) (1<=K<=100 * N)
	공간복잡도
		O(N)	 (1<=N<=300)
*/

/*
모범 답안 반영 전

	N이 20이상일 경우에는 O(2^N)말고 다른 풀이를 생각하자!
	이진 탐색은 보통 주어진 값의 범위가 굉장히 클 때 주로 써서 쓸 생각을 못했다.
	주어진 값의 크기가 작아도 이진 탐색을 적용해보자!

	시간복잡도
		O(2^N) (1<=N<=300)
	공간복잡도
		O(N)

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void DFS(int, int, int);
int flag[300];
int numArr[300];
int n, m, res = 2147000000, limit;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	freopen("input.txt", "rt", stdin);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> numArr[i];
	}
	flag[0] = 1;
	DFS(1, numArr[0], 1);
	cout << res;
	return 0;
}

void DFS(int L, int sum, int team) {
	if (sum > res) return;
	if (L == n) {
		if (team != m) return;
		vector<int> sumV(m + 1);
		int maxSum = -1;
		for (int i = 0; i < n; i++) {
			sumV[flag[i]] += numArr[i];
		}
		for (int i = 1; i <= m; i++) {
			maxSum = max(maxSum, sumV[i]);
		}
		res = min(res, maxSum);
	}
	else {
		if (team < m) {
			flag[L] = team + 1;
			DFS(L + 1, numArr[L], team + 1);
		}
		flag[L] = team;
		DFS(L + 1, sum + numArr[L], team);
	}
}
*/