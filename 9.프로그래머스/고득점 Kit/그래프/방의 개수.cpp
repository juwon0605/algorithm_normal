/*
순위
문제 설명
n명의 권투선수가 권투 대회에 참여했고 각각 1번부터 n번까지 번호를 받았습니다. 권투 경기는 1대1 방식으로 진행이 되고, 만약 A 선수가 B 선수보다 실력이 좋다면 A 선수는 B 선수를 항상 이깁니다. 심판은 주어진 경기 결과를 가지고 선수들의 순위를 매기려 합니다. 하지만 몇몇 경기 결과를 분실하여 정확하게 순위를 매길 수 없습니다.

선수의 수 n, 경기 결과를 담은 2차원 배열 results가 매개변수로 주어질 때 정확하게 순위를 매길 수 있는 선수의 수를 return 하도록 solution 함수를 작성해주세요.

제한사항
선수의 수는 1명 이상 100명 이하입니다.
경기 결과는 1개 이상 4,500개 이하입니다.
results 배열 각 행 [A, B]는 A 선수가 B 선수를 이겼다는 의미입니다.
모든 경기 결과에는 모순이 없습니다.
입출력 예
n	results	return
5	[[4, 3], [4, 2], [3, 2], [1, 2], [2, 5]]	2
입출력 예 설명
2번 선수는 [1, 3, 4] 선수에게 패배했고 5번 선수에게 승리했기 때문에 4위입니다.
5번 선수는 4위인 2번 선수에게 패배했기 때문에 5위입니다.

출처
*/

#include <string>
#include <vector>
#include <set>

using namespace std;

int solution(vector<int> arrows) {
	int answer = 0;
	int dy[8] = { -1,-1,0,1,1,1,0,-1 };
	int dx[8] = { 0,1,1,1,0,-1,-1,-1 };
	set<pair<int, int>> flag;
	set<pair<pair<int, int>, pair<int, int>>> edge;

	pair<int, int> before = { 0,0 };
	flag.insert(before);
	for (int k = 0; k < arrows.size(); k++) {
		int direction = arrows[k];
		for (int kk = 0; kk < 2; kk++) {
			int ii = before.first + dy[direction];
			int jj = before.second + dx[direction];
			pair<int, int> now = { ii,jj };
			if (flag.find(now) != flag.end() &&
				edge.find(make_pair(before, now)) == edge.end()) {
				edge.insert(make_pair(before, now));
				edge.insert(make_pair(now, before));
				++answer;
			}
			else {
				flag.insert(now);
				edge.insert(make_pair(before, now));
				edge.insert(make_pair(now, before));
			}
			before = now;
		}
	}

	return answer;
}

/*
모범 답안

	1.flag가 표시된 지점에 다시 방문했는데, 없었던 간선이라면 방 발생!
	   (flag가 표시된 지점에 다시 방문했는데, 있었던 간선이라면 중복)
	2.점과 점 사이의 선끼리 교차되는 것을 표현하기 위해 점을 두 번 씩 이동!

	unordered를 사용하면 O(N)으로도 풀 수 있지만,
	unordered를 사용하기 위해서는 hash와 operator ==를 둘 다 정의해줘야한다.
	반면 map,set을 사용하기 위해서는 operator <만 정의해주면 된다.
	pair에는 operator ==와 operator <가 이미 정의되어 있기 때문에
	풀이 시간을 고려해 hash를 따로 정의해 unordered_set을 사용하기 보다 set을 사용했다.

	앞으로도 풀이시간을 고려해 구조체의 O(1)탐색이 필요하다면
	구조체에 opertor <만 정의하고 map,set을 사용해서 NlogN으로 빠르게 풀자.

	시간복잡도
		O(NlogN)
	공간복잡도
		O(N)
*/

/*
모범 답안 반영 전

	1.DFS로 사이클이 발생한 부분을 flag로 표시
	2.flag가 표시된 지점에서 출발하면 바로 다음이 아닌 flag가 표시된 지점을 만났을 때 그 경로를 flag로 표시
	주어진 모든 지점에서 위의 두 가지 함수에 대입해 풀려고 했으나,
	구현이 복잡하고 정답을 학습하는 게 효율적일 것 같아서 구현 중 포기함.
	아래 코드는 에러가 발생하는 상태.

	시간복잡도
		O(N^2)
	공간복잡도
		O(N^3)

#include <string>
#include <vector>
#include <queue>

using namespace std;

struct Info{
	int i;
	int j;
	int direction;
	Info(int a, int b, int c){
		i = a;
		j = b;
		direction = c;
	}
};

void isCycleDFS(int,int,int);

vector<vector<vector<int>>> map;
vector<vector<int>> flag;
vector<vector<int>> cycle;
int dy[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dx[8] = {0, 1, 1, 1, 0, -1, -1, -1};
pair<int,int> cyclePoint;
bool isCycle = false;
int answer;

int solution(vector<int> arrows) {
	queue<Info> infoQ;
	int n = arrows.size();
	map.resize(2 * n + 1, vector<vector<int>>(2 * n + 1));
	int y = n;
	int x = n;
	for(int i = 0; i < n; i++){
		int direction = arrows[i];
		map[y][x].push_back(direction);
		infoQ.push(Info(y,x,direction));
		y += dy[direction];
		x += dx[direction];
	}

	while(!infoQ.empty()){
		int i = infoQ.front().i;
		int j = infoQ.front().j;
		int direction = infoQ.front().direction;
		infoQ.pop();
		isCycleDFS(i, j, direction);

	}

	return answer;
}

void isCycleDFS(int i,int j, int direction){
	if(flag[i][j] == 1){
		return;
	}
	if(cycle[i][j] == 1){
		isCycle = !isCycle;
		cyclePoint.first = i;
		cyclePoint.second = j;
		++answer;
		return;
	}
	else{
		cycle[i][j] = 1;
		int ii = i + dy[direction];
		int jj = j + dx[direction];
		for(int k = 0; k < map[ii][jj].size(); k++){
			isCycleDFS(ii,jj,map[ii][jj][k]);
		}
		cycle[i][j] = 0;
		if(isCycle){
			flag[i][j] = 1;
			if(i == cyclePoint.first && j == cyclePoint.second){
				isCycle = !isCycle;
			}
		}
	}
}
*/