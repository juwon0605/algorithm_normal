/*
01. 코딩 인터뷰 프레임워크

문제를 푸는것 만이 목적이 아니라 문제를 동료와 같이 해결하는 과정이 중요하다.
	- 다만, 여기서 문제를 풀어나가는 주체가 “지원자".
	- "면접관"을 동료로 생각하고 같이 문제를 풀어나가야한다.

문제 풀이 프레임워크
	1.문제를 명확히 이해했는지 확인한다.
	2.가정하고 있거나 가정할 수 있는 것들을 확인한다.
	3.실제 예를 들어가며 다시 확인한다. (나중에 테스트 케이스로 활용할 수 있다.)
	4.문제 해결책을 고민한다.
	5.해결책을 설명하고 해당 시간과 공간 알고리듬 복잡도를 설명한다.
	6.코드를 작성한다.
	7.앞서 예시로 사용했던 입력값을 케이스로 삼아 코드를 테스트 한다.
*/

/*
퀴즈 1) 유일한 숫자 찾기
	numbers라는 int형 배열이 있다. 해당 배열에 들어있는 숫자들은 오직 한 숫자를 제외하고는
	모두 두번씩 들어있다. 오직 한 번만 등장하는 숫자를 찾는 코드를 작성하라.
*/

#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

/*
풀이 1)
	배열을 만들고 순회하면서 해당 숫자를 확인한다.
	배열에 있으면 빼내고, 없으면 넣는다.
	배열에는 유일한 숫자만 남으니 해당 숫자를 리턴한다.

	시간 복잡도: O(N^2) (O(N) * O(N))
	공간 복잡도: O(N)
*/

int solution1(int* numbers, int size) {
	vector<int> V;
	bool duplicatation;
	for (int i = 0; i < size; i++) {
		duplicatation = false;
		for (int j = 0; j < V.size(); j++) {
			if (numbers[i] == V[j]) {
				duplicatation = true;
				V.erase(V.begin() + j);
			}
		}
		if (!duplicatation) {
			V.push_back(numbers[i]);
		}
	}
	return V[0];
}

/*
풀이 2)
	HashMap을 사용해서 배열에 들어있는 숫자를 키, 등장 횟수를 값으로 저장한다.
	숫자의 등장 횟수가 1인 키값을 찾아서 리턴한다.

	시간 복잡도: O(N) (O(N) + O(N))
	공간 복잡도: O(N)
*/

int solution2(int* numbers, int size) {
	unordered_map<int, int> uM;
	for (int i = 0; i < size; i++) {
		uM[numbers[i]]++;
	}
	for (int i = 0; i < size; i++) {
		if (uM[numbers[i]] == 1) {
			return numbers[i];
		}
	}
	return 0;
}

/*
풀이 3)
	XOR 비트 연산자 (^)를 사용한다.
	XOR 비트 연산자는 순서와 상관 없이 동일한 숫자를 2번 연산하면 0이 된다.

	시간 복잡도: O(N)
	공간 복잡도: O(1)
*/

int solution3(int* numbers, int size) {
	int uniqueNum = 0;
	for (int i = 0; i < size; i++) {
		uniqueNum ^= numbers[i];
	}
	return uniqueNum;
}

int main() {
	int numbers[] = { 1,2,2,3,3 };
	int size = sizeof(numbers) / sizeof(numbers[0]);
	cout << solution1(numbers, size) << endl;	// 1
	cout << solution2(numbers, size) << endl;	// 1
	cout << solution2(numbers, size) << endl;	// 1
	return 0;
}