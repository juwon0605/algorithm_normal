/*
2. 모든 아나그램
설명
Anagram이란 두 문자열이 알파벳의 나열 순서를 다르지만 그 구성이 일치하면 두 단어는 아나그램이라고 합니다.
예를 들면 AbaAeCe 와 baeeACA 는 알파벳을 나열 순서는 다르지만 그 구성을 살펴보면 A(2), a(1), b(1), C(1), e(2)로
알파벳과 그 개수가 모두 일치합니다. 즉 어느 한 단어를 재 배열하면 상대편 단어가 될 수 있는 것을 아나그램이라 합니다.
하나의 문자열 S가 주어지면, S문자열에서 T문자열과 아나그램이 되는 연속된 부분문자열이 몇 개 있는지 구하는 프로그램을 작성하세요.
입력
첫 번째 줄에 길이 100,000을 넘지 않는 문자열 S가 주어집니다.
두 번째 줄에 길이 50,000을 넘지 않는 문자열 T가 주어집니다.(T길이<=S길이)
두 문자열의 모두 소문자로 입력됩니다.
출력
첫 번째 줄에 아나그램의 총개수를 출력합니다. 존재하지 않으면 0을 출력합니다.
예시 입력 1
eabcbacade
abc
예시 출력 1
3
힌트
출력설명
아나그램이 되는 연속된 부분 문자열은“abc", "cba", "bac" 총 3개입니다.
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
	unordered_map<char, int> sUM, tUM;
	string s, t;
	int res = 0;
	cin >> s >> t;
	for (int i = 0; i < t.size(); i++) {
		tUM[t[i]]++;
		sUM[s[i]]++;
	}
	if (sUM == tUM) res++;
	for (int i = t.size(); i < s.size(); i++) {
		sUM[s[i - t.size()]]--;
		if (sUM[s[i - t.size()]] == 0) sUM.erase(s[i - t.size()]);
		sUM[s[i]]++;
		if (sUM == tUM) res++;
	}
	cout << res;
	return 0;
}

/*
모범 답안

	두 unordered_map이 모든 key값과 value값이 같으면 == 연산자는 true를 return한다.

	시간복잡도
		O(N)
	공간복잡도
		O(N)
*/

/*
모범 답안 반영 전
	시간복잡도
		O(N)
	공간복잡도
		O(N)

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	freopen("input.txt", "rt", stdin);
	unordered_map<char, int> sUM, tUM;
	string s, t;
	int res = 0;
	bool check = true;
	cin >> s >> t;
	for (int i = 0; i < t.size(); i++) {
		tUM[t[i]]++;
		sUM[s[i]]++;
	}
	if (sUM.size() != tUM.size()) check = false;
	else {
		for (auto iter = tUM.begin(); iter != tUM.end(); iter++) {
			if (iter->second != sUM[iter->first]) {
				check = false;
				break;
			}
		}
	}
	if (check) res++;
	for (int i = t.size(); i < s.size(); i++) {
		sUM[s[i - t.size()]]--;
		if (sUM[s[i - t.size()]] == 0) sUM.erase(s[i - t.size()]);
		sUM[s[i]]++;
		check = true;
		if (sUM.size() != tUM.size()) check = false;
		else {
			for (auto iter = tUM.begin(); iter != tUM.end(); iter++) {
				if (iter->second != sUM[iter->first]) {
					check = false;
					break;
				}
			}
		}
		if (check) res++;
	}
	cout << res;
	return 0;
}
*/