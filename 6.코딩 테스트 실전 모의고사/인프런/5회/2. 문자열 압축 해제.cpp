/*
2. 문자열 압축 해제
설명
압축된 결과의 문자열이 주어지면 다시 원 상태로 압축을 해제하여 출력하는 프로그램을 작성하세요.
압축된 결과는 3(ab) 라고 주어지면 괄호안에 문자열이 3번 반복된 것을 압축했다는 의미입니다. 이걸 원상태로 해제한 것은 “ababab”입니다.
만약 2(ab)(k)3(bc) 를 압축해제 하면 "ababkbcbcbc"입니다. 2(ab)(k)3(bc)에서 (k)문자열과 같이 반복횟수가 1인 경우는 숫자를 생략합니다.
입력
첫 번째 줄에 압축된 결과가 주어집니다. 각 문자열의 반복횟수는 30을 넘지 않습니다.
압축을 해제했을 경우 총 길이는 1000을 넘지 않도록 입력이 주어집니다.
문자는 소문자로만 주어집니다.
출력
첫 번째 줄에 압축을 해제한 결과를 출력합니다.
예시 입력 1
2(ab)(k)3(bc)
예시 출력 1
ababkbcbcbc
*/

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <vector>
using namespace std;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	freopen("input.txt", "rt", stdin);
	vector<string> strV;
	string str, res, temp;
	cin >> str;
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == ')') {
			strV.push_back(temp);
			temp = "";
		}
		else {
			temp += str[i];
		}
	}
	for (int i = 0; i < strV.size(); i++) {
		temp = "";
		for (int j = 0; j < strV[i].size(); j++) {
			if (strV[i][j] == '(') {
				int k = (temp != "" ? stoi(temp) : 1);
				while (k--) res += strV[i].substr(j + 1);
				break;
			}
			else {
				temp += strV[i][j];
			}
		}
	}
	cout << res;
	return 0;
}

/*
모범 답안
	시간복잡도
		O(N)
	공간복잡도
		O(N)
*/