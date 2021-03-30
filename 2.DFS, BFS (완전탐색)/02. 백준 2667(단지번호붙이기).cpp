/*
2. 백준 2667(단지번호붙이기)
<그림 1>과 같이 정사각형 모양의 지도가 있다. 1은 집이 있는 곳을, 0은 집이 없는 곳을 나타낸다. 철수는 이 지도를 가지고 연결된 집의 모임인 단지를 정의하고, 단지에 번호를 붙이려 한다. 여기서 연결되었다는 것은 어떤 집이 좌우, 혹은 아래위로 다른 집이 있는 경우를 말한다. 대각선상에 집이 있는 경우는 연결된 것이 아니다. <그림 2>는 <그림 1>을 단지별로 번호를 붙인 것이다. 지도를 입력하여 단지수를 출력하고, 각 단지에 속하는 집의 수를 오름차순으로 정렬하여 출력하는 프로그램을 작성하시오.
입력
첫 번째 줄에는 지도의 크기 N(정사각형이므로 가로와 세로의 크기는 같으며 5≤N≤25)이 입력되고, 그 다음 N줄에는 각각 N개의 자료(0혹은 1)가 입력된다.
출력
첫 번째 줄에는 총 단지수를 출력하시오. 그리고 각 단지내 집의 수를 오름차순으로 정렬하여 한 줄에 하나씩 출력하시오.
예제 입력 1
7
0110100
0110101
1110101
0000111
0100000
0111110
0111000
예제 출력 1
3
7
8
9
출처
Olympiad > 한국정보올림피아드 > KOI 1996 > 초등부 1번
*/

#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

void BFS(int, int);
vector<int> resV;
int map[25][25];
int dy[4] = { 1,0,-1,0 }, dx[4] = { 0,1,0,-1 };
int n;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	freopen("input.txt", "rt", stdin);
	string input;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> input;
		for (int j = 0; j < n; j++) {
			map[i][j] = input[j] - '0';
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (map[i][j] == 1) BFS(i, j);
		}
	}
	sort(resV.begin(), resV.end());
	cout << resV.size() << "\n";
	for (int i = 0; i < resV.size(); i++) {
		cout << resV[i] << "\n";
	}
	return 0;
}
void BFS(int a, int b) {
	int cnt = 0;
	queue<pair<int, int>> Q;
	Q.push(make_pair(a, b));
	map[a][b] = 0;
	cnt++;
	while (!Q.empty()) {
		pair<int, int> now = Q.front();
		Q.pop();
		int i = now.first;
		int j = now.second;
		for (int k = 0; k < 4; k++) {
			int ii = i + dy[k];
			int jj = j + dx[k];
			if (ii < 0 || ii >= n || jj < 0 || jj >= n) continue;
			if (map[ii][jj] == 1) {
				Q.push(make_pair(ii, jj));
				map[ii][jj] = 0;
				cnt++;
			}
		}
	}
	resV.push_back(cnt);
}