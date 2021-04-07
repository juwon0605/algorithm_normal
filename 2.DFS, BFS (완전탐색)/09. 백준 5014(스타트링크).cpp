﻿/*
09. 백준5014(스타트링크)
문제
강호는 코딩 교육을 하는 스타트업 스타트링크에 지원했다. 오늘은 강호의 면접날이다. 하지만, 늦잠을 잔 강호는 스타트링크가 있는 건물에 늦게 도착하고 말았다.
스타트링크는 총 F층으로 이루어진 고층 건물에 사무실이 있고, 스타트링크가 있는 곳의 위치는 G층이다. 강호가 지금 있는 곳은 S층이고, 이제 엘리베이터를 타고 G층으로 이동하려고 한다.
보통 엘리베이터에는 어떤 층으로 이동할 수 있는 버튼이 있지만, 강호가 탄 엘리베이터는 버튼이 2개밖에 없다. U버튼은 위로 U층을 가는 버튼, D버튼은 아래로 D층을 가는 버튼이다. (만약, U층 위, 또는 D층 아래에 해당하는 층이 없을 때는, 엘리베이터는 움직이지 않는다)
강호가 G층에 도착하려면, 버튼을 적어도 몇 번 눌러야 하는지 구하는 프로그램을 작성하시오. 만약, 엘리베이터를 이용해서 G층에 갈 수 없다면, "use the stairs"를 출력한다.
입력
첫째 줄에 F, S, G, U, D가 주어진다. (1 ≤ S, G ≤ F ≤ 1000000, 0 ≤ U, D ≤ 1000000) 건물은 1층부터 시작하고, 가장 높은 층은 F층이다.
출력
첫째 줄에 강호가 S층에서 G층으로 가기 위해 눌러야 하는 버튼의 수의 최솟값을 출력한다. 만약, 엘리베이터로 이동할 수 없을 때는 "use the stairs"를 출력한다.
예제 입력 1
10 1 10 2 1
예제 출력 1
6
예제 입력 2
100 2 1 1 0
예제 출력 2
use the stairs
출처
ICPC > Regionals > Europe > Northwestern European Regional Contest > Nordic Collegiate Programming Contest > NCPC 2011 D번
*/

#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<queue>
using namespace std;

int arr[1000001];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	freopen("input.txt", "rt", stdin);
	queue<int> Q;
	int f, s, g, u, d;
	cin >> f >> s >> g >> u >> d;
	if (s == g) {
		cout << 0;
		return 0;
	}
	arr[s] = 1;
	Q.push(s);
	while (!Q.empty()) {
		int now = Q.front();
		Q.pop();
		int nextUp = now + u;
		int nextDown = now - d;
		if (nextUp <= f && arr[nextUp] == 0) {
			arr[nextUp] = arr[now] + 1;
			Q.push(nextUp);
		}
		if (nextDown > 0 && arr[nextDown] == 0) {
			arr[nextDown] = arr[now] + 1;
			Q.push(nextDown);
		}
	}
	if (arr[g] != 0) {
		cout << arr[g] - 1;
	}
	else {
		cout << "use the stairs";
	}
	return 0;
}