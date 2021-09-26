/*
5. 최대 선호 음식(DFS, 비트연산)
설명
엘리트 학원에서 선생님과 학생들이 소풍을 갔습니다. 선생님들은 학생들에게 요리를 해주기로 마음먹고, 학생들에게 각자의 취향에 대해서 물었다.
선생님들이 가지고 있는 양념재료의종류는 D(1≤D≤15)종류입니다, 양념재료는 1부터 D까지 번호로 매겨져 있다.
각각의 학생들은 자기가 원하는 재료가 꼭 다 들어가야만 음식을 먹겠다고 합니다.
학생들은 총 N(1≤N≤30,000)명이 있고, 선생님이 사용할 수 있는 재료의 종류가 K(1≤K≤D)개 이하가 되도록 하려 한다.
위의 조건을 만족하면서 최대 몇 명의 학생에게 음식을 만들어 줄 수 있는지 구하는 프로그램을 작성하세요.
입력
첫째 줄에 세 정수 N, D, K가 주어진다. 다음 N개의 줄에는 차례로 1번 학생부터 N번 학생까지의 음식취향에 관한 정보가 주어진다.
각 줄의 첫 번째 정수는 그 학생이 원하는 재료의 개수이고, 다음에는 그 학생이 좋아하는 재료의 번호이다.
재료의 번호는 1부터 D까지의 정수로 나타낸다. 원하는 재료가 없는 학생은 아무거나 먹겠다는 뜻으로 해석한다.
출력
조건을 만족하는 최대인원을 출력한다.
예시 입력 1
8 4 3
1 1
2 2 3
1 3
2 1 2
0
2 2 1
3 2 3 4
2 3 4
예시 출력 1
6
힌트
1, 2, 3번 재료를 사용하여 1, 2, 3, 4, 5, 6번 학생들이 음식을 먹을 수 있다.
*/

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
using namespace std;

void DFS(int, int);
int flag[15], bitArr[16], studentArr[30000];
int n, d, k, bitAccum, res;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	freopen("input.txt", "rt", stdin);
	cin >> n >> d >> k;
	int bit = 1, num1, num2;
	for (int i = 1; i <= d; i++) {
		bitArr[i] = bit;
		bit *= 2;
	}
	for (int i = 0; i < n; i++) {
		bitAccum = 0;
		cin >> num1;
		while (num1--) {
			cin >> num2;
			bitAccum += bitArr[num2];
		}
		studentArr[i] = bitAccum;
	}
	DFS(0, 1);
	cout << res;
	return 0;
}

void DFS(int L, int s) {
	if (L == k) {
		//log
		/*
		for (int i = 0; i < k; i++) {
			cout << flag[i] << " ";
		}
		cout << "\n";
		*/
		bitAccum = 0;
		int cnt = 0;
		for (int i = 0; i < k; i++) {
			bitAccum += bitArr[flag[i]];
		}
		for (int i = 0; i < n; i++) {
			if ((bitAccum & studentArr[i]) == studentArr[i]) cnt++;
		}
		if (res < cnt) res = cnt;
	}
	else {
		for (int i = s; i <= d; i++) {
			flag[L] = i;
			DFS(L + 1, i + 1);
		}
	}
}

/*
모범 답안

	선택한 음식 번호들을 비트로 표현해서 & 연산자를 사용하면 O(1)만에 포함 관계를 알 수 있다!
	&는 ==보다 연산자 우선순위가 낮다는 점 주의!

	시간복잡도
		O(dCk * N)
	공간복잡도
		O(N)
*/

/*
모범 답안 반영 전

	시간 초과돼서 N의 중복을 하나로 만들었다.
	운 좋게 테스트 케이스는 통과했지만 2^15 > 30,000이라 N을 압축해도 안돼야 한다.

	시간복잡도
		O(dCk * N * D)
	공간복잡도
		O(ND)

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
using namespace std;

void DFS(int, int);
unordered_map<string, int> uM;
int flag[15];
int n, d, k, res;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	freopen("input.txt", "rt", stdin);
	cin >> n >> d >> k;
	int num1, num2, zeroCnt = 0;
	for (int i = 0; i < n; i++) {
		cin >> num1;
		if (num1 == 0) {
			zeroCnt++;
			continue;
		}
		vector<int> V;
		while (num1--) {
			cin >> num2;
			V.push_back(num2);
		}
		sort(V.begin(), V.end());
		string temp;
		for (int j = 0; j < V.size(); j++) {
			temp += to_string(V[j]) + "/";
		}
		uM[temp]++;
	}
	DFS(0, 1);
	cout << res + zeroCnt;
	return 0;
}

void DFS(int L, int s) {
	if (L == k) {
		unordered_set<int> uS;
		for (int i = 0; i < k; i++) {
			uS.insert(flag[i]);
		}
		int cnt = 0;
		for (auto iter = uM.begin(); iter != uM.end(); iter++) {
			string str = iter->first;
			string temp;
			bool check = true;
			for (int i = 0; i < str.size(); i++) {
				if (str[i] == '/') {
					if (uS.find(stoi(temp)) == uS.end()) {
						check = false;
						break;
					}
					temp = "";
				}
				else {
					temp += str[i];
				}
			}
			if (check) cnt += iter->second;
		}
		if (res < cnt) res = cnt;
	}
	else {
		for (int i = s; i <= d; i++) {
			flag[L] = i;
			DFS(L + 1, i + 1);
			flag[L] = 0;
		}
	}
}
*/