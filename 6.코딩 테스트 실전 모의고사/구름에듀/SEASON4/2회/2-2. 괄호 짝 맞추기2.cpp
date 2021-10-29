/*
2-2. 괄호 짝 맞추기2
*/

#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;

int check(string);
vector<int> V;

int main() {
	string str;
	int t;
	cin >> t;
	while (t--) {
		cin >> str;
		int num = check(str);
		if (num == 0) {
			cout << V[0];
			for (int i = 1; i < V.size(); i++) {
				cout << " " << V[i];
			}
		}
		else {
			cout << num;
		}
		cout << "\n";
	}
	return 0;
}

int check(string input) {
	vector<int> tempV;
	stack<char> S;
	string open = "{[(";
	string close = "}])";
	for (int i = 0; i < input.size(); i++) {
		if (input[i] == '{' || input[i] == '[' || input[i] == '(') {
			tempV.push_back(S.size());
			S.push(input[i]);
		}
		else if (input[i] == '}' || input[i] == ']' || input[i] == ')') {
			if (S.empty()) return i;
			for (int j = 0; j < 3; j++) {
				if (input[i] == close[j] && S.top() != open[j]) return i;
			}
			S.pop();
			tempV.push_back(S.size());
		}
		else {
			tempV.push_back(S.size());
		}
	}
	if (S.empty()) {
		V = tempV;
		return 0;
	}
	else {
		return -1;
	}
}

/*
모범 답안
	시간복잡도
		O(TN)
	공간복잡도
		O(N)
*/