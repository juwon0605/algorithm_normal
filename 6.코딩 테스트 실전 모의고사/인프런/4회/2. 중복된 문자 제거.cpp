/*
2. 중복된 문자 제거
설명
대소문자가 섞여있는 문자열이 주어지면 해당 문자열을 모두 대문자로 통일한 후, 그 순서는 유지하면서 중복된 문자는 제거한 문자열을 만듭니다.
그 문자열은 사전순으로 가장 빠른 단어가 되게 만들어야 합니다. 만약 주어진 문자열이 "CbDBEaCEb" 라면 일단 대문자로 통일합니다.
“CBDBEACEB" 그 다음 중복을 제거하되 순서는 유지되면서 사전순으로 가장 빠른 단어를 만듭니다.
그 결과는 “CBDBEACEB"에서 뽑아낸 ”BDACE"입니다.
입력
첫 줄에 한 줄에 문자열 하나가 입력됩니다. 문자열의 길이는 50을 넘지 않습니다.
출력
첫 줄부터 중복이 제거된 사전순으로 가장 빠른 단어를 출력합니다.
예시 입력 1
CbDBEaCEb
예시 출력 1
BDACE
*/

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <stack>
#include <unordered_map>
#include <unordered_set>
using namespace std;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	freopen("input.txt", "rt", stdin);
	unordered_map<char, int> uM;
	unordered_set<char> uS;
	stack<char> S;
	string input, res;
	cin >> input;
	for (int i = 0; i < input.size(); i++) {
		if (input[i] >= 'a' && input[i] <= 'z') input[i] += ('A' - 'a');
		uM[input[i]]++;
	}
	for (int i = 0; i < input.size(); i++) {
		uM[input[i]]--;
		if (uS.find(input[i]) != uS.end()) continue;
		while (!S.empty() && S.top() > input[i] && uM[S.top()] > 0) {
			uS.erase(S.top());
			S.pop();
		}
		uS.insert(input[i]);
		S.push(input[i]);
	}
	while (!S.empty()) {
		res += S.top();
		S.pop();
	}
	for (int i = res.size() - 1; i >= 0; i--) {
		cout << res[i];
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

/*
모범 답안 반영 전1

	대문자 알파벳의 개수가 26개로 상수개라 모든 경우의 수를 구하고 정렬해도 될 것 같아서 풀고 통과했음.
	하지만 최악의 경우에는 모든 알파벳이 2개씩 있다면 (2^26)log(2^26)번의 연산으로 1초 안에 연산 불가!

	시간복잡도
		O((k^(N/k))log(k^(N/k))) (k는 중복되지 않는 알파벳의 평균 개수)
	공간복잡도
		O(k^(N/k)) (k는 중복되지 않는 알파벳의 평균 개수)

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

void DFS(int);
bool compare2(pair<char, int>, pair<char, int>);

vector<int> VArr[26];
vector<string> strV;
int flag[26];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	freopen("input.txt", "rt", stdin);
	string input;
	cin >> input;
	for (int i = 0; i < input.size(); i++) {
		if (input[i] >= 'a' && input[i] <= 'z') input[i] -= ('a' - 'A');
	}
	for (int i = 0; i < input.size(); i++) {
		VArr[input[i] - 'A'].push_back(i);
	}
	DFS(0);
	sort(strV.begin(), strV.end());
	cout << strV[0];
	return 0;
}

void DFS(int L) {
	if (L == 26) {
		vector<pair<char, int>> pV;
		for (int i = 0; i < 26; i++) {
			if (flag[i] != 0) {
				pV.push_back(make_pair('A' + i, flag[i]));
			}
		}
		sort(pV.begin(), pV.end(), compare2);
		string temp;
		for (int i = 0; i < pV.size(); i++) {
			temp += pV[i].first;
		}
		strV.push_back(temp);
	}
	else {
		if (VArr[L].size() == 0) DFS(L + 1);
		else {
			for (int i = 0; i < VArr[L].size(); i++) {
				flag[L] = VArr[L][i] + 1;
				DFS(L + 1);
			}
		}
	}
}

bool compare2(pair<char, int> a, pair<char, int> b) {
	return a.second < b.second;
}
*/

/*
모범 답안 반영 전2

	현재 나보다 큰 알파벳이 앞에 있을때 뒤에 그 큰 알파벳이 있는지를 순회하면서 판단했다.
	미리 unordred_map으로 개수를 세놓고, 읽은 알파벳 개수를 빼면서 남은 개수를 확인하면 순회할 필요가 없다!

	시간복잡도
		O(N^2)
	공간복잡도
		O(N)

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <unordered_set>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	freopen("input.txt", "rt", stdin);
	unordered_set<char> uS;
	stack<char> S;
	string input, res;
	cin >> input;
	for (int i = 0; i < input.size(); i++) {
		if (input[i] >= 'a' && input[i] <= 'z') input[i] += ('A' - 'a');
	}
	for (int i = 0; i < input.size(); i++) {
		if (uS.find(input[i]) != uS.end()) continue;
		bool isBehind = true;
		while (!S.empty() && S.top() > input[i] && isBehind) {
			isBehind = false;
			for (int j = i + 1; j < input.size(); j++) {
				if (S.top() == input[j]) {
					isBehind = true;
					uS.erase(S.top());
					S.pop();
					break;
				}
			}
		}
		uS.insert(input[i]);
		S.push(input[i]);
	}
	while (!S.empty()) {
		res += S.top();
		S.pop();
	}
	for (int i = res.size() - 1; i >= 0; i--) {
		cout << res[i];
	}
	return 0;
}
*/