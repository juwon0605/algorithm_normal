/*
문제 6-B
제목 연산자
내용
연산자가 가려진 식 6429 = 42에 대해 네모 안에 연산자 × 또는
를 넣어 등식이 성립하게 하려면 6×4+2×9와 같이 하면 된다. 그러나
2229 = 516과 같은 식은 × 또는 + 부호만으로는 등식을 성립하
게 할 수 없다. 이렇게 한 자리 숫자들 N개로 구성된 식들이 주어질 때 이
들 사이에 곱셈 또는 덧셈 기호를 넣어 주어진 등식이 만족되도록 할 수 있
는지를 판단하는 프로그램을 작성하시오. (주의사항: STL은 사용 가능하나,
기타 라이브러리는 사용을 금지함)
사용할 수 있는 언어는 C, C++로 제한한다. 프로그램의 실행 시간은 1초이
다. C++의 경우 main 함수 내의 시작 지점에 다음 내용을 추가하면 cin 입
력 속도가 개선되는 경우도 있다.
std::ios::sync_with_stdio(false);
입력 형식
입력은 표준입력으로 다음과 같이 주어진다. 첫 줄에는 테스트케이스의 수
T(≤ 100)가 주어지며, 둘째 줄부터는 테스트케이스들이 주어진다. 각 테스
트케이스는 다음과 같이 구성된다.
1. 각 테스트케이스의 첫 번째 줄에는 이 테스트케이스를 위한 식의 개수
M(≤ 100) 및 그 식들 각각의 좌변을 구성하는 숫자의 개수 N(≤ 8)이 빈
칸 하나를 사이에 두고 주어진다.
2. 두 번째 줄부터 M개의 줄에는 식이 한 줄에 하나씩 주어진다. 각 식은
좌변을 나타내는 N개의 한 자리 자연수와 우변을 나타내는 자연수 1개가
빈 칸 하나씩을 사이에 두고 주어진다.
출력 형식
출력은 표준출력으로 표시하며, 총 T줄로 구성된다. 각 테스트케이스 별로
M개의 식에 대해 1(가능) 또는 0(불가능)을 빈 칸 하나씩을 사이에 두고 한
줄에 출력한다.
예
입력
2
5 4 // 테스트케이스 1: 한 자리 숫자 4개로 구성된 좌변을 가지는 식 5개
6 4 2 9 42 // 테스트케이스 1의 문제 1: 6429 = 42
1 3 2 4 10
1 3 2 3 48
2 4 6 8 384
1 2 8 2 2356
3 2 // 테스트케이스 2: 한 자리 숫자 2개로 구성된 좌변을 가지는 식 3개
1 1 2
3 8 95
2 9 18
(empty line)
출력
1 1 0 1 0 // 1은 가능, 0은 불가능
1 0 1
(empty line)
*/
#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<string>
#include<stack>
using namespace std;

void DFS(int, string);
string infixToPostfix(string);
int calPriority(char);
int calPostfix(string);
int numArr[8];
int n, answer;
bool check;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	freopen("input.txt", "rt", stdin);
	int t, m;
	cin >> t;
	while (t--) {
		cin >> m >> n;
		while (m--) {
			check = false;
			fill(numArr, numArr + n, 0);
			for (int i = 0; i < n; i++) cin >> numArr[i];
			cin >> answer;
			DFS(1, to_string(numArr[0]));
			cout << (check == true ? 1 : 0) << " ";
		}
		cout << endl;
	}
	return 0;
}

void DFS(int L, string accum) {
	if (check == true) return;
	if (L == n) {
		string postfix = infixToPostfix(accum);
		int res = calPostfix(postfix);		
		if (res == answer) check = true;
	}
	else {
		DFS(L + 1, accum + ("+" + to_string(numArr[L])));
		DFS(L + 1, accum + ("*" + to_string(numArr[L])));
	}
}

string infixToPostfix(string input) {
	string postfix = "";
	stack<char> S;
	for (int i = 0; i < input.size(); i++) {
		if (input[i] - '0' > 0 && input[i] - '0' < 10) {
			postfix += input[i];
		}
		else if (input[i] == '+' || input[i] == '-' || input[i] == '*' || input[i] == '/') {
			if (S.empty()) {
				S.push(input[i]);
			}
			else {
				while (calPriority(input[i]) < calPriority(S.top())) {
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
	if (input == '+' || input == '-') return 1;
	else if (input == '*' || input == '/') return 2;
}

int calPostfix(string input) {
	stack<int> S;
	for (int i = 0; i < input.size(); i++) {
		if (input[i] - '0' > 0 && input[i] - '0' < 10) {
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