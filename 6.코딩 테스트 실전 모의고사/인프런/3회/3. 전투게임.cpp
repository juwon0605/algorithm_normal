/*
3. 전투 게임
설명
현수네 반 학생들은 몇 개의 팀으로 나뉘어 전투게임을 합니다.
각 학생들은 반 번호, 팀, 공격력을 가지고 있습니다. 각 학생들은 다른 팀의 학생 중 자기보다 공격력이 작은 학생을 사로잡을 수 있습니다.
다른 팀의 학생을 사로잡았다고 해서 본인의 공격력이 올라가는 것은 아닙니다. 공격력은 변하지 않습니다.
다음 예는 학생이 5명이 있을 때의 경우입니다.
Image1.jpg
1번 학생의 경우 2, 4, 5번 학생을 사로잡을 수 있고, 3번 학생은 같은 팀이라 사로잡을 수 없습니다. 2번 학생은 3, 4번 학생을 사로잡을 수 있습니다.
각 학생은 자신이 사로잡을 수 있는 학생의 공격력만큼 점수를 획득합니다.
1번 학생의 경우 2, 4, 5번 학생을 사로잡을 수 있으므로 2, 4, 5번의 공격력을 합한 12+11+12=35만큼 점수를 획득할 수 있습니다.
모든 학생의 팀과 공격력이 주어지면, 각 학생마다 얻을 수 있는 점수를 출력하는 프로그램을 작성하세요.
입력
첫 줄에는 반 학생수를 나타내는 자연수 N이 주어진다(1 ≤ N ≤ 200,000).
다음 N줄에 걸쳐 i번째 줄에는 i번째 학생의 팀(a~z)과 공격력(1~100)이 주어집니다.
출력
N개의 줄을 출력합니다. N개의 줄 중 i번째 줄에는 i번째 학생이 사로잡을 수 있는 학생들의 공격력의 총합을 출력합니다.
예시 입력 1
7
a 17
b 12
a 10
c 11
b 24
a 25
b 12
예시 출력 1
35
21
0
10
38
59
21
*/

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

struct student {
	int idx;
	char team;
	int power;
	student(int a, char b, int c) {
		idx = a;
		team = b;
		power = c;
	}
	bool operator < (const student &b) const {
		return power < b.power;
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	freopen("input.txt", "rt", stdin);
	vector<student> sV;
	unordered_map<char, int> uM;
	int n, num, sum = 0;
	char c;
	cin >> n;
	vector<int> resV(n);
	for (int i = 0; i < n; i++) {
		cin >> c >> num;
		sV.push_back(student(i, c, num));
	}
	sort(sV.begin(), sV.end());
	int j = 0;
	for (int i = 1; i < n; i++) {
		for (; j < n; j++) {
			if (sV[j].power < sV[i].power) {
				sum += sV[j].power;
				uM[sV[j].team] += sV[j].power;
			}
			else break;
		}
		resV[sV[i].idx] = sum - uM[sV[i].team];
	}
	for (int i = 0; i < n; i++) {
		cout << resV[i] << "\n";
	}
	return 0;
}

/*
모범 답안

	만약 팀과 공격력의 범위가 주어지지 않거나 매우 크다면 모범 답안처럼 풀어야 함!
	시간복잡도에서 불리해보이지만, log(20000)이 14정도라 최대 O(100N + 26N)인 counting sort랑 큰 차이 없음.
	counting sort가 아주 조금 빠르긴 했지만, 속도차이가 거의 없었음.

	시간복잡도
		O(NlogN)
	공간복잡도
		O(N)
*/

/*
모범 답안 반영 전

	a<=팀<=z이고, 1<=공격력<=100이어서 2차원 배열에 counting sort해서 품!

	시간복잡도
		O(N)
	공간복잡도
		O(N)

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	freopen("input.txt", "rt", stdin);
	vector<vector<int>> board(26, vector<int>(101));
	unordered_map<char, vector<int>> uM;
	vector<pair<char, int>> pV;
	int n, num;
	char c;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> c >> num;
		pV.push_back(make_pair(c, num));
		uM[c].push_back(num);
	}
	for (auto iter = uM.begin(); iter != uM.end(); iter++) {
		for (int i = 0; i < iter->second.size(); i++) {
			for (int j = (iter->second)[i] + 1; j <= 100; j++) {
				board[iter->first - 'a'][j] += (iter->second)[i];
			}
		}
	}
	//log
	/*
	for (int i = 0; i < 26; i++) {
		for (int j = 0; j < 101; j++) {
			cout << board[i][j] << " ";
		}
		cout << "\n";
	}
	//
	for (int i = 0; i < n; i++) {
		int res = 0;
		c = pV[i].first;
		num = pV[i].second;
		for (auto iter = uM.begin(); iter != uM.end(); iter++) {
			if (iter->first == c) continue;
			res += board[iter->first - 'a'][num];
		}
		cout << res << "\n";
	}
	return 0;
}
*/