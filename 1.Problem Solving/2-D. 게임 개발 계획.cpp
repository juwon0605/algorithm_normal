/*
문제 2-D
제목 게임 개발 계획
내용
1인 게임 개발자 김인하는 기본 개발을 마무리하고 남은 일정 기간 동안 게
임 아이템 개발을 추진하려고 한다. 김인하는 각 아이템 개발 일정에 대한
적절한 시작 시점과 개발 완료 시점을 예상 정리하였다. 하지만, 김인하는 제
한된 일정 때문에 모든 아이템 개발 계획을 실행에 옮기기 어렵다고 판단하
였다. 이에 김인하는 최대한 많은 아이템을 개발하기 위해 최적의 개발 일정
을 계획하고자 한다. 김인하는 아래와 같은 조건을 통해 개발 일정을 계획한다.
1. 아이템 이름, 개발 시작 시점, 개발 완료 시점이 주어진다.
2. 1인 개발의 한계로 한 시점에서 하나의 아이템만 개발할 수 있다 
	(즉, 동시에 2개 이상의 아이템을 개발 할 수 없다).
3. 한 아이템의 개발 완료 시점과 다른 아이템의 개발 시작 시점이 같을 경
우, 두 아이템은 연속해서 개발이 가능하다. (즉, 어떤 아이템의 개발 시
작 시점과 종료 시점이 각각 3과 5이고 다른 아이템의 개발 시점과 종료
시점이 각각 5와 7이면 두 아이템은 연속해서 개발 가능하다).
아이템 이름, 개발 시작 시점, 개발 완료 시점이 주어졌을 때, 김인하가 위와
같은 조건으로 개발할 수 있는 아이템은 최대 몇 개인지 출력하는 프로그램
을 작성하시오. 예를 들어, 개발하려는 아이템 수가 11개이고 각 아이템에
대한 시작 시점과 완료 시점이 아래와 같이 주어진다고 하자.
아이템 이름		개발 시작 시점		개발 완료 시점
item1			6					10
item2			8					12
item3			1					4
item4			3					9
item5			12					16
item6			8					11
item7			2					14
item8			4					7
item9			3					5
item10			5					9
item11			0					6
item3 → item8 → item6 → item5 순으로 진행하면 최대 4개의 아이템을
개발할 수 있다.
사용할 수 있는 언어는 C, C++로 제한한다. 프로그램의 실행 제한 시간은 5
초이다. C++의 경우 main 함수 내의 시작 지점에 다음 내용을 추가함으로써
cin 입력 속도를 개선할 수 있다.
std::ios::sync_with_stdio(false);
입력 형식
입력은 표준 입력으로 다음과 같이 주어진다. 첫 번째 줄에는 테스트케이스
의 수 T(≤ 1000)가 주어진다. 각 테스트케이스의 첫 번째 줄에는 개발하려
는 아이템 수 n≤ (10000)이 주어지며, 각 테스트케이스의 두 번째 줄부터
n + 1번째 줄까지 각 줄에는 각 아이템 i(1 ≤ i ≤ n)의 이름을 나타내는 문자
열과, 개발 시작 시점 Si (0 ≤ Si ≤ 10000), 개발 종료 시점 Fi
(0 ≤ Fi ≤ 10000)를 나타내는 정수들이 공백 하나씩을 사이에 두고 주어진
다. 이후에는 같은 형태의 테스트케이스가 T - 1개 더 반복된다.
출력 형식
출력은 표준 출력으로 표시하며, 줄로 구성된다. 각 줄에는 테스트케이스
별로 개발할 수 있는 아이템의 최대 수를 출력한다.
예
입력
2
11
item1 5 7
item2 8 12
item3 0 6
item4 1 4
item5 6 10
item6 5 9
item7 3 9
item8 8 11
item9 2 14
item10 3 5
item11 12 16
5
apple 47 49
banana 35 47
grape 2 46
melon 7 19
orange 19 40
(empty line)
출력
4
3
(empty line)
*/

#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

struct Item {
	int start;
	int finish;
	Item(int a, int b) {
		start = a;
		finish = b;
	}
	bool operator < (const Item &b) const {
		return finish < b.finish;
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	freopen("input.txt", "rt", stdin);
	string a;
	int t, n, b, c, res, preFinish;
	cin >> t;
	while (t--) {
		cin >> n;
		res = 0;
		vector<Item> itemV;
		while (n--) {
			cin >> a >> b >> c;
			itemV.push_back(Item(b, c));
		}
		sort(itemV.begin(), itemV.end());
		preFinish = itemV[0].finish;
		res++;
		for (int i = 1; i < itemV.size(); i++) {
			if (preFinish <= itemV[i].start) {
				preFinish = itemV[i].finish;
				res++;
			}
		}
		cout << res << endl;
	}
	return 0;
}

/*
모범 답안
	현재 시점에서 가장 빨리 끝나는 item을 선택하는 것이 최적이다.

	시간복잡도
		O(TNlogN)
	공간복잡도
		O(N)
*/

/*
모범 답안 반영전
	주어진 값의 범위를 이용해서 Count Sort하고
	DFS와 메모이제이션으로 풀었음!

	시간복잡도
		O(TK) (K=10,000)(0<=N<=10,000)
	공간복잡도
		O(K) (K=10,000)(0<=N<=10,000)

#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int DFS(int, vector<int>*);
int save[10001];
int minStart = 10000, maxFinish = 0;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	freopen("input.txt", "rt", stdin);
	string a;
	int t, n, b, c;
	cin >> t;
	while (t--) {
		cin >> n;
		vector<int> timeV[10001];
		minStart = 10000, maxFinish = 0;
		int temp = n;
		while (temp--) {
			cin >> a >> b >> c;
			if (minStart > b) minStart = b;
			if (maxFinish < c) maxFinish = c;
			timeV[b].push_back(c);
		}
		fill(save, save + 10001, 0);
		cout << DFS(minStart, timeV) << endl;
	}
	return 0;
}
int DFS(int L, vector<int>* timeV) {
	if (save[L] > 0) return save[L];
	if (L == maxFinish) {
		return 0;
	}
	else {
		int left = 0;
		int right = 0;
		for (int i = 0; i < timeV[L].size(); i++) {
			left = max(left, 1 + DFS(timeV[L][i], timeV));
		}
		right = DFS(L + 1, timeV);
		return save[L] = max(left, right);
	}
}
*/