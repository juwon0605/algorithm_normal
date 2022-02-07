/*
단어 변환
문제 설명
두 개의 단어 begin, target과 단어의 집합 words가 있습니다. 아래와 같은 규칙을 이용하여 begin에서 target으로 변환하는 가장 짧은 변환 과정을 찾으려고 합니다.

1. 한 번에 한 개의 알파벳만 바꿀 수 있습니다.
2. words에 있는 단어로만 변환할 수 있습니다.
예를 들어 begin이 "hit", target가 "cog", words가 ["hot","dot","dog","lot","log","cog"]라면 "hit" -> "hot" -> "dot" -> "dog" -> "cog"와 같이 4단계를 거쳐 변환할 수 있습니다.

두 개의 단어 begin, target과 단어의 집합 words가 매개변수로 주어질 때, 최소 몇 단계의 과정을 거쳐 begin을 target으로 변환할 수 있는지 return 하도록 solution 함수를 작성해주세요.

제한사항
각 단어는 알파벳 소문자로만 이루어져 있습니다.
각 단어의 길이는 3 이상 10 이하이며 모든 단어의 길이는 같습니다.
words에는 3개 이상 50개 이하의 단어가 있으며 중복되는 단어는 없습니다.
begin과 target은 같지 않습니다.
변환할 수 없는 경우에는 0를 return 합니다.
입출력 예
begin	target	words	return
"hit"	"cog"	["hot", "dot", "dog", "lot", "log", "cog"]	4
"hit"	"cog"	["hot", "dot", "dog", "lot", "log"]	0
입출력 예 설명
예제 #1
문제에 나온 예와 같습니다.

예제 #2
target인 "cog"는 words 안에 없기 때문에 변환할 수 없습니다.
*/

#include <string>
#include <vector>
#include <queue>

using namespace std;

bool isChangable(string, string);

int solution(string begin, string target, vector<string> words) {
	int answer = 0;
	vector<int> flag(words.size());
	queue<pair<string, int>> wordQ;
	wordQ.push(make_pair(begin, 0));
	while (!wordQ.empty()) {
		pair<string, int> now = wordQ.front();
		wordQ.pop();
		if (now.first == target) {
			return now.second;
		}
		for (int i = 0; i < words.size(); i++) {
			if (flag[i] == 0 && isChangable(now.first, words[i])) {
				flag[i] = 1;
				wordQ.push(make_pair(words[i], now.second + 1));
			}
		}
	}
	return answer;
}

bool isChangable(string a, string b) {
	int cnt = 0;
	for (int i = 0; i < a.size(); i++) {
		if (a[i] == b[i]) cnt++;
	}
	if (cnt == a.size() - 1) {
		return true;
	}
	else {
		return false;
	}
}

/*
모범 답안
	시간복잡도
		O()
	공간복잡도
		O(N)
*/

/*
DFS 풀이법
가능한 모든 경로를 다 탐색해봐야하기 때문에 최단 거리로 찾고 끝내는 BFS	보다 비효율적!

#include <string>
#include <vector>
#include <climits>

using namespace std;

void DFS(int);
bool isChangable(string, string);
vector<string> wordV;
string now, targetStr;
int flag[50];
int minDistance = INT_MAX;

int solution(string begin, string target, vector<string> words) {
	int answer = 0;
	wordV = words;
	now = begin;
	targetStr = target;
	DFS(0);
	if (minDistance != INT_MAX) {
		answer = minDistance;
	}
	return answer;
}

void DFS(int L) {
	if (now == targetStr && L < minDistance) {
		minDistance = L;
	}
	else {
		for (int i = 0; i < wordV.size(); i++) {
			if (flag[i] == 0 && isChangable(now, wordV[i])) {
				string temp = now;
				now = wordV[i];
				flag[i] = 1;
				DFS(L + 1);
				flag[i] = 0;
				now = temp;
			}
		}
	}
}
bool isChangable(string a, string b) {
	int cnt = 0;
	for (int i = 0; i < a.size(); i++) {
		if (a[i] == b[i]) cnt++;
	}
	if (cnt == a.size() - 1) {
		return true;
	}
	else {
		return false;
	}
}

모범 답안
	시간 복잡도
		O()(백트래킹)
	공간 복잡도
		O(N)
*/