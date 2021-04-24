/*
01. 스택 1(스택 뒤집기)

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
출제 의도
	난이도: 보통
	스택을 이해하고 있는가?
	재귀적으로 생각하고 코드로 옮길 수 있는가?
*/

/*
문제 1) 스택 뒤집기
	스택을 뒤집는 코드를 작성하라.

	예) 1, 2, 3 -> 3, 2, 1
*/

#include<iostream>
#include<stack>
using namespace std;

/*
풀이 1)
	스택을 하나 더 사용한다.

	시간 복잡도: O(N)
	공간 복잡도: O(N)
*/

stack<int> reverseStack(stack<int> S) {
	stack<int> rS;
	while (!S.empty()) {
		rS.push(S.top());
		S.pop();
	}
	return rS;
}

/*
풀이 2)
	(다른 자료 구조를 사용하지 못한다면) 재귀적으로 한 스택만 사용한다.

	시간 복잡도: O(N^2)
	공간 복잡도: O(N)
*/

// 1.역순 방향 재귀 구현: 3 <- 2 <- 1 <- return;
void insertAtBottom(stack<int>*, int);
void reverseStack2(stack<int>* S) {
	if (S->empty()) {
		return;
	}
	else {
		int temp = S->top();
		S->pop();
		reverseStack2(S);
		insertAtBottom(S, temp);
	}
}
// 2.재귀 각 단계에서 주어진 num을 제일 밑에 넣는 재귀 구현
//        (1,2 / 3) <- (1 / 2) <- (empty / 1)
//   1
//   2        1
//   3   <-   2     <-    1    <-     x
void insertAtBottom(stack<int>* S, int num) {
	if (S->empty()) {
		S->push(num);
		return;
	}
	else {
		int temp = S->top();
		S->pop();
		insertAtBottom(S, num);
		S->push(temp);
	}
}

int main() {
	stack<int> S;
	for (int i = 1; i <= 3; i++) {
		S.push(i);
	}
	//S = reverseStack(S);
	reverseStack2(&S);
	while (!S.empty()) {
		cout << S.top() << " ";
		S.pop();
	}

	return 0;
}