/*
02-2. 스택 2-2(닫힌 괄호의 위치)

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
문제 2-2) 닫힌 괄호의 위치
	괄호 수식과 여는 괄호의 위치가 주어졌을 때 그에 대응하는 닫힌 괄호의 위치를 찾는 코드를 작성하라.

	예) [{1+2*(2+2)}-(1-3)], 1   => 11 (‘{‘에 대응하는 ‘}’가 11번째 위치에 있다.
*/

#include<iostream>
#include<string>
#include<stack>
using namespace std;

/*
풀이 2-2)
	스택을 사용한다.

	시간 복잡도: O(N)
	공간 복잡도: O(N)
*/

int positionOfPair(string input, int position) {
	stack<char> S;
	string open = "{[(";
	string close = "}])";
	S.push(input[position]);
	for (int i = position + 1; i < input.size(); i++) {
		if (input[i] == '{' || input[i] == '[' || input[i] == '(') {
			S.push(input[i]);
		}
		else if (input[i] == '}' || input[i] == ']' || input[i] == ')') {
			for (int j = 0; j < 3; j++) {
				if (input[i] == close[j] && S.top() != open[j]) {
					return -1;
				}
			}
			S.pop();
			if (S.empty()) return i;
		}
	}
	return -1;
}


int main() {
	string example = "[{1+2*(2+2)}-(1-3)]";
	
	cout << positionOfPair(example, 1) << endl;
	cout << positionOfPair(example, 0) << endl;
	cout << positionOfPair(example, 6) << endl;

	return 0;
}