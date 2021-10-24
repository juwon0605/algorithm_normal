/*
2. 펠린드롬 넘버 만들기
*/

#include <iostream>
#include <string>

using namespace std;

int F(int);
bool isValid(int);

int main() {
	int num, res = -1;
	cin >> num;
	for (int i = 0; i < 3; i++) {
		num = F(num);
		if (num >= 10000) {
			break;
		}
		if (isValid(num)) {
			res = num;
			break;
		}
	}
	cout << res;
	return 0;
}

int F(int num) {
	string str1, str2;
	str1 = to_string(num);
	for (int i = str1.size() - 1; i >= 0; i--) {
		str2 += str1[i];
	}
	return stoi(str1) + stoi(str2);
}
bool isValid(int num) {
	string str = to_string(num);
	for (int i = 0; i < str.size(); i++) {
		if (str[i] != str[str.size() - 1 - i]) {
			return false;
		}
	}
	return true;
}

/*
모범 답안
	시간복잡도
		O(L) (L: length of N)
	공간복잡도
		O(L)
*/