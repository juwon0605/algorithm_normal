/*
3. 단어 찾아내기
*/

#include <iostream>
#include <string>

using namespace std;

bool isVowel(char);

int main() {
	string str;
	int res1 = 0, res2 = 0;
	while (cin >> str) {
		if (str.size() < 2) continue;
		for (int i = 1; i < str.size(); i++) {
			if (isVowel(str[i - 1]) && isVowel(str[i])) {
				res1++;
				break;
			}
		}
		if (str.size() < 3) continue;
		for (int i = 2; i < str.size(); i++) {
			if (!isVowel(str[i - 2]) && !isVowel(str[i - 1]) && !isVowel(str[i])) {
				res2++;
				break;
			}
		}
	}
	cout << res1 << "\n";
	cout << res2;
	return 0;
}

bool isVowel(char c) {
	if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
		return true;
	}
	return false;
}


/*
모범 답안
	시간복잡도
		O(TL)	(L: length of words[i])
	공간복잡도
		O(L)
*/