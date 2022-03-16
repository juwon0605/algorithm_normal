/*
[3차] 자동완성
문제 설명
자동완성
포털 다음에서 검색어 자동완성 기능을 넣고 싶은 라이언은 한 번 입력된 문자열을 학습해서 다음 입력 때 활용하고 싶어 졌다. 예를 들어, go 가 한 번 입력되었다면, 다음 사용자는 g 만 입력해도 go를 추천해주므로 o를 입력할 필요가 없어진다! 단, 학습에 사용된 단어들 중 앞부분이 같은 경우에는 어쩔 수 없이 다른 문자가 나올 때까지 입력을 해야 한다.
효과가 얼마나 좋을지 알고 싶은 라이언은 학습된 단어들을 찾을 때 몇 글자를 입력해야 하는지 궁금해졌다.

예를 들어, 학습된 단어들이 아래와 같을 때

go
gone
guild
go를 찾을 때 go를 모두 입력해야 한다.
gone을 찾을 때 gon 까지 입력해야 한다. (gon이 입력되기 전까지는 go 인지 gone인지 확신할 수 없다.)
guild를 찾을 때는 gu 까지만 입력하면 guild가 완성된다.
이 경우 총 입력해야 할 문자의 수는 7이다.

라이언을 도와 위와 같이 문자열이 입력으로 주어지면 학습을 시킨 후, 학습된 단어들을 순서대로 찾을 때 몇 개의 문자를 입력하면 되는지 계산하는 프로그램을 만들어보자.

입력 형식
학습과 검색에 사용될 중복 없는 단어 N개가 주어진다.
모든 단어는 알파벳 소문자로 구성되며 단어의 수 N과 단어들의 길이의 총합 L의 범위는 다음과 같다.

2 <= N <= 100,000
2 <= L <= 1,000,000
출력 형식
단어를 찾을 때 입력해야 할 총 문자수를 리턴한다.

입출력 예제
words	result
["go","gone","guild"]	7
["abc","def","ghi","jklm"]	4
["word","war","warrior","world"]	15
입출력 설명
첫 번째 예제는 본문 설명과 같다.
두 번째 예제에서는 모든 단어들이 공통된 부분이 없으므로, 가장 앞글자만 입력하면 된다.
세 번째 예제는 총 15 자를 입력해야 하고 설명은 아래와 같다.
word는 word모두 입력해야 한다.
war는 war 까지 모두 입력해야 한다.
warrior는 warr 까지만 입력하면 된다.
world는 worl까지 입력해야 한다. (word와 구분되어야 함을 명심하자)
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<string> words) {
	int answer = 0;
	sort(words.begin(), words.end());

	for (int i = 0; i < words.size(); i++) {
		string str1;
		string str2;
		bool check = true;
		for (int j = 0; j < words[i].size() - 1; j++) {
			str1 += words[i][j];
			str2 = str1.substr(0, str1.size() - 1);
			str2 += str1.back() + 1;
			if (lower_bound(words.begin(), words.end(), str1) + 1 ==
				lower_bound(words.begin(), words.end(), str2)) {
				answer += j + 1;
				check = false;
				break;
			}
		}
		if (check) {
			answer += words[i].size();
		}
	}

	return answer;
}

/*
모범 풀이

	정렬 후, 매번 이분탐색 2번 사용해서 사이에 한 개 밖에 없는지 확인
	
	시간복잡도
		O(LlogN)
	공간복잡도
		O(L)
*/

/*
다른 모범 답안1

	정렬 후 순회하면서 계산

	시간복잡도
		O(L)
	공간복잡도
		O(L)

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<string> words) {
	int ans = 1, pre = 0;
	sort(words.begin(), words.end());
	string pre_word = words[0]; //정렬된 첫번째 단어

	for (int cur = 1; cur < words.size(); cur++) {//단어 개수만큼 반복
		int idx = 0;
		for (; idx <= words[cur].size(); idx++) { //입력된 단어 순서대로
			if (idx >= pre_word.size()) { //현재 idx가 이전 단어보다 크다면
				ans += pre_word.size() - pre - 1;
				ans += idx + 1;
				break;
			}
			if (words[cur][idx] != pre_word[idx]) { //현재 단어랑 이전 단어 스펠링이 다르다면
				if (idx > pre)
					ans += idx - pre;
				ans += idx + 1;
				break;
			}
		}
		pre = idx;
		pre_word = words[cur];
	}

	return ans;
}
*/

/*
다른 모범 답안2

	TRIE 자료구조 구현

	시간복잡도
		O(L)
	공간복잡도
		O(L)

#include <string>
#include <vector>

using namespace std;

struct TRIE
{
	TRIE *Node[26];
	int Child;
	bool Finish;

	void Insert(const char *Str);
	int Find(const char *Str, int Cnt);
};

int Trie_Idx;
TRIE Nodepool[1000010];

TRIE *Nodeset()
{
	TRIE *NewNode = &Nodepool[Trie_Idx++];
	for (int i = 0; i < 26; i++) NewNode->Node[i] = NULL;
	NewNode->Child = 0;

	return NewNode;
}

void TRIE::Insert(const char *Str)
{
	Child++;
	if (*Str == NULL)
	{
		Finish = true;
		return;
	}

	int Cur = *Str - 'a';
	if (Node[Cur] == NULL) Node[Cur] = Nodeset();
	Node[Cur]->Insert(Str + 1);
}

int TRIE::Find(const char *Str, int Cnt)
{
	if (Child == 1 || *Str == NULL) return Cnt;

	int Cur = *Str - 'a';
	return Node[Cur]->Find(Str + 1, Cnt + 1);
}

int solution(vector<string> words)
{
	Trie_Idx = 0;
	int answer = 0;
	int N = words.size();
	TRIE *Root = Nodeset();
	for (int i = 0; i < N; i++) Root->Insert(words[i].c_str());
	for (int i = 0; i < N; i++) answer = answer + Root->Find(words[i].c_str(), 0);

	return answer;
}

//출처: https://yabmoons.tistory.com/490 [얍문's Coding World..]
*/