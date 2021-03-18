/*
1. 백준 2583(영역구하기)
눈금의 간격이 1인 M×N(M,N≤100)크기의 모눈종이가 있다. 이 모눈종이 위에 눈금에 맞추어 K개의 직사각형을 그릴 때, 이들 K개의 직사각형의 내부를 제외한 나머지 부분이 몇 개의 분리된 영역으로 나누어진다.
예를 들어 M=5, N=7 인 모눈종이 위에 <그림 1>과 같이 직사각형 3개를 그렸다면, 그 나머지 영역은 <그림 2>와 같이 3개의 분리된 영역으로 나누어지게 된다.
<그림 2>와 같이 분리된 세 영역의 넓이는 각각 1, 7, 13이 된다.
M, N과 K 그리고 K개의 직사각형의 좌표가 주어질 때, K개의 직사각형 내부를 제외한 나머지 부분이 몇 개의 분리된 영역으로 나누어지는지, 그리고 분리된 각 영역의 넓이가 얼마인지를 구하여 이를 출력하는 프로그램을 작성하시오.
입력
첫째 줄에 M과 N, 그리고 K가 빈칸을 사이에 두고 차례로 주어진다. M, N, K는 모두 100 이하의 자연수이다. 둘째 줄부터 K개의 줄에는 한 줄에 하나씩 직사각형의 왼쪽 아래 꼭짓점의 x, y좌표값과 오른쪽 위 꼭짓점의 x, y좌표값이 빈칸을 사이에 두고 차례로 주어진다. 모눈종이의 왼쪽 아래 꼭짓점의 좌표는 (0,0)이고, 오른쪽 위 꼭짓점의 좌표는(N,M)이다. 입력되는 K개의 직사각형들이 모눈종이 전체를 채우는 경우는 없다.
출력
첫째 줄에 분리되어 나누어지는 영역의 개수를 출력한다. 둘째 줄에는 각 영역의 넓이를 오름차순으로 정렬하여 빈칸을 사이에 두고 출력한다.
예제 입력 1
5 7 3
0 2 4 4
1 1 2 5
4 0 6 2
예제 출력 1
3
1 7 13
출처
Olympiad > 한국정보올림피아드 > 한국정보올림피아드시․도지역본선 > 지역본선 2006 > 고등부 2번
*/

#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

void BFS(int, int);
vector<int> resV;
int map[100][100];
int dy[4] = { 1,0,-1,0 }, dx[4] = { 0,1,0,-1 };
int m, n;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	freopen("input.txt", "rt", stdin);
	int k, x1, y1, x2, y2;
	cin >> m >> n >> k;
	for (int i = 0; i < k; i++) {
		cin >> x1 >> y1 >> x2 >> y2;
		for (int y = m - y2; y < m - y1; y++) {
			for (int x = x1; x < x2; x++) {
				map[y][x] = 1;
			}
		}
	}
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (map[i][j] == 0) BFS(i, j);
		}
	}
	sort(resV.begin(), resV.end());
	cout << resV.size() << "\n";
	for (int i = 0; i < resV.size(); i++) {
		cout << resV[i] << " ";
	}
	return 0;
}
void BFS(int a, int b) {
	int cnt = 0;
	queue<pair<int, int>> Q;
	Q.push(make_pair(a, b));
	map[a][b] = 1;
	cnt++;
	while (!Q.empty()) {
		pair<int, int> now = Q.front();
		Q.pop();
		int i = now.first;
		int j = now.second;
		for (int k = 0; k < 4; k++) {
			int ii = i + dy[k];
			int jj = j + dx[k];
			if (ii < 0 || ii >= m || jj < 0 || jj >= n) continue;
			if (map[ii][jj] == 0) {
				Q.push(make_pair(ii, jj));
				map[ii][jj] = 1;
				cnt++;
			} 
		}
	}
	resV.push_back(cnt);
}

/*
모범 답안
	BFS는 큐에서 뺀 다음에 아닌, 큐에 넣을 때 방문 표시를 해야 중복 방문이 일어나지 않는다!
*/

/*
모범 답안 반영 전
	BFS 구현을 큐에서 뺀 다음 방문 표시를 해서 중복 방문 발생!
	메모리 초과로 오답 처리됨.
*/