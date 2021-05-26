/*
01. 큐 1(큐 뒤집기)

큐(Queue)
스택과 비슷한 데이터 구조이지만, 데이터 삽입과 삭제가 각기 다른 쪽에서 이루어지는 정렬된 리스트이다.
가장 처음에 삽입된 데이터가 제일 먼저 삭제된다. (FIFO)
가장 마지막에 삽입된 데이터가 제일 마지막에 삭제된다. (LILO)

큐 오퍼레이션
EnQueue: 큐에 데이터 넣기
DeQueue: 큐에서 데이터 빼기

큐 구현
(동적) 원형 배열
연결 리스트

오퍼레이션 별 시간 복잡도
EnQueue: O(1)
DeQueue: O(1)

자바의 Queue 인터페이스
add(E e): 넣을 수 있으면 넣고 true를 리턴, 더이상 큐에 넣을 수 없을 때는 IllegalStateException을 던진다.
offer(E e): 넣을 수 있으면 넣고 true를 리턴, 넣을 수 없는 경우에는 false 리턴.
E remove(): 꺼낼 수 있으면 꺼내주고 꺼낼 것이 없으면 NoSuchElementException을 던진다.
E poll(): 꺼낼 수 있으면 꺼내주고 없으면 null 리턴.
E element(): 큐의 head에 들어있는 값을 리턴하지만 큐에서 빼지는 않는다. 큐에 데이터가 없으면 NoSuchElementException을 던진다.
E peek(): 큐의 head에 들어있는 값을 리턴하지만 큐에서 빼지는 않는다. 큐에 데이터가 없으면 null 리턴.

*/

/*
출제 의도
	난이도: 쉬움
	큐를 이해하고 있는가?
	재귀를 사용할 수 있는가?
*/

/*
문제 1) 큐 뒤집기
	큐가 제공하는 오퍼레이션만 사용해서 큐를 뒤집는 코드를 작성하라.
	제공하는 오퍼레이션은 다음과 같다.
	offer(E e): 큐의 끝에 데이터를 추가한다.
	E poll(): 큐 헤드를 꺼낸다.
	isEmpty(): 큐가 비어있는가.

	예) Q {1, 2, 3}  =>  Q {3, 2, 1}
*/

#include<iostream>
#include<queue>
#include<stack>
using namespace std;

/*
풀이 1)
	스택을 사용해서 뒤집는다.

	시간 복잡도: O(N)
	공간 복잡도: O(N)
*/

void reverseQueue1(queue<int>* Qptr) {
	stack<int> S;
	while (!Qptr->empty()) {
		S.push(Qptr->front());
		Qptr->pop();
	}
	while (!S.empty()) {
		Qptr->push(S.top());
		S.pop();
	}
}

/*
풀이 2)
	재귀를 사용해서 뒤집는다.

	시간 복잡도: O(N)
	공간 복잡도: O(N)
*/

// 역순 방향 재귀 구현: 1 <- 2 <- 3 <- return;
void reverseQueue2(queue<int>* Qptr) {
	if (Qptr->empty()) {
		return;
	}
	else {
		int temp = Qptr->front();
		Qptr->pop();
		reverseQueue2(Qptr);
		Qptr->push(temp);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	queue<int> Q;
	int size = 3;
	for (int i = 1; i <= size; i++) {
		Q.push(i);
	}
	//reverseQueue1(&Q);
	reverseQueue2(&Q);
	while (!Q.empty()) {
		cout << Q.front() << " ";
		Q.pop();
	}
	return 0;
}