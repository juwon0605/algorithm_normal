﻿/*
03-1. 스택 3-1(포스트픽스 계산하기)

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
문제 3-1) 포스트픽스 계산하기
	포스트픽스로 주어진 식을 계산하는 코드를 작성하라. 수식은 사칙연산 (+, -, *, /)만 사용한다고 가정한다.

	예) 12+         => 3
	예) 123+-5*  => -20

	인픽스: 수식 앞 뒤로 피연산자를 두는 표기법. 예) (1 - (2 + 3)) * 5
	프리픽스: 수식 뒤에 피연산자 두개를 두는 표기법. 예) *-+2315
	포스트픽스: 수식을 피연산자 두개 뒤에 두는 표기법. 예) 123+-5*
*/

/*
출제 의도
	난이도: 보통에서 어려움
	문제를 이해력할 수 있는가. (예제를 들며 생각하는지 적절한 시간내에 문제를 이해하는지 살펴볼 것)
	규칙을 찾을 수 있는가.
	스택을 활용할 수 있는가.
	테스트를 하는가.
*/

#include<iostream>
#include<string>
#include<stack>
using namespace std;

/*
풀이 ) 숫자면 스택에 push하고 연산자면 스택에서 두 숫자를 꺼내 계산하여 다시 스택에 push한다.

	시간 복잡도: O(N)
	공간 복잡도: O(N)
*/

int calPostfix(string input) {
	stack<int> S;
	for (int i = 0; i < input.size(); i++ ) {
		if (input[i] - '0' >= 0 && input[i] - '0' <= 9) {
			S.push(input[i] - '0');
		}
		else {
			int right = S.top();
			S.pop();
			int left = S.top();
			S.pop();
			switch (input[i]) 
			{
			case '+':
				S.push(left + right);
				break;
			case '-':
				S.push(left - right);
				break;
			case '*':
				S.push(left * right);
				break;
			case '/':
				S.push(left / right);
				break;
			}
		}
	}
	return S.top();
}

int main() {
	string example = "123+-5*";

	cout << calPostfix(example) << endl;

	return 0;
}