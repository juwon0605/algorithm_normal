/*
도둑질
문제 설명
도둑이 어느 마을을 털 계획을 하고 있습니다. 이 마을의 모든 집들은 아래 그림과 같이 동그랗게 배치되어 있습니다.

image.png

각 집들은 서로 인접한 집들과 방범장치가 연결되어 있기 때문에 인접한 두 집을 털면 경보가 울립니다.

각 집에 있는 돈이 담긴 배열 money가 주어질 때, 도둑이 훔칠 수 있는 돈의 최댓값을 return 하도록 solution 함수를 작성하세요.

제한사항
이 마을에 있는 집은 3개 이상 1,000,000개 이하입니다.
money 배열의 각 원소는 0 이상 1,000 이하인 정수입니다.
입출력 예
money	return
[1, 2, 3, 1]	4
*/

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> money) {
	int n = money.size();
	vector<int> dp1(n);
	dp1[0] = money[0];
	dp1[1] = dp1[0];
	for (int i = 2; i < n - 1; i++) {
		dp1[i] = max(dp1[i - 2] + money[i], dp1[i - 1]);
	}

	vector<int> dp2(n);
	dp2[1] = money[1];
	for (int i = 2; i < n; i++) {
		dp2[i] = max(dp2[i - 1], dp2[i - 2] + money[i]);
	}

	return max(dp1[n - 2], dp2[n - 1]);
}

/*
모범 답안
	i번째 집까지의 털 수 있는 최댓값은
	i-2번째 집까지의 털때의 최댓값에 i번째 집을 털때를 더하거나
	i번째 집을 털지 않고 i-1번째 집까지의 털때의 최댓값 둘 중 하나이다.


	1번 집을 털어서 마지막 집을 못 터는 경우와,
	1번 집을 털지 않아서 마지막 집을 털 수 있는 경우로 나눠서
	2개의 DP 배열을 적용해서 큰 값을 return한다.

	2가지 경우의 DP 배열을 각각 사용할 생각을 못했다.
	앞으로는 1차원, 2차원, N차원 DP 배열 뿐만아니라 N경우의 DP 배열도 생각해보자!


	시간복잡도
		O(N)
	공간복잡도
		O(N)
*/

/*
모범 답안 반영 전

	bottom up DFS에 메모이제이션을 적용해서 풀려고 했다.
	우선 아래와 같이 bottom up DFS를 구현했다.
	하지만 같은 L에서 같은 idx여도 어떤 flag를 지나왔느냐에 따라 최댓값이 달라지기에 메모이제이션을 적용할 수 없었다.

	시간복잡도
		O(2^N)
	공간복잡도
		O(N)

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int DFS(int, int);
// vector<vector<int>> save;
vector<int> flag;
vector<int> copyMoney;
int n, numOfVisit;

int solution(vector<int> money) {
	copyMoney = money;
	n = money.size();
	save.resize(n, vector<int>(n));
	flag.resize(n);
	return DFS(0,0);
}

int DFS(int L, int idx){
	// if(save[L][idx] > 0){
	//     return save[L][idx];
	// }
	vector<int> V;
	for(int i = 0; i < n; i++){
		if(flag[i] == 0){
			vector<int> temp = {i};
			int left = (i == 0 ? n - 1 : i - 1);
			int right = (i == n - 1 ? 0 : i + 1);
			if(flag[left] == 0) temp.push_back(left);
			if(flag[right] == 0) temp.push_back(right);
			for(int j = 0; j < temp.size(); j++){
				flag[temp[j]] = 1;
			}
			V.push_back(copyMoney[i] + DFS(L+1, i));
			for(int j = 0; j < temp.size(); j++){
				flag[temp[j]] = 0;
			}
		}
	}
	return V.empty() ? 0 : *max_element(V.begin(), V.end());
	// return save[L][idx] = V.empty() ? 0 : *max_element(V.begin(), V.end());
}
*/