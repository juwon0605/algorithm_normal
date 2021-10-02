/*
1. 패턴 찾기
설명
철수는 어떤 규칙에 의하여 숫자를 N개 썼습니다. 철수가 규칙에 의하여 쓴 숫자들의 총 합은 얼마인지 구하여 출력하는 프로그램을 작성하세요.
만약 철수가 다음과 같은 규칙으로 20개의 숫자를 썼다면 패턴은 32102이고 쓴 숫자의 총 합은 32입니다.
3210232102321……
패턴은 처음 쓴 숫자부터 시작된다. 패턴의 길이는 최소 3이상이다. 그리고 반드시 존재한다.
입력
첫 번째 줄에 철수가 쓴 숫자의 첫 부분이 주어진다. 패턴이 발견될 정도의 정보는 주어진다. 첫 줄은 길이가 50을 넘지는 않는다.
두 번째 줄에는 자연수 N(10<=N<=100,000,000)이 주어진다.
출력
총합을 출력한다.
예시 입력 1
3210232102321023
52
예시 출력 1
85
*/

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
using namespace std;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	freopen("input.txt", "rt", stdin);
	string str, pattern;
	int n, sum = 0, res = 0;
	cin >> str >> n;
	for (int i = 0; i < str.size(); i++) {
		pattern += str[i];
		bool isPattern = true;
		for (int j = i + 1; j + pattern.size() - 1 < str.size(); j += pattern.size()) {
			if (pattern != str.substr(j, pattern.size())) {
				isPattern = false;
				break;
			}
		}
		if (isPattern) break;
	}
	for (int i = 0; i < pattern.size(); i++) {
		sum += pattern[i] - '0';
	}
	res += sum * (n / pattern.size());
	for (int i = 0; i < n % pattern.size(); i++) {
		res += pattern[i] - '0';
	}
	cout << res;
	return 0;
}

/*
모범 답안
	시간복잡도
		O(N^2)
	공간복잡도
		O(N)
*/