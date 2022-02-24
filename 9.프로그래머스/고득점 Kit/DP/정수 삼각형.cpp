/*
정수 삼각형
문제 설명
스크린샷 2018-09-14 오후 5.44.19.png

위와 같은 삼각형의 꼭대기에서 바닥까지 이어지는 경로 중, 거쳐간 숫자의 합이 가장 큰 경우를 찾아보려고 합니다. 아래 칸으로 이동할 때는 대각선 방향으로 한 칸 오른쪽 또는 왼쪽으로만 이동 가능합니다. 예를 들어 3에서는 그 아래칸의 8 또는 1로만 이동이 가능합니다.

삼각형의 정보가 담긴 배열 triangle이 매개변수로 주어질 때, 거쳐간 숫자의 최댓값을 return 하도록 solution 함수를 완성하세요.

제한사항
삼각형의 높이는 1 이상 500 이하입니다.
삼각형을 이루고 있는 숫자는 0 이상 9,999 이하의 정수입니다.
입출력 예
triangle	result
[[7], [3, 8], [8, 1, 0], [2, 7, 4, 4], [4, 5, 2, 6, 5]]	30
출처
*/

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int DFS(int, int);
vector<vector<int>> save(499, vector<int>(499, -1));
vector<vector<int>> copyTriangle;
int n;

int solution(vector<vector<int>> triangle) {
	copyTriangle = triangle;
	n = triangle.size();

	return DFS(0, 0);
}

int DFS(int L, int idx) {
	if (L == n - 1) {
		return copyTriangle[L][idx];
	}
	else {
		if (save[L][idx] != -1) {
			return save[L][idx];
		}
		else {
			return save[L][idx] = copyTriangle[L][idx] + max(DFS(L + 1, idx), DFS(L + 1, idx + 1));
		}
	}
}

/*
모범 답안

	bottom up DFS와 메모이제이션으로 풀었음.

	시간복잡도
		O(N^2)
	공간복잡도
		O(N^2)
*/

/*
다른 모범 답안

	top down DP로도 풀 수 있음.

	시간복잡도
		O(N^2)
	공간복잡도
		O(N^2)

#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<vector<int>> triangle) {
	int answer = 0;
	int n = triangle.size();
	vector<vector<int>> dp(n, vector<int>(n));
	dp[0][0] = triangle[0][0];

	for(int i = 0; i < n - 1; i++){
		for(int j = 0; j < triangle[i].size(); j++){
			dp[i + 1][j] = max(dp[i + 1][j], dp[i][j] + triangle[i+ 1][j]);
			dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i][j] + triangle[i+ 1][j + 1]);
		}
	}

	for(int j = 0; j < triangle[n-1].size(); j++){
		answer = max(answer, dp[n-1][j]);
	}

	return answer;
}
*/