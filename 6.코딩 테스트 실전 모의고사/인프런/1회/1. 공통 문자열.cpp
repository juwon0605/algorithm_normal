/*
1. 공통 문자열
설명
N개의 문자열이 주어지면 이 문자열들의 최대 공통 접두사를 출력하는 프로그램을 작성하세요.
만약 문자열들이 {“long", "longtime", "longest"} 라면 세 단어의 최대 공통 접두사는 ”long"입니다.
입력
첫 번째 줄에 자연수 N(3<=N<=30)이 주어집니다.
두 번째 줄부터 N개의 단어가 입력됩니다. 각 단어의 길이는 100을 넘지 않는다.
모든 문자열은 모두 소문자로 입력됩니다.
출력
첫 번째 줄에 최대 공통 접두사를 출력하세요.
예시 입력 1
3
long
longtime
longest
예시 출력 1
long
예시 입력 2
5
apple
apple
apple
apple
apple
예시 출력 2
apple
*/

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	freopen("input.txt", "rt", stdin);
	unordered_map<string, int> uM;
	string str, answer;
	int t, max = 0;
	cin >> t;
	while (t--) {
		cin >> str;
		string temp;
		for (int i = 0; i < str.size(); i++) {
			temp += str[i];
			uM[temp]++;
		}
	}
	for (auto iter = uM.begin(); iter != uM.end(); iter++) {
		if (max < iter->second) max = iter->second;
	}
	for (auto iter = uM.begin(); iter != uM.end(); iter++) {
		if (iter->second == max && (answer.size() < (iter->first).size())) answer = iter->first;
	}
	cout << answer;
	return 0;
}

/*
모범 답안
	시간복잡도
		O(MN)
	공간복잡도
		O(MN)
*/