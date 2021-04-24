/*
02-4. 스택 2-4(불필요한 괄호 판단)

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
문제 2-4) 불필요한 괄호 판단
	주어진 수식에 불필요한 괄호가 있지 않은지 확인하는 코드를 작성하라.

	예) ((1 + 2)) + 3 => true (불필요한 괄호가 있다.)
	예) 1 + (2 * 3) => false (산술적으로는 불필요하지만 이 문제에서는 이런 괄호는 유효하다고 가정한다.)
	예) 1 + (2) * 3 => true (2를 감싸고 있는 괄호는 불필요하다.)
*/

#include<iostream>
#include<string>
#include<stack>
using namespace std;

/*
풀이 2-4)
	닫는 괄호가 나왔을 때 스택에 사칙 연산 기호가 있는지 확인한다.

	시간 복잡도: O(N)
	공간 복잡도: O(N)
*/

bool isNeedLess(string input) {
	stack<char> S;
	for (int i = 0; i < input.size(); i++) {
		if (input[i] == '(' || input[i] == '+' || input[i] == '-' || input[i] == '*' || input[i] == '/') {
			S.push(input[i]);
		}
		else if (input[i] == ')') {
			if (S.top() == '(') return true;
			while (S.top() != '(') {
				S.pop();
			}
			S.pop();
		}
	}
	return false;
}


int main() {
	string example1 = "((1 + 2)) + 3";
	string example2 = "1 + (2 * 3)";
	string example3 = "1 + (2) * 3";

	cout << isNeedLess(example1) << endl;
	cout << isNeedLess(example2) << endl;
	cout << isNeedLess(example3) << endl;

	return 0;
}