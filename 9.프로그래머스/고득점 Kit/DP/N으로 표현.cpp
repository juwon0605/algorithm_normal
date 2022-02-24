/*
N으로 표현
문제 설명
아래와 같이 5와 사칙연산만으로 12를 표현할 수 있습니다.

12 = 5 + 5 + (5 / 5) + (5 / 5)
12 = 55 / 5 + 5 / 5
12 = (55 + 5) / 5

5를 사용한 횟수는 각각 6,5,4 입니다. 그리고 이중 가장 작은 경우는 4입니다.
이처럼 숫자 N과 number가 주어질 때, N과 사칙연산만 사용해서 표현 할 수 있는 방법 중 N 사용횟수의 최솟값을 return 하도록 solution 함수를 작성하세요.

제한사항
N은 1 이상 9 이하입니다.
number는 1 이상 32,000 이하입니다.
수식에는 괄호와 사칙연산만 가능하며 나누기 연산에서 나머지는 무시합니다.
최솟값이 8보다 크면 -1을 return 합니다.
입출력 예
N	number	return
5	12	4
2	11	3
입출력 예 설명
예제 #1
문제에 나온 예와 같습니다.

예제 #2
11 = 22 / 2와 같이 2를 3번만 사용하여 표현할 수 있습니다.

출처

※ 공지 - 2020년 9월 3일 테스트케이스가 추가되었습니다.
*/

#include <string>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

int getNumberOfOnlyN(int, int);

int solution(int N, int number) {
	if (N == number) return 1;

	vector<unordered_set<long long>> DP(9);
	DP[1].insert(N);

	for (int i = 2; i <= 8; i++) {
		for (int j = 1; j <= i / 2; j++) {

			DP[i].insert(getNumberOfOnlyN(N, i));

			for (auto iter1 = DP[j].begin(); iter1 != DP[j].end(); iter1++) {
				for (auto iter2 = DP[i - j].begin(); iter2 != DP[i - j].end(); iter2++) {
					DP[i].insert(*iter1 + *iter2);
					if (*iter1 != *iter2) {
						DP[i].insert(abs(*iter1 - *iter2));
					}
					if (*iter1 > *iter2) {
						DP[i].insert(*iter1 / *iter2);
					}
					else {
						DP[i].insert(*iter2 / *iter1);
					}
					DP[i].insert(*iter1 * *iter2);
				}
			}

		}
		if (DP[i].find(number) != DP[i].end()) {
			return i;
		}
	}

	return -1;
}

int getNumberOfOnlyN(int N, int size) {
	int numberOfOnlyN = N;
	while (--size) {
		numberOfOnlyN = numberOfOnlyN * 10 + N;
	}
	return numberOfOnlyN;
}

/*
모범 답안

	시간복잡도
		O(4^K) (K = 8)(최솟값이 K보다 크면 -1을 return합니다.)
	공간복잡도
		O(4^K)
*/

/*
모범 답안 반영 전

	최단거리 문제라 BFS가 떠올라 구현해봤지만, 4/9만 맞았다.
	아래 풀이는 예외가 있을 것 같아서 틀릴 것 같기는 했는데 다른 풀이 방법이 생각이 안나서 구현해봤다.
	DP 문제인 걸 알고 있었지만, 1차원 DP 배열만 생각 하고 있어서 풀이 방법을 생각해내지 못했다.
	2차원 DP 배열도 있음을 숙지하고 풀이 방법을 고려해보자!

	시간복잡도
		O(4^K) (K = 8)(최솟값이 K보다 크면 -1을 return합니다.)
	공간복잡도
		O(4^K)

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;

bool isOnlyN(long long);
int copyN;

int solution(int N, int number) {
	int answer = 0;
	copyN = N;
	queue<pair<long long,int>> pairQ;
	unordered_set<long long> flag;
	pairQ.push(make_pair(number, 0));
	flag.insert(number);
	while(!pairQ.empty()){
		pair now = pairQ.front();
		pairQ.pop();
		if(isOnlyN(now.first)){
			return to_string(now.first).size() + now.second;
		}
		if(now.second >= 8){
			return -1;
		}
		if(now.first - N >= 0 && flag.find(now.first - N) == flag.end()){
			pairQ.push(make_pair(now.first - N, now.second + 1));
		}
		if(flag.find(now.first + N) == flag.end()){
			pairQ.push(make_pair(now.first + N, now.second + 1));
		}
		if(flag.find(now.first / N) == flag.end()){
			pairQ.push(make_pair(now.first / N, now.second + 1));
		}
		if(flag.find(now.first * N) == flag.end()){
			pairQ.push(make_pair(now.first * N, now.second + 1));
		}
	}
	return -1;
}

bool isOnlyN(long long number){
	string str = to_string(number);
	for(int i = 0; i < str.size(); i++){
		if(str[i] - '0' != copyN){
			return false;
		}
	}
	return true;
}
*/