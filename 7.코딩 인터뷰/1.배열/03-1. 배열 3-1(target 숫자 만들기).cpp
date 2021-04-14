/*
03-1. 배열 3-1(target 숫자 만들기)

배열은 연속된 메모리 영역에 저장된 데이터로, 조회가 O(1), 추가 및 삭제가 O(n) 복잡도를 가지고 있다.
즉, 조회는 빠르고 추가 및 삭제는 느리다.
*/

/*
문제 3) target 숫자 만들기
	숫자로 구성된 배열 numbers와 target 숫자 하나가 주어졌을 때 numbers 배열에 들어있는 두 수를 더해 target 숫자를 만들 수 있는 인덱스 두개를 찾는 함수를 작성하라.

	예) numbers = [2, 3, 5, 7] target = 8, 8을 만들 수 있는 3과 5의 인덱스인 1, 2를 리턴해야 한다.
	예) numbers = [1, 2, 6, 8] target = 9, 9를 만들 수 있는 1과 8의 인덱스인 0, 3을 리턴해야 한다.

	numbers 배열에 중복되는 숫자는 없으며 target 숫자를 만들 수 있는 조합은 하나 뿐이라고 가정해도 좋다. 
*/

/*
출제 의도
	난이도: 보통
	배열 순회 및 출력
	HashMap의 오퍼레이션을 이해하고 있는가?
	2Sum 문제를 3Sum 문제로 바꿔도 해결할 수 있을까?
*/

#include<iostream>
#include<unordered_map>
using namespace std;

/*
풀이 1)
	numbers를 순회하면서 모든 경우의 수를 확인한다.

	시간 복잡도: O(N^2)
	공간 복잡도: O(1)
*/

void solution1(int *numbers, int size, int target) {
	for (int i = 0; i < size - 1; i++) {
		for (int j = i + 1; j < size; j++) {
			if (numbers[i] + numbers[j] == target) {
				cout << "첫 번째 인덱스: " << i << endl;
				cout << "두 번째 인덱스: " << j << endl;
				return;
			}
		}
	}
	cout << "해당 조건을 만족하는 숫자 조합이 없습니다." << endl;
}

/*
풀이 2)
	map를 사용하여 확인한다.

	시간 복잡도: O(N)	(O(N) + O(N))
	공간 복잡도: O(N)
*/

void solution2(int *numbers, int size, int target) {
	unordered_map<int, int> uM;
	for (int i = 0; i < size; i++) {
		uM.insert(make_pair(numbers[i], i));
		//uM[numbers[i]] = i;	// 이렇게 insert도 가능
	}
	for (int i = 0; i < size; i++) {
		int other = target - numbers[i];
		if (other != numbers[i] && uM.find(other) != uM.end()) {
			cout << "첫 번째 인덱스: " << i << endl;
			cout << "두 번째 인덱스: " << uM.find(other)->second << endl;
			return;
		}
	}
	cout << "해당 조건을 만족하는 숫자 조합이 없습니다." << endl;
}

int main() {
	int numbers[] = { 2,3,5,7 };
	int size = sizeof(numbers) / sizeof(numbers[0]);
	int target = 9;

	solution1(numbers, size, target);
	solution2(numbers, size, target);
	return 0;
}