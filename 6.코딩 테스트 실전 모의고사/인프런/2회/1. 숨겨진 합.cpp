/*
1. 숨겨진 합
설명
숫자와 문자가 섞여있는 문자열이 주어지면 숫자만을 추출하여 그 합을 구하는 프로그램을 작성하세요.
문자열에서 연속된 숫자는 하나의 숫자로 간주합니다. 연속된 숫자는 5자리를 넘지 않으며 연속된 숫자의 제일 앞자리의 0은 무시합니다.
만약 문자열에서 연속된 숫자가 "050"이라면 50입니다.
입력
첫 번째 줄에 길이 100을 넘지 않는 문자열 S가 주어집니다. 문자열은 대소문자와 0-9의 숫자로 이루어져 있습니다.
출력
첫 번째 줄에 총 합을 출력합니다.
예시 입력 1
ab050cdoj33eden17sd
예시 출력 1
100
*/

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	freopen("input.txt", "rt", stdin);
	string input, temp = "";
	int res = 0;
	cin >> input;
	for (int i = 0; i < input.size(); i++) {
		if (input[i] >= '0' && input[i] <= '9') {
			temp += input[i];
		}
		else if(temp != ""){
			res += stoi(temp);
			temp = "";
		}
	}
	if (temp != "") res += stoi(temp);
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