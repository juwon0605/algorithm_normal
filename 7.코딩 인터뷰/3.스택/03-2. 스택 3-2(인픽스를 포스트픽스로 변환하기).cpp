/*
03-2. 스택 3-2(인픽스를 포스트픽스로 변환하기)

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
문제 3-2) 인픽스를 포스트픽스로 변환하기
	인픽스로 주어진 식을 포스트픽스로 변환하는 코드를 작성하라. 수식은 사칙연산 (+, -, *, /)만 사용한다고 가정한다.

	예) (1 - (2 + 3)) * 5 => 123+-5*

	인픽스: 수식 앞 뒤로 피연산자를 두는 표기법. 예) (1 - (2 + 3)) * 5
	프리픽스: 수식 뒤에 피연산자 두개를 두는 표기법. 예) *-+2315
	포스트픽스: 수식을 피연산자 두개 뒤에 두는 표기법. 예) 123+-5*
*/

#include<iostream>
#include<string>
#include<stack>
using namespace std;

/*
풀이 ) 숫자면 string에 +=해주고
	   연산자면 우선순위를 비교해서 S.push() or (string += S.top() && S.pop())하고
	   '('이면 S.push(), ')'이면 '('이 나올때까지 string += S.top() && S.pop()한다.

	시간 복잡도: O(N)
	공간 복잡도: O(N)
*/

int calPriority(char);
string infixToPostfix(string input) {
	string postfix = "";
	stack<char> S;
	for (int i = 0; i < input.size(); i++) {
		if (input[i] - '0' >= 0 && input[i] - '0' <= 9) {
			postfix += input[i];
		}
		else if (input[i] == '+' || input[i] == '-' || input[i] == '*' || input[i] == '/' || input[i] == '(' || input[i] == ')') {
			if (S.empty() || input[i] == '(') {
				S.push(input[i]);
			}
			else if (input[i] == ')'){
				while (S.top() != '(') {
					postfix += S.top();
					S.pop();
				}
				S.pop();
			}
			else {
				while (calPriority(input[i]) <= calPriority(S.top())) {
					postfix += S.top();
					S.pop();
					if (S.empty()) break;
				}
				S.push(input[i]);
			}
		}
	}
	while (!S.empty()) {
		postfix += S.top();
		S.pop();
	}
	return postfix;
}

int calPriority(char input) {
	if (input == '(' || input == ')') return 0;
	else if (input == '+' || input == '-') return 1;
	else if (input == '*' || input == '/') return 2;
}

int main() {
	string example = "(1 - (2 + 3)) * 5";

	cout << infixToPostfix(example) << endl;

	return 0;
}