/*
4. 백준 1987(알파벳)
세로 R칸, 가로 C칸으로 된 표 모양의 보드가 있다. 보드의 각 칸에는 대문자 알파벳이 하나씩 적혀 있고, 좌측 상단 칸 (1행 1열) 에는 말이 놓여 있다.
말은 상하좌우로 인접한 네 칸 중의 한 칸으로 이동할 수 있는데, 새로 이동한 칸에 적혀 있는 알파벳은 지금까지 지나온 모든 칸에 적혀 있는 알파벳과는 달라야 한다. 즉, 같은 알파벳이 적힌 칸을 두 번 지날 수 없다.
좌측 상단에서 시작해서, 말이 최대한 몇 칸을 지날 수 있는지를 구하는 프로그램을 작성하시오. 말이 지나는 칸은 좌측 상단의 칸도 포함된다.
입력
첫째 줄에 R과 C가 빈칸을 사이에 두고 주어진다. (1 ≤ R,C ≤ 20) 둘째 줄부터 R개의 줄에 걸쳐서 보드에 적혀 있는 C개의 대문자 알파벳들이 빈칸 없이 주어진다.
출력
첫째 줄에 말이 지날 수 있는 최대의 칸 수를 출력한다.
예제 입력 1
2 4
CAAB
ADCB
예제 출력 1
3
출처
Olympiad > Croatian Highschool Competitions in Informatics > 2002 > Regional Competition - Juniors 3번
*/

#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<string>
using namespace std;

void DFS(int, int, int);
char map[20][20];
int alphabet[26];
int dy[4] = { 1,0,-1,0 }, dx[4] = { 0,1,0,-1 };
int R, C, res = 0;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	freopen("input.txt", "rt", stdin);
	string input;
	cin >> R >> C;
	for (int i = 0; i < R; i++) {
		cin >> input;
		for (int j = 0; j < C; j++) {
			map[i][j] = input[j];
		}
	}
	int pos = map[0][0] - 65;
	alphabet[pos] = 1;
	DFS(0, 0, 1);
	cout << res;
	return 0;
}
void DFS(int a, int b, int L) {
	if (L > res) res = L;
	int i = a;
	int j = b;
	for (int k = 0; k < 4; k++) {
		int ii = i + dy[k];
		int jj = j + dx[k];
		if (ii < 0 || ii >= R || jj < 0 || jj >= C) continue;
		int pos = map[ii][jj] - 65;
		if (alphabet[pos] == 0) {
			alphabet[pos] = 1;
			DFS(ii, jj, L + 1);
			alphabet[pos] = 0;
		}
	}
}

/*
모범 답안
	alphabet 크기의 배열을 만들어서 count하는 방법으로 바로 중복 판단.
	앞으로, 비교해야하는 경우의 수가 적을때는 해당 배열을 만들어 판단!
*/

/*
모범 답안 반영 전1
	거의 바로 오답 처리됨.
	아직 어디가 문제인지 찾지 못함.

#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

void DFS(int, int, int);
char map[20][20];
int flag[20][20];
vector<char> pathV;
int dy[4] = { 1,0,-1,0 }, dx[4] = { 0,1,0,-1 };
int R, C, res = 0;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string input;
	cin >> R >> C;
	for (int i = 0; i < R; i++) {
		cin >> input;
		for (int j = 0; j < C; j++) {
			map[i][j] = input[j];
		}
	}
	flag[0][0] = 1;
	pathV.push_back(map[0][0]);
	DFS(0, 0, 1);
	cout << res;
	return 0;
}
void DFS(int a, int b, int L) {
	if (L > res) res = L;
	int i = a;
	int j = b;
	for (int k = 0; k < 4; k++) {
		int ii = i + dy[k];
		int jj = j + dx[k];
		if (flag[ii][jj] == 1 || ii < 0 || ii >= R || jj < 0 || jj >= C) continue;
		bool duplication = false;
		sort(pathV.begin(), pathV.end());
		int start = 0;
		int end = pathV.size() - 1;
		int mid;
		while (start <= end) {
			mid = (start + end) / 2;
			if (map[ii][jj] == pathV[mid]) {
				duplication = true;
				break;
			}
			else if (map[ii][jj] > pathV[mid]) {
				start = mid + 1;
			}
			else {
				end = mid - 1;
			}
		}
		if (!duplication) {
			flag[ii][jj] = 1;
			pathV.push_back(map[ii][jj]);
			DFS(ii, jj, L + 1);
			pathV.pop_back();
			flag[ii][jj] = 0;
		}
	}
}
*/

/*
모범 답안 반영 전2
	70%정도는 채점 되는데 이후에 시간 초과됨.

#include<iostream>
#include<string>
#include<vector>
using namespace std;

void DFS(int, int, int);
char map[20][20];
int flag[20][20];
vector<char> pathV;
int dy[4] = { 1,0,-1,0 }, dx[4] = { 0,1,0,-1 };
int R, C, res = 0;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string input;
	cin >> R >> C;
	for (int i = 0; i < R; i++) {
		cin >> input;
		for (int j = 0; j < C; j++) {
			map[i][j] = input[j];
		}
	}
	flag[0][0] = 1;
	pathV.push_back(map[0][0]);
	DFS(0, 0, 1);
	cout << res;
	return 0;
}
void DFS(int a, int b, int L) {
	if (L > res) res = L;
	int i = a;
	int j = b;
	for (int k = 0; k < 4; k++) {
		int ii = i + dy[k];
		int jj = j + dx[k];
		if (flag[ii][jj] == 1 || ii < 0 || ii >= R || jj < 0 || jj >= C) continue;
		bool duplication = false;
		for (int i = 0; i < pathV.size(); i++) {
			if (map[ii][jj] == pathV[i]) {
				duplication = true;
				break;
			}
		}
		if (!duplication) {
			flag[ii][jj] = 1;
			pathV.push_back(map[ii][jj]);
			DFS(ii, jj, L + 1);
			pathV.pop_back();
			flag[ii][jj] = 0;
		}
	}
}
*/