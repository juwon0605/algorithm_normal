/*
가장 긴 증가하는 부분 수열 2
문제
수열 A가 주어졌을 때, 가장 긴 증가하는 부분 수열을 구하는 프로그램을 작성하시오.
예를 들어, 수열 A = {10, 20, 10, 30, 20, 50} 인 경우에 가장 긴 증가하는 부분 수열은 A = {10, 20, 10, 30, 20, 50} 이고, 길이는 4이다.
입력
첫째 줄에 수열 A의 크기 N (1 ≤ N ≤ 1,000,000)이 주어진다.
둘째 줄에는 수열 A를 이루고 있는 Ai가 주어진다. (1 ≤ Ai ≤ 1,000,000)
출력
첫째 줄에 수열 A의 가장 긴 증가하는 부분 수열의 길이를 출력한다.
예제 입력 1
6
10 20 10 30 20 50
예제 출력 1
4
출처
문제를 만든 사람: baekjoon
데이터를 추가한 사람: harinboy, jh05013, surung9898, tony9402
*/

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	freopen("input.txt", "rt", stdin);
	int n;
	cin >> n;
	vector<int> numV(n);
	for(int i = 0; i < n; i++){
		cin >> numV[i];
	}

	vector<int> answerV;
	answerV.push_back(numV[0]);
	for(int i = 1; i < n; i++){
		if(answerV.back() < numV[i]){
			answerV.push_back(numV[i]);
		}
		else{
			auto iter = lower_bound(answerV.begin(), answerV.end(), numV[i]);
			*iter = numV[i];
		}
	}

	cout << answerV.size();
	return 0;
}

/*
모범 담안
	시간복잡도
		O(NlogN)
	공간복잡도
		O(N)
*/