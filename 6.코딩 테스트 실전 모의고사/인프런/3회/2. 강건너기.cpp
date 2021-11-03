/*
2. 강건너기
설명
1번, 2번, 3번, 4번으로 구분하는 네 명의 사람이 강을 건너려고 합니다. 강에는 배가 한 척밖에 없고, 그 배에는 최대 두 명이 탈 수 있습니다.
혼자서 배를 타고 노를 저어 강을 건널 경우 1번은 1분, 2번은 3분, 3번은 7분, 4번은 10분이 걸립니다.
둘 이 함께 타고 건널 경우 안전을 위하여 더 천천히 노를 젖는 사람이 노를 잡습니다. 만약 1번과 2번이 함께 타고 강을 건너면 3분이 걸립니다.
네 사람이 강을 건너려면 최소 몇 분이 걸릴까요?
Image1.jpg
1번부터 N번까지의 N명의 노를 저어 강을 건너는 시간이 주어지면 N명의 사람이 모두 강을 건너는데 걸리는
최소시간을 출력하는 프로그램을 작성하세요.
입력
첫 번째 줄에 자연수 N(4<=N<=100)이 주어지고 그 다음줄에는 1번 사람부터 차례대로 강을 건너는데 걸리는 시간이 주어집니다.
출력
최소시간을 출력하세요. (단위는 분입니다)
예시 입력 1
4
1 3 7 10
예시 출력 1
20
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
	int n, res = 0;
	cin >> n;
	vector<int> V(n);
	for (int i = 0; i < n; i++) {
		cin >> V[i];
	}
	sort(V.begin(), V.end());
	for (int i = n - 1; i >= 3; i -= 2) {
		res += min(V[i] + V[0] + V[i - 1] + V[0], V[1] + V[0] + V[i] + V[1]);
	}
	if (n % 2 == 0) {
		res += V[1];
	}
	else {
		for (int i = 0; i < 3; i++) {
			res += V[i];
		}
	}
	cout << res;
	return 0;
}

/*
모범 답안
	시간복잡도
		O(NlogN)
	공간복잡도
		O(N)
*/

/*
모범 답안 반영 전
	출력예제를 만드는 경우를 생각해내지 못해서 못 풀었음.
	건너간 최고 속도가 아닌 사람이 다시 되돌아 오는 경우를 생각하지 못했음!
*/