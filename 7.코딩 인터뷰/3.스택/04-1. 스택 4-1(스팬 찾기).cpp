/*
04-1. 스택 4-1(스팬 찾기)

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
문제 4-1) 스팬 찾기
	주어진 배열 prices에 대한 스팬을 구하는 코드를 작성하라.
	스팬: 당일의 주가 보다 낮거나 같았던 연속적인 일 수.

	예) [5, 3, 2, 4, 7, 1]    =>   [1, 1, 1, 3, 5, 1]
	예) [2, 3, 4, 5, 6, 7]    =>   [1, 2, 3, 4, 5, 6]
*/

/*
출제 의도
	난이도: 보통
	문제를 이해하는 능력
	테스트를 하는가
	스택을 활용할 수 있는가
*/

#include<iostream>
#include<stack>
using namespace std;

/*
풀이 1) 이중 루프로 순회한다.

	시간 복잡도: O(N^2)
	공간 복잡도: O(N)
*/

/*
풀이 2) 스택에 인덱스를 저장하여 현재 인덱스와의 차이로 span을 O(1)에 구한다.
		순회하며 현재 값보다 큰 값만 스택에 남긴다. (현재 값보다 작으면 현재 값에 의미가 포함되어 있다)
		S.empty()하면 i+1을, 아니면 i - S.top()을 저장한다.

	시간 복잡도: O(N)
	공간 복잡도: O(N)
*/

int* calSpan(int prices[], int size) {
	int* spanArr = new int[size];
	stack<int> S;
	spanArr[0] = 1;
	S.push(0);
	for (int i = 1; i < size; i++) {
		while (!S.empty() && prices[S.top()] < prices[i]) {
			S.pop();
		}
		spanArr[i] = (S.empty() ? i + 1 : i - S.top());
		S.push(i);
	}
	return spanArr;
}

int main() {
	int prices1[] = { 5, 3, 2, 4, 7, 1 };
	int size1 = sizeof(prices1) / sizeof(prices1[0]);
	int prices2[] = { 2, 3, 4, 5, 6, 7 };
	int size2 = sizeof(prices2) / sizeof(prices2[0]);

	int* res1 = calSpan(prices1, size1);	// 1, 1, 1, 3, 5, 1
	int* res2 = calSpan(prices2, size2);	// 1, 2, 3, 4, 5, 6
	for (int i = 0; i < size1; i++) {
		cout << res1[i] << " ";
	}
	cout << endl;
	for (int i = 0; i < size2; i++) {
		cout << res2[i] << " ";
	}
	cout << endl;

	return 0;
}