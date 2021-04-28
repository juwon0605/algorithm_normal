/*
04-2. 스택 4-2(다음 큰 수 찾기)

스택
데이터 삽입과 삭제가 한쪽 끝에서 이루어지는 순서가 있는 특별한 형태의 리스트.
제일 먼저 추가된 데이터가 제일 마지막에 나간다. (FILO)
제일 마지막에 추가된 데이터가 제일 먼저 나간다. (LIFO)

스택 오퍼레이션
push: 데이터 추가
pop: 데이터를 꺼낸다
peek 또는 top: 맨 위에 있는 데이터를 조회한다. (스택에서 빼지는 않는다.)

스택 구현 방법
배열을 사용하는 방법
연결 리스트를 사용하는 방법

오퍼레이션 별 시간 복잡도
Push: O(1)
Pop: O(1)
Top: O(1)
*/

/*
문제 4-2) 다음 큰 수 찾기
	주어진 배열의 오른쪽에 처음으로 등장하는 현재 숫자보다 큰 수를 담고 있는 배열을 만드는 코드를 작성하라.
	오른쪽에 현재 수보다 큰수가 없는 경우에는 -1.

	예) [1, 1, 2, 3]	=>  [2, 2, 3, -1]
	예) [10, 4, 2, 30]	=>  [30, 30, 30, -1]
	예) [82, 7, 15]		=>  [-1, 15, -1]
*/

#include<iostream>
#include<stack>
using namespace std;

/*
풀이 ) 역순회하며 현재 값보다 큰 값만 남긴다. (현재 값보다 작으면 현재 값에 의미가 포함되어 있다)
	   S.empty()하면 -1을, 아니면 S.top()을 저장한다.

	시간 복잡도: O(N)
	공간 복잡도: O(N)
*/

int* nextBigNum(int arr[], int size) {
	int* resArr = new int[size];
	stack<int> S;
	resArr[size - 1] = -1;
	S.push(arr[size - 1]);
	for (int i = size - 2; i >= 0; i--) {
		while (!S.empty() && arr[i] >= S.top()) {
			S.pop();
		}
		resArr[i] = (S.empty() ? -1 : S.top());
		S.push(arr[i]);
	}
	return resArr;
}

int main() {
	int example1[] = { 1, 1, 2, 3 };
	int size1 = sizeof(example1) / sizeof(example1[0]);
	int example2[] = { 10, 4, 2, 30 };
	int size2 = sizeof(example2) / sizeof(example2[0]);
	int example3[] = { 82, 7, 15 };
	int size3 = sizeof(example3) / sizeof(example3[0]);

	int* res1 = nextBigNum(example1, size1);	// 2, 2, 3, -1
	int* res2 = nextBigNum(example2, size2);	// 30, 30, 30, -1
	int* res3 = nextBigNum(example3, size3);	// -1, 15, -1
	for (int i = 0; i < size1; i++) {
		cout << res1[i] << " ";
	}
	cout << endl;
	for (int i = 0; i < size2; i++) {
		cout << res2[i] << " ";
	}
	cout << endl;
	for (int i = 0; i < size3; i++) {
		cout << res3[i] << " ";
	}
	cout << endl;

	return 0;
}