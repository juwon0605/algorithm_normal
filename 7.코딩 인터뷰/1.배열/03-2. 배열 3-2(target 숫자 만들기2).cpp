/*
03-2. 배열 3-2(target 숫자 만들기2)

배열은 연속된 메모리 영역에 저장된 데이터로, 조회가 O(1), 추가 및 삭제가 O(n) 복잡도를 가지고 있다.
즉, 조회는 빠르고 추가 및 삭제는 느리다.
*/

/*
문제 3-2) target 숫자 만들기2
	
	숫자로 구성된 배열 numbers와 target 숫자 하나가 주어졌을 때 numbers 배열에 들어있는 수 세개를 더해서 target 숫자를 만들 수 있는 인덱스를 찾는 함수를 작성하라.

	예) numbers = [2, 3, 5, 7] target = 10, 10을 만들 수 있는 2, 3, 5의 인덱스인 0, 1, 2를 배열로 리턴해야 한다.
*/

#include<iostream>
#include<unordered_map>
using namespace std;

/*
풀이 )
	numbers를 이중으로 순회하면서 map을 2번씩 사용하여 확인한다.

	시간 복잡도: O(N^2)	(O(N) + O(N) * O(N))
	공간 복잡도: O(N)
*/

void solution1(int *numbers, int size, int target) {
	unordered_map<int, int> uM;
	for (int i = 0; i < size; i++) {
		uM.insert(make_pair(numbers[i], i));
		//uM[numbers[i]] = i;	// 이렇게 insert도 가능
	}
	for (int i = 0; i < size - 2; i++) {
		for (int j = i + 1; j < size; j++) {
			int other = target - numbers[i] - numbers[j];
			if (numbers[i] != numbers[j] && numbers[j] != other && other != numbers[i]
				&& uM.find(numbers[i]) != uM.end() && uM.find(numbers[j]) != uM.end() && uM.find(other) != uM.end()) {
				cout << "첫 번째 인덱스: " << i << endl;
				cout << "두 번째 인덱스: " << j << endl;
				cout << "세 번째 인덱스: " << uM.find(other)->second << endl;
				return;
			}
		}
	}
	cout << "해당 조건을 만족하는 숫자 조합이 없습니다." << endl;
}

int main() {
	int numbers[] = { 2,3,5,7 };
	int size = sizeof(numbers) / sizeof(numbers[0]);
	int target = 10;

	solution1(numbers, size, target);
	return 0;
}