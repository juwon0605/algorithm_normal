/*
4. 스도쿠(DFS 활용)
설명
스도쿠는 9×9 크기의 보드가 있을 때, 각 행과 각 열, 그리고 9개의 3×3 크기의 보드에 1부터 9까지의 숫자가 중복 없이 나타나도록 보드를 채우는 퍼즐이다.
Image1.jpg
위 그림은 스도쿠를 정확하게 풀어낸 것이다. 각 행에 1부터 9까지의 숫자가 중복 없이 나오고, 각 열에 1부터 9까지의 숫자가 중복 없이 나오고,
각 3×3짜리 사각형(9개이며, 위에서 색깔로 표시되었다)에 1부터 9까지의 숫자가 중복 없이 한 번씩 나오기 때문이다.
완성되지 않은 스도쿠 퍼즐이 주어졌을 때, 스도쿠를 정확하게 완성하는 프로그램을 작성하세요.
입력
9*9 보드정보가 주어집니다. 아직 숫자가 채워지지 않은 칸은 0으로 표시됩니다.
출력
9개의 줄에 9개의 숫자로 답을 출력한다. 답이 여러 개 있다면 그 중 오름차순으로 제일 먼저 발견된 것을 출력하면 됩니다.
즉, 81자리의 수가 제일 작은 경우로 출력하는 것입니다.
예시 입력 1
0 2 3 0 5 0 7 8 9
0 5 6 0 8 9 1 0 3
0 8 9 1 0 3 0 5 6
0 1 0 0 6 0 8 9 0
3 0 5 0 9 7 0 1 4
0 9 7 0 1 0 0 6 5
5 3 0 6 0 2 9 7 8
6 0 2 9 0 8 5 3 1
9 0 8 0 3 0 6 0 2
예시 출력 1
1 2 3 4 5 6 7 8 9
4 5 6 7 8 9 1 2 3
7 8 9 1 2 3 4 5 6
2 1 4 3 6 5 8 9 7
3 6 5 8 9 7 2 1 4
8 9 7 2 1 4 3 6 5
5 3 1 6 4 2 9 7 8
6 4 2 9 7 8 5 3 1
9 7 8 5 3 1 6 4 2
*/

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
using namespace std;

void DFS(int);
bool isValid(int, int, int);
int map[9][9];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	freopen("input.txt", "rt", stdin);
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cin >> map[i][j];
		}
	}
	DFS(0);
	return 0;
}

void DFS(int L) {
	if (L == 81) {
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				cout << map[i][j] << " ";
			}
			cout << "\n";
		}
		exit(0);
	}
	else {
		int i = L / 9;
		int j = L % 9;
		if (map[i][j] != 0) {
			DFS(L + 1);
		}
		else {
			for (int k = 1; k <= 9; k++) {
				if (isValid(i, j, k)) {
					map[i][j] = k;
					DFS(L + 1);
				}
			}
		}
	}
}

bool isValid(int i, int j, int k) {
	map[i][j] = k;
	vector<int> V1(10);
	for (int jj = 0; jj < 9; jj++) {
		if (map[i][jj] != 0) {
			if (V1[map[i][jj]] == 0) V1[map[i][jj]]++;
			else {
				map[i][j] = 0;
				return false;
			}
		}
	}
	vector<int> V2(10);
	for (int ii = 0; ii < 9; ii++) {
		if (map[ii][j] != 0) {
			if (V2[map[ii][j]] == 0) V2[map[ii][j]]++;
			else {
				map[i][j] = 0;
				return false;
			}
		}
	}
	int ii, jj;
	if (i >= 0 && i < 3) ii = 0;
	else if (i >= 3 && i < 6) ii = 3;
	else ii = 6;
	if (j >= 0 && j < 3) jj = 0;
	else if (j >= 3 && j < 6) jj = 3;
	else jj = 6;
	vector<int> V3(10);
	for (int y = 0; y < 3; y++) {
		for (int x = 0; x < 3; x++) {
			if (map[ii + y][jj + x] != 0) {
				if (V3[map[ii + y][jj + x]] == 0) V3[map[ii + y][jj + x]]++;
				else {
					map[i][j] = 0;
					return false;
				}
			}
		}
	}
	map[i][j] = 0;
	return true;
}

/*
모범 답안
	시간복잡도
		
	공간복잡도
		O(1)
*/