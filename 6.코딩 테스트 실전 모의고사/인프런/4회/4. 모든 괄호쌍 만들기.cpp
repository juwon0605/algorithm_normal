/*
4. 모든 쌍의 괄호
설명
두 쌍의 괄호로 만들 수 있는 모든 괄호문자열의 경우는 (()), ()() 두가지입니다.
자연수 N이 입력되면 N쌍의 괄호로 만들 수 있는 모든 괄호문자열을 출력하는 프로그램을 작성하세요.
입력
첫째 줄에 자연수 N(3<=N<=10)이 주어집니다.
출력
매 줄에 모든 괄호문자열의 종류를 출력하고, 마지막 줄에 총 개수를 출력합니다.
괄호문자열의 출력순서는 출력예제처럼 해야 합니다.
예시 입력 1
3
예시 출력 1
((()))
(()())
(())()
()(())
()()()
5
*/

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
using namespace std;

void DFS(int, int, int);
int flag[20];
int n, res;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	freopen("input.txt", "rt", stdin);
	cin >> n;
	DFS(0, 0, 0);
	cout << res;
	return 0;
}

void DFS(int L, int left, int right) {
	if (left < right) return;
	if (L == 2 * n) {
		string str;
		for (int i = 0; i < 2 * n; i++) {
			str += (flag[i] == 0 ? "(" : ")");
		}
		cout << str << "\n";
		res++;
	}
	else {
		if (left < n) {
			flag[L] = 0;
			DFS(L + 1, left + 1, right);
		}
		if (right < n) {
			flag[L] = 1;
			DFS(L + 1, left, right + 1);
		}
	}
}

/*
모범 답안
	시간복잡도
		O(2^N)
	공간복잡도
		O(N)
*/

/*
모범 답안 반영 전

	DFS에서 left < right일때 바로 return하면 isValid 함수가 없어도 됨!

	시간복잡도
		O(2^N)
	공간복잡도
		O(N)

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <stack>
using namespace std;

void DFS(int,int,int);
bool isValid(string);
int flag[18];
int n, res;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	freopen("input.txt", "rt", stdin);
	cin >> n;
	DFS(0,0,0);
	cout << res;
	return 0;
}

void DFS(int L, int left, int right) {
	if (L == 2 * n - 2) {
		string str = "(";
		for (int i = 0; i < 2 * n - 2; i++) {
			str += (flag[i] == 0 ? "(" : ")");
		}
		str += ")";
		if (isValid(str)) {
			cout << str << "\n";
			res++;
		}
	}
	else {
		if (left < n - 1) {
			flag[L] = 0;
			DFS(L + 1, left + 1, right);
		}
		if (right < n - 1) {
			flag[L] = 1;
			DFS(L + 1, left, right + 1);
		}
	}
}

bool isValid(string str) {
	stack<char> S;
	for (int i = 0; i < str.size(); i++) {
		char c = str[i];
		if (c == '(') {
			S.push(c);
		}
		else {
			if (S.empty()) return false;
			S.pop();
		}
	}
	return true;
}
*/