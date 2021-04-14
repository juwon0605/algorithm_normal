/*
02. 배열 1(중복 숫자 확인)

배열은 연속된 메모리 영역에 저장된 데이터로, 조회가 O(1), 추가 및 삭제가 O(n) 복잡도를 가지고 있다.
즉, 조회는 빠르고 추가 및 삭제는 느리다.
*/

/*
문제 1) 중복 숫자 확인
	숫자로 구성된 배열이 주어졌을 때 그 배열에 중복된 숫자가 있는지 확인하는 함수를 작성하라.
	중복된 숫자가 있다면 true 없다면 false.

	예) 1 2 3 4 5 6 => false
	예) 1 1 2 2 3 1 => true
*/

/*
출제 의도
	난이도: 쉬움
	배열 조회, 순회, 조건문과 반복문 등 기본적인 프로그래밍 경험이 있는가?
	시간 복잡도와 공간 복잡도를 이해하고 있는가?
	지원자가 사용하는 언어의 기본 Sorting 알고리듬의 시간 복잡도와 공간 복잡도를 알고 있는가?
	해싱을 사용하는 Set의 오퍼레이션 시간 복잡도를 이해하고 있는가?
*/

#include<iostream>
#include<algorithm>
#include<unordered_set>
using namespace std;

/*
풀이 1)
	배열을 만들고 순회하면서 중복을 확인한다.

	시간 복잡도: O(N^2) (O(N) * O(N))
	공간 복잡도: O(1)
*/

bool solution1(int* numbers, int size) {
	for (int i = 0; i < size; i++) {
		for (int j = i+1; j < size; j++) {
			if (numbers[i] == numbers[j]) {
				return true;
			}
		}
	}
	return false;
}

/*
풀이 2)
	배열을 정렬하고 순회하면서 중복을 확인한다.
	sort: N이 크다면 퀵 정렬로 정의되어 있다. logN의 메모리를 사용한다.

	시간 복잡도: O(NlogN) (O(NlogN) + O(N))
	공간 복잡도: O(logN)
*/

bool solution2(int* numbers, int size) {
	sort(numbers, numbers + size);
	for (int i = 0; i < size - 1; i++) {
		if (numbers[i] == numbers[i + 1]) {
			return true;
		}
	}
	return false;
}

/*
풀이 3)
	set 자료구조를 사용해서 중복을 확인한다.

	시간 복잡도: O(N) (O(N) * O(1))
	공간 복잡도: O(N)
*/

bool solution3(int* numbers, int size) {
	unordered_set<int> uS;
	for (int i = 0; i < size; i++) {
		if (uS.find(numbers[i]) != uS.end()) {
			// find 성공 -> 해당 위치를 가리키는 iterator 반환
			// find 실패 -> uS.end()를 가리키는 iterator 반환
			return true;
		}
		else {
			uS.insert(numbers[i]);
		}
	}
	return false;
}

int main() {
	// []로 배열 선언
	int numbers1[] = { 1,2,2,3,3 };
	
	// *로 배열 선언
	int *numbers2 = new int[5];
	numbers2[0] = 1, numbers2[1] = 2, numbers2[2] = 2, numbers2[3] = 3, numbers2[4] = 4;
	
	// []의 크기 구하기
	int size1 = sizeof(numbers1) / sizeof(numbers1[0]);	// 5	(20 / 4)
	int size2 = _countof(numbers1);						// 5
	//int size3 = _msize(numbers1) / sizeof(numbers1[0]);	// error
	
	// *의 크기 구하기
	int size4 = sizeof(numbers2) / sizeof(numbers2[0]);	// 1	(8 / 8)
	//int size5 = _countof(numbers2);						// error
	int size6 = _msize(numbers2) / sizeof(numbers2[0]);	// 5	(40 / 8)

	/*
		주의사항1
		C++에서는 파라미터로 배열이 넘어가면 포인터로 넘어가서 함수내에서 크기를 구하기 어렵다.
		파라미터로 넘기기 전에 배열의 크기를 구해 같이 넘겨주는게 편하다.

		주의사항2
		[]이 아니라 *로 배열을 선언한 경우 포인터들의 포인터라 메모리 크기로 크기를 구해야한다.
		*로 선언된 배열의 경우 _msize(arr)를 사용해서 크기를 구할 수 있다.
		단, _msize()는 HEAP 영역의 변수(동적할당 변수)에만 사용할 수 있다.
	*/

	cout << solution1(numbers1, size1) << endl;
	cout << solution2(numbers1, size1) << endl;
	cout << solution3(numbers2, size6) << endl;
	return 0;
}

/*
모범 답안

*/

/*
모범 답안 반영 전

*/