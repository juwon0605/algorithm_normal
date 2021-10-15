/*
퍼즐 조각 채우기
문제 설명
테이블 위에 놓인 퍼즐 조각을 게임 보드의 빈 공간에 적절히 올려놓으려 합니다. 게임 보드와 테이블은 모두 각 칸이 1x1 크기인 정사각 격자 모양입니다. 이때, 다음 규칙에 따라 테이블 위에 놓인 퍼즐 조각을 게임 보드의 빈칸에 채우면 됩니다.

조각은 한 번에 하나씩 채워 넣습니다.
조각을 회전시킬 수 있습니다.
조각을 뒤집을 수는 없습니다.
게임 보드에 새로 채워 넣은 퍼즐 조각과 인접한 칸이 비어있으면 안 됩니다.
다음은 퍼즐 조각을 채우는 예시입니다.

puzzle_5.png

위 그림에서 왼쪽은 현재 게임 보드의 상태를, 오른쪽은 테이블 위에 놓인 퍼즐 조각들을 나타냅니다. 테이블 위에 놓인 퍼즐 조각들 또한 마찬가지로 [상,하,좌,우]로 인접해 붙어있는 경우는 없으며, 흰 칸은 퍼즐이 놓이지 않은 빈 공간을 나타냅니다. 모든 퍼즐 조각은 격자 칸에 딱 맞게 놓여있으며, 격자 칸을 벗어나거나, 걸쳐 있는 등 잘못 놓인 경우는 없습니다.

이때, 아래 그림과 같이 3,4,5번 조각을 격자 칸에 놓으면 규칙에 어긋나므로 불가능한 경우입니다.

puzzle_6.png

3번 조각을 놓고 4번 조각을 놓기 전에 위쪽으로 인접한 칸에 빈칸이 생깁니다.
5번 조각의 양 옆으로 인접한 칸에 빈칸이 생깁니다.
다음은 규칙에 맞게 최대한 많은 조각을 게임 보드에 채워 넣은 모습입니다.

puzzle_7.png

최대한 많은 조각을 채워 넣으면 총 14칸을 채울 수 있습니다.

현재 게임 보드의 상태 game_board, 테이블 위에 놓인 퍼즐 조각의 상태 table이 매개변수로 주어집니다. 규칙에 맞게 최대한 많은 퍼즐 조각을 채워 넣을 경우, 총 몇 칸을 채울 수 있는지 return 하도록 solution 함수를 완성해주세요.

제한사항
3 ≤ game_board의 행 길이 ≤ 50
game_board의 각 열 길이 = game_board의 행 길이
즉, 게임 보드는 정사각 격자 모양입니다.
game_board의 모든 원소는 0 또는 1입니다.
0은 빈칸, 1은 이미 채워진 칸을 나타냅니다.
퍼즐 조각이 놓일 빈칸은 1 x 1 크기 정사각형이 최소 1개에서 최대 6개까지 연결된 형태로만 주어집니다.
table의 행 길이 = game_board의 행 길이
table의 각 열 길이 = table의 행 길이
즉, 테이블은 game_board와 같은 크기의 정사각 격자 모양입니다.
table의 모든 원소는 0 또는 1입니다.
0은 빈칸, 1은 조각이 놓인 칸을 나타냅니다.
퍼즐 조각은 1 x 1 크기 정사각형이 최소 1개에서 최대 6개까지 연결된 형태로만 주어집니다.
game_board에는 반드시 하나 이상의 빈칸이 있습니다.
table에는 반드시 하나 이상의 블록이 놓여 있습니다.
입출력 예
game_board	table	result
[[1,1,0,0,1,0],[0,0,1,0,1,0],[0,1,1,0,0,1],[1,1,0,1,1,1],[1,0,0,0,1,0],[0,1,1,1,0,0]]	[[1,0,0,1,1,0],[1,0,1,0,1,0],[0,1,1,0,1,1],[0,0,1,0,0,0],[1,1,0,1,1,0],[0,1,0,0,0,0]]	14
[[0,0,0],[1,1,0],[1,1,1]]	[[1,1,1],[1,0,0],[0,0,0]]	0
입출력 예 설명
입출력 예 #1

입력은 다음과 같은 형태이며, 문제의 예시와 같습니다.

puzzle_9.png

입출력 예 #2

블록의 회전은 가능하지만, 뒤집을 수는 없습니다.
*/

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

void BFS(int, int, int);
bool compare(pair<int, int>, pair<int, int>);
vector<pair<int, int>> rotate(vector<pair<int, int>>);

vector<vector<pair<int, int>>> boardV;
vector<int> boardFlag;
vector<vector<pair<int, int>>> puzzleV;
vector<int> puzzleFlag;
vector<vector<int>> map;
int dy[4] = { 1,0,-1,0 }, dx[4] = { 0,1,0,-1 };
int n;

int solution(vector<vector<int>> game_board, vector<vector<int>> table) {
	int answer = 0;
	n = game_board.size();
	map = game_board;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (map[i][j] == 0) {
				BFS(i, j, 0);
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			map[i][j] = (table[i][j] == 1 ? 0 : 1);
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (map[i][j] == 0) {
				BFS(i, j, 1);
			}
		}
	}
	for (int i = 0; i < boardV.size(); i++) {
		if (boardFlag[i] == 1) continue;
		for (int j = 0; j < puzzleV.size(); j++) {
			if (puzzleFlag[j] == 1) continue;
			if (boardV[i].size() != puzzleV[j].size()) continue;
			vector<pair<int, int>> rotatePuzzle = puzzleV[j];
			for (int k = 0; k < 4; k++) {
				bool valid = true;
				for (int t = 0; t < boardV[i].size(); t++) {
					if (boardV[i][t].first != rotatePuzzle[t].first ||
						boardV[i][t].second != rotatePuzzle[t].second) {
						valid = false;
						break;
					}
				}
				if (valid) {
					answer += boardV[i].size();
					boardFlag[i] = 1;
					puzzleFlag[j] = 1;
					break;
				}
				rotatePuzzle = rotate(rotatePuzzle);
			}
			if (boardFlag[i] == 1) break;
		}
	}
	return answer;
}

void BFS(int y, int x, int state) {
	vector<pair<int, int>> pV;
	queue<pair<int, int>> pQ;
	pQ.push(make_pair(y, x));
	pV.push_back(make_pair(y, x));
	map[y][x] = 1;
	int mini = y, minj = x;
	while (!pQ.empty()) {
		int i = pQ.front().first;
		int j = pQ.front().second;
		pQ.pop();
		for (int k = 0; k < 4; k++) {
			int ii = i + dy[k];
			int jj = j + dx[k];
			if (ii < 0 || ii >= n || jj < 0 || jj >= n || map[ii][jj] == 1) continue;
			pQ.push(make_pair(ii, jj));
			pV.push_back(make_pair(ii, jj));
			map[ii][jj] = 1;
			mini = min(mini, ii);
			minj = min(minj, jj);
		}
	}
	for (int i = 0; i < pV.size(); i++) {
		pV[i].first -= mini;
		pV[i].second -= minj;
	}
	sort(pV.begin(), pV.end(), compare);
	if (state == 0) {
		boardV.push_back(pV);
		boardFlag.push_back(0);
	}
	else {
		puzzleV.push_back(pV);
		puzzleFlag.push_back(0);
	}
}
bool compare(pair<int, int> a, pair<int, int> b) {
	return (a.first != b.first ? a.first < b.first : a.second < b.second);
}
vector<pair<int, int>> rotate(vector<pair<int, int>> puzzle) {
	vector<pair<int, int>> pV;
	int mini = 50, minj = 50;
	for (int i = 0; i < puzzle.size(); i++) {
		int y = puzzle[i].first;
		int x = puzzle[i].second;
		pV.push_back(make_pair(x, n - y - 1));
		mini = min(mini, x);
		minj = min(minj, n - y - 1);
	}
	for (int i = 0; i < pV.size(); i++) {
		pV[i].first -= mini;
		pV[i].second -= minj;
	}
	sort(pV.begin(), pV.end(), compare);
	return pV;
}

/*
모범 답안
	시간복잡도
		O(N^4)
	공간복잡도
		O(N^2)
*/