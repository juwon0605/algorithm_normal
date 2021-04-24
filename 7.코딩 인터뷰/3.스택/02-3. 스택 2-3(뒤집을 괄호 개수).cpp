/*
02-3. 스택 2-3(뒤집을 괄호 개수)

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
문제 2-3) 뒤집을 괄호 개수
	괄호 몇개를 뒤집어야 정상적인 수식을 만들 수 있는지 계산하는 코드를 작성하라.

	예) {{{}} => exception
	예) {{{{}} => 1
	예) }}}}{}}} => 3
	예) {{{{ => 2
*/

#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

/*
풀이 2-3)
	여는 괄호와 닫는 괄호의 개수 차이로 판단한다.

	시간 복잡도: O(N)
	공간 복잡도: O(1)
*/

int calNumOfReverse(string input) {
	int open = 0;
	int close = 0;
	for (int i = 0; i < input.size(); i++) {
		if (input[i] == '{') {
			open++;
		}
		else if (input[i] == '}') {
			close++;
		}
	}
	int sub = abs(open - close);
	return (sub % 2 == 0 ? sub / 2 : -1);
}


int main() {
	string example1 = "{{{}}";
	string example2 = "{{{{}}";
	string example3 = "}}}}{}}}";
	string example4 = "{{{{";

	cout << calNumOfReverse(example1) << endl;
	cout << calNumOfReverse(example2) << endl;
	cout << calNumOfReverse(example3) << endl;
	cout << calNumOfReverse(example4) << endl;

	return 0;
}