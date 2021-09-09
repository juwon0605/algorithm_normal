/*
4. 경주로 건설
문제 설명
kakao_road1.png

건설회사의 설계사인 죠르디는 고객사로부터 자동차 경주로 건설에 필요한 견적을 의뢰받았습니다.
제공된 경주로 설계 도면에 따르면 경주로 부지는 N x N 크기의 정사각형 격자 형태이며 각 격자는 1 x 1 크기입니다.
설계 도면에는 각 격자의 칸은 0 또는 1 로 채워져 있으며, 0은 칸이 비어 있음을 1은 해당 칸이 벽으로 채워져 있음을 나타냅니다.
경주로의 출발점은 (0, 0) 칸(좌측 상단)이며, 도착점은 (N-1, N-1) 칸(우측 하단)입니다. 죠르디는 출발점인 (0, 0) 칸에서 출발한 자동차가 도착점인 (N-1, N-1) 칸까지 무사히 도달할 수 있게 중간에 끊기지 않도록 경주로를 건설해야 합니다.
경주로는 상, 하, 좌, 우로 인접한 두 빈 칸을 연결하여 건설할 수 있으며, 벽이 있는 칸에는 경주로를 건설할 수 없습니다.
이때, 인접한 두 빈 칸을 상하 또는 좌우로 연결한 경주로를 직선 도로 라고 합니다.
또한 두 직선 도로가 서로 직각으로 만나는 지점을 코너 라고 부릅니다.
건설 비용을 계산해 보니 직선 도로 하나를 만들 때는 100원이 소요되며, 코너를 하나 만들 때는 500원이 추가로 듭니다.
죠르디는 견적서 작성을 위해 경주로를 건설하는 데 필요한 최소 비용을 계산해야 합니다.

예를 들어, 아래 그림은 직선 도로 6개와 코너 4개로 구성된 임의의 경주로 예시이며, 건설 비용은 6 x 100 + 4 x 500 = 2600원 입니다.

kakao_road2.png

또 다른 예로, 아래 그림은 직선 도로 4개와 코너 1개로 구성된 경주로이며, 건설 비용은 4 x 100 + 1 x 500 = 900원 입니다.

kakao_road3.png

도면의 상태(0은 비어 있음, 1은 벽)을 나타내는 2차원 배열 board가 매개변수로 주어질 때, 경주로를 건설하는데 필요한 최소 비용을 return 하도록 solution 함수를 완성해주세요.

[제한사항]
board는 2차원 정사각 배열로 배열의 크기는 3 이상 25 이하입니다.
board 배열의 각 원소의 값은 0 또는 1 입니다.
도면의 가장 왼쪽 상단 좌표는 (0, 0)이며, 가장 우측 하단 좌표는 (N-1, N-1) 입니다.
원소의 값 0은 칸이 비어 있어 도로 연결이 가능함을 1은 칸이 벽으로 채워져 있어 도로 연결이 불가능함을 나타냅니다.
board는 항상 출발점에서 도착점까지 경주로를 건설할 수 있는 형태로 주어집니다.
출발점과 도착점 칸의 원소의 값은 항상 0으로 주어집니다.
입출력 예
board	result
[[0,0,0],[0,0,0],[0,0,0]]	900
[[0,0,0,0,0,0,0,1],[0,0,0,0,0,0,0,0],[0,0,0,0,0,1,0,0],[0,0,0,0,1,0,0,0],[0,0,0,1,0,0,0,1],[0,0,1,0,0,0,1,0],[0,1,0,0,0,1,0,0],[1,0,0,0,0,0,0,0]]	3800
[[0,0,1,0],[0,0,0,0],[0,1,0,1],[1,0,0,0]]	2100
[[0,0,0,0,0,0],[0,1,1,1,1,0],[0,0,1,0,0,0],[1,0,0,1,0,1],[0,1,0,0,0,1],[0,0,0,0,0,0]]	3200
입출력 예에 대한 설명
입출력 예 #1

본문의 예시와 같습니다.

입출력 예 #2

kakao_road4.png

위와 같이 경주로를 건설하면 직선 도로 18개, 코너 4개로 총 3800원이 듭니다.

입출력 예 #3

kakao_road5.png

위와 같이 경주로를 건설하면 직선 도로 6개, 코너 3개로 총 2100원이 듭니다.

입출력 예 #4

kakao_road6.png

붉은색 경로와 같이 경주로를 건설하면 직선 도로 12개, 코너 4개로 총 3200원이 듭니다.
만약, 파란색 경로와 같이 경주로를 건설한다면 직선 도로 10개, 코너 5개로 총 3500원이 들며, 더 많은 비용이 듭니다.

※ 공지 - 2021년 8월 30일 테스트케이스가 추가되었습니다.
*/

#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

struct Info {
	int i;
	int j;
	int direction; // 0:상, 1:우, 2:하, 3:좌
	Info(int a, int b, int c) {
		i = a;
		j = b;
		direction = c;
	}
};

int solution(vector<vector<int>> board) {
	int answer = 2147000000;
	int cnt[4][25][25];
	int n = board.size();
	for (int i = 0; i < board.size(); i++) {
		for (int j = 0; j < board.size(); j++) {
			for (int k = 0; k < 4; k++) {
				cnt[k][i][j] = 2147000000;
				//log
				// cnt[k][i][j] = 99999;                
			}
		}
	}
	//시계 방향
	int dy[4] = { 1, 0, -1, 0 }, dx[4] = { 0, 1, 0, -1 }; //상,우,하,좌->통과
	// int dy[4] = {0, -1, 0, 1}, dx[4] = {1, 0, -1, 0}; //우,하,좌,상->통과
	// int dy[4] = {-1, 0, 1, 0}, dx[4] = {0, -1, 0, 1}; //하,좌,상,우->통과
	// int dy[4] = {0, 1, 0, -1}, dx[4] = {-1, 0, 1, 0}; //좌,상,우,하->통과
	//반시계 방향
	// int dy[4] = {1, 0, -1, 0}, dx[4] = {0, -1, 0, 1}; //상,좌,하,우->통과
	// int dy[4] = {0, -1, 0, 1}, dx[4] = {-1, 0, 1, 0}; //좌,하,우,상->통과
	// int dy[4] = {-1, 0, 1, 0}, dx[4] = {0, 1, 0, -1}; //하,우,상,좌->통과
	// int dy[4] = {0, 1, 0, -1}, dx[4] = {1, 0, -1, 0}; //우,상,좌,하->통과
	queue<Info> infoQ;
	for (int i = 0; i < 4; i++) {
		infoQ.push(Info(0, 0, i));
		cnt[i][0][0] = 0;
	}
	while (!infoQ.empty()) {
		Info now = infoQ.front();
		infoQ.pop();
		int i = now.i;
		int j = now.j;
		int direction = now.direction;
		for (int k = 0; k < 4; k++) {
			int ii = i + dy[k];
			int jj = j + dx[k];
			if (ii < 0 || ii >= n || jj < 0 || jj >= n ||
				board[ii][jj] == 1) continue;
			int direction2;
			if (i == ii) direction2 = (j < jj ? 1 : 3); // 우, 좌
			else direction2 = (i < ii ? 2 : 0); // 하, 상
			int nextCnt = cnt[direction][i][j] + ((direction + direction2) % 2 == 0 ? 100 : 600);
			if (cnt[direction2][ii][jj] > nextCnt) {
				cnt[direction2][ii][jj] = nextCnt;
				infoQ.push(Info(ii, jj, direction2));
			}
		}
	}
	//log
	// for(int i = 0; i < board.size(); i++){
	//     for(int j = 0; j < board.size(); j++){
	//         cout << cnt[i][j] << " ";
	//     }
	//     cout << "\n";
	// }
	for (int i = 0; i < 4; i++) {
		if (answer > cnt[i][n - 1][n - 1])
			answer = cnt[i][n - 1][n - 1];
	}
	//log
	// cout << answer;
	return answer;
}

/*
모범 답안
	시간복잡도
		O(N^2)
	공간복잡도
		O(N^2)
*/

/*
모범 답안 반영 전

	반례
	전체 cnt를 최소로 갱신할 수는 없을 때, 해당 direction의 flag 유무로 BFS를 실행하면
	나중에 도착한 전체 cnt를 최소로 갱신할 수는 없어도 해당 direction의 cnt는 갱신할 수 있는데 못가는 경우가 발생한다.
	그래서 BFS의 방향에 따라 테스트 케이스 정답 유무가 달라졌다.

	따라서 각 direction의 cnt를 최소로 갱신할 수 있는 경우에만 갈 수 있도록 BFS를 구현해야한다.

#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

struct Info{
	int i;
	int j;
	int direction; // 0:우, 1:상, 2:좌, 3:하
	int accum;
	Info(int a, int b, int c, int d){
		i = a;
		j = b;
		direction = c;
		accum = d;
	}
};

int solution(vector<vector<int>> board) {
	int answer = 0;
	int flag[4][25][25];
	int cnt[25][25];
	for(int i = 0; i < board.size(); i++){
		for(int j = 0; j < board.size(); j++){
			flag[0][i][j] = 0;
			flag[1][i][j] = 0;
			flag[2][i][j] = 0;
			flag[3][i][j] = 0;
			cnt[i][j] = 2147000000;
			//log
			// cnt[i][j] = 99999;
		}
	}
	//시계 방향
	// int dy[4] = {1, 0, -1, 0}, dx[4] = {0, 1, 0, -1}; //상,우,하,좌->실패
	// int dy[4] = {0, -1, 0, 1}, dx[4] = {1, 0, -1, 0}; //우,하,좌,상->통과
	// int dy[4] = {-1, 0, 1, 0}, dx[4] = {0, -1, 0, 1}; //하,좌,상,우->실패
	// int dy[4] = {0, 1, 0, -1}, dx[4] = {-1, 0, 1, 0}; //좌,상,우,하->실패
	//반시계 방향
	// int dy[4] = {1, 0, -1, 0}, dx[4] = {0, -1, 0, 1}; //상,좌,하,우->실패
	// int dy[4] = {0, -1, 0, 1}, dx[4] = {-1, 0, 1, 0}; //좌,하,우,상->통과
	// int dy[4] = {-1, 0, 1, 0}, dx[4] = {0, 1, 0, -1}; //하,우,상,좌->실패
	int dy[4] = {0, 1, 0, -1}, dx[4] = {1, 0, -1, 0}; //우,상,좌,하->통과
	queue<Info> infoQ;
	for(int i = 0; i < 4; i++){
		infoQ.push(Info(0,0,i,0));
		flag[i][0][0] = 1;
	}
	cnt[0][0] = 0;
	while(!infoQ.empty()){
		Info now = infoQ.front();
		infoQ.pop();
		int i = now.i;
		int j = now.j;
		int direction = now.direction;
		int accum = now.accum;
		for(int k = 0; k < 4; k++){
			int ii = i + dy[k];
			int jj = j + dx[k];
			if(ii < 0 || ii >= board.size() || jj < 0 || jj >= board.size() ||
			   board[ii][jj] == 1) continue;
			int direction2;
			if(i == ii) direction2 = (j < jj ? 0 : 2); // 우, 좌
			else direction2 = (i < ii ? 3 : 1); // 하, 상
			int nextCnt = accum + ((direction+direction2) % 2 == 0 ? 100 : 600);
			if(nextCnt <= cnt[ii][jj]){
				cnt[ii][jj] = nextCnt;
				infoQ.push(Info(ii,jj,direction2,nextCnt));
				flag[direction2][ii][jj] = 1;
			}else if (flag[direction2][ii][jj] == 0){
				infoQ.push(Info(ii,jj,direction2,nextCnt));
				flag[direction2][ii][jj] = 1;
			}
		}
	}
	//log
	// for(int i = 0; i < board.size(); i++){
	//     for(int j = 0; j < board.size(); j++){
	//         cout << cnt[i][j] << " ";
	//     }
	//     cout << "\n";
	// }
	answer = cnt[board.size()-1][board.size()-1];
	//log
	// cout << answer;
	return answer;
}
*/