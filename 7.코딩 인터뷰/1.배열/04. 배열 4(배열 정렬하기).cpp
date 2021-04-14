/*
04. 배열 4(배열 정렬하기)

배열은 연속된 메모리 영역에 저장된 데이터로, 조회가 O(1), 추가 및 삭제가 O(n) 복잡도를 가지고 있다.
즉, 조회는 빠르고 추가 및 삭제는 느리다.
*/

/*
문제 4) 배열 정렬하기
	
	1부터 100 까지의 숫자 중에 50개의 랜덤한 숫자가 들어있는 배열이 있다. 이 배열을 O(n)의 시간 복잡도로 정렬하라.
*/

/*
출제 의도
	난이도: 보통
	배열의 인덱스를 활용하는 방법
	자바 배열의 최대 크기
*/

#include<iostream>
using namespace std;

/*
풀이 )
	값의 제한을 활용하여 Counting Sort한다.

	시간 복잡도: O(k)	(O(N) + O(K))
	공간 복잡도: O(K)	(K = 100)
*/

void solution1(int *numbers, int size) {
	int cntArr[101] = { 0 };
	for (int i = 0; i < size; i++) {
		cntArr[numbers[i]]++;
	}
	int idx = 0;
	for (int i = 1; i <= 100; i++) {
		if (cntArr[i] > 0) {
			while (cntArr[i]--) {
				numbers[idx++] = i;
			}
		}
	}
}

int main() {
	int numbers[] = { 9,8,7,6,5,4,3,3,3,2,2,1 };
	int size = sizeof(numbers) / sizeof(numbers[0]);

	solution1(numbers, size);
	for (int i = 0; i < size; i++) {
		cout << numbers[i] << " ";
	}
	return 0;
}