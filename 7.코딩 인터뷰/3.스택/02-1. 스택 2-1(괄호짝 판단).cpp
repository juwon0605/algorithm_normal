/*
02-1. 스택 2-1(괄호짝 판단)

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
출제의도
	난이도: 쉬움
	스택이라는 데이터 구조를 활용할 수 있는가?
*/

/*
문제 2-1) 괄호짝 판단
	주어진 수식의 괄호짝이 맞는지 확인하는 코드를 작성하라.

	예) [{1 + 2 * (2 + 2)} - (1 - 3)]   => true
	예) [{1 + 2 * (2 + 2)} - [1 - 3)]   => false
*/

#include<iostream>
#include<string>
#include<stack>
using namespace std;

/*
풀이 )
	스택을 사용한다.

	시간 복잡도: O(N)
	공간 복잡도: O(N)
*/

bool check(string input) {
	stack<char> S;
	string open = "{[(";
	string close = "}])";
	for (int i = 0; i < input.size(); i++) {
		if (input[i] == '{' || input[i] == '[' || input[i] == '(') {
			S.push(input[i]);
		}
		else if (input[i] == '}' || input[i] == ']' || input[i] == ')') {
			if (S.empty()) return false;
			for (int j = 0; j < 3; j++) {
				if (input[i] == close[j] && S.top() != open[j]) {
					return false;
				}
			}
			S.pop();
		}
	}
	return S.empty();
}


int main() {
	string example1 = "[{1 + 2 * (2 + 2)} - (1 - 3)]";
	string example2 = "[{1 + 2 * (2 + 2)} - [1 - 3)]";
	
	cout << check(example1) << endl;
	cout << check(example2) << endl;

	return 0;
}