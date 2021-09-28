/*
1. unique한 문자열
설명
N개의 문자열이 주어지면 각 문자열에서 특정문자(알파벳)가 존재하는 문자열을 찾아 그 문자열을 “unique한 문자열”로 만들어 출력하는 프로그램을 작성하세요.
특정문자는 대소문자를 구별하지 않습니다.
여기서 “unique한 문자열”이란 해당 문자열을 모두 대문자로 통일하고, 그 순서는 유지하면서 중복된 문자는 한 번만 사용되게 만든 문자열입니다.
만약 어떤 문자열이 "Remember" 라면 이 문자열의“unique한 문자열”은 “REMB”입니다.
입력
첫 줄에 한 줄에 자연수 N(3<=N<=100)과 특정문자가 주어집니다.
두 번째 줄에 N개의 줄에 걸쳐 문자열이 N개 입력됩니다.
출력
첫 줄부터 특정문자가 있는 문자열을 unique한 문자열로 변환한 다음 출력합니다.
예시 입력 1
5 b
Queen
Apple
Best
Remember
Beer
예시 출력 1
BEST
REMB
BER
*/

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	freopen("input.txt", "rt", stdin);
	string str;
	int n;
	char c;
	cin >> n >> c;
	if (c >= 'a' && c <= 'z') c -= ('a' - 'A');
	for (int i = 0; i < n; i++) {
		cin >> str;
		unordered_set<char> uS;
		for (int j = 0; j < str.size(); j++) {
			if (str[j] >= 'a' && str[j] <= 'z') str[j] -= ('a' - 'A');
			uS.insert(str[j]);
		}
		if (uS.find(c) != uS.end()) {
			for (int j = 0; j < str.size(); j++) {
				if (uS.find(str[j]) != uS.end()) {
					cout << str[j];
					uS.erase(str[j]);
				}
			}
			cout << "\n";
		}
	}
	return 0;
}

/*
모범 답안
	시간복잡도
		O(N)
	공간복잡도
		O(N)
*/