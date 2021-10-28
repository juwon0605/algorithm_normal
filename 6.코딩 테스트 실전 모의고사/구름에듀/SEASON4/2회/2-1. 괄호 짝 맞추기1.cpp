/*
2-1. 괄호 짝 맞추기1
*/

#include <iostream>
#include <string>
#include <stack>
using namespace std;

bool check(string);

int main() {
	string str;
	int t;
	cin >> t;
	while (t--) {
		cin >> str;
		cout << (check(str) ? "YES" : "NO") << "\n";
	}
	return 0;
}

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
				if (input[i] == close[j] && S.top() != open[j]) return false;
			}
			S.pop();
		}
	}
	return S.empty();
}

/*
모범 답안
	시간복잡도
		O(TN)
	공간복잡도
		O(N)
*/