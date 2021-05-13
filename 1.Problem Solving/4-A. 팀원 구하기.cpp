/*
문제 4-A
제목 팀원 구하기
내용
인하대학교 컴퓨터공학과의 수업 X에서는 N명의 학생들이 기말고사로 팀
프로젝트를 진행한다. 팀을 이루는 학생들의 수와 팀의 수는 제한이 없다.
즉, N명의 모든 학생들이 1개의 팀을 이룰 수도 있고, 1명으로 이루어진 팀
이 N개인 경우도 있을 수 있다. 각 학생들 마다 함께 팀원이 되고 싶은 사
람(자기자신을 포함)을 지목할 수 있는 기회가 1번 있다. 이 때, t
(1 ≤ t ≤ N)명의 학생들이 한 팀을 이룰 수 있는 조건은 아래와 같다.
각 학생들을 si (1 ≤ i ≤ N)라 할 때, si가 팀원이 되고 싶어하는 sj를 지목
하면 <i,j>라 표현하기로 하자. 이때, <i,j1>, <j1,j2>, ... , 
<jk,j>, <j,i>가 성립하면 (i,j1,...,jk,j)는 반드시 한 팀을 이루게 된다.
예를 들어, X 수업을 수강하는 10명의 학생들이 있고, 각 학생마다 팀원을
이루고 싶은 사람을 지목한 결과가 다음과 같다고 하자.
학생번호 s1  s2 s3 s4 s5 s6 s7 s8 s9 s10
지목결과 s4 s10 s1 s4 s6 s2 s8 s9 s7 s5
위의 결과를 통해, (s2,s5,s6,s10) , (s7,s8,s9) , (s4) 로 팀 3개가 만들어 졌
고, s1과 s4은 어느 팀에도 속하지 않는다.
학생번호들과 해당 학생들의 지목결과가 주어질 때, 어느 팀에도 속하지 않
는 학생들의 수를 계산하는 프로그램을 작성하시오.
사용 할 수 있는 언어는 C, C++로 제한한다. 프로그램의 실행시간은 5초를
초과할 수 없다. C++의 경우 main 함수 내의 시작 지점에 다음 내용을 추
가하면 cin입력 속도가 개선되는 경우도 있다.
std::ios::sync_with_stdio(false);
입력 형식
입력은 표준입력으로 다음과 같이 주어진다.
1. 첫 번째 줄에는 테스트케이스의 수 T가 주어진다. (1 ≤ T ≤ 100)
2. 두 번째 줄에는 첫 번째 테스트케이스에 대한 수업 X의 수강생 수 N
(1 ≤ N ≤ 10,000)이 주어진다.
3. 세 번째 줄에는 1번부터 N번까지의 학생들이 각각 지목한 학생들의 번호
가 공백을 사이에 두고 차례로 주어진다.
4. 그 이후에 각 테스트케이스마다 위의 2, 3단계가 T-1번 반복된다.
출력 형식
출력은 표준출력으로 수행하며 총 T줄로 이루어진다. 각 줄에는 각 테스트
케이스 별로 어느 팀에도 속하지 않는 학생들의 수를 출력한다
예
입력 
3
7
3 1 3 7 3 4 6
10
4 10 1 4 6 2 8 9 7 5 8
1 2 3 4 5 6 7 8
(empty line)
출력 
3
2
0
(empty line)
*/

#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<vector>
using namespace std;

int DFS(int);
int sArr[10001];
int flag[10001];
bool flagOff;
int start, res;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	freopen("input.txt", "rt", stdin);
	int t, n;
	cin >> t;
	while (t--) {
		cin >> n;
		fill(flag, flag + n + 1, 0);
		res = 0;
		for (int i = 1; i <= n; i++) {
			cin >> sArr[i];
		}
		for (int i = 1; i <= n; i++) {
			if (flag[i] > 0) continue;
			start = i;
			if (DFS(sArr[i]) != 0) res++;
			flag[i] = i;
		}
		cout << res << endl;
	}
	return 0;
}
int DFS(int s) {
	if (s == start) {
		return 0;
	}
	else if (flag[s] == start) {
		flagOff = false;
		return s;
	}
	else if (flag[s] > 0) {
		return -1;
	}
	else {
		flag[s] = start;
		int check =  DFS(sArr[s]);
		if (check > 0) {
			if (flagOff) flag[s] = 0;
			if (check == s) flagOff = true;			
		}
		else if (check == -1) flag[s] = 0;
		return check;
	}
}

/*
모범 답안
	visit 배열과 finish 배열을 만들어서 flag 상태를 비교

	시간복잡도
		O(TN)
	공간복잡도
		O(N)
*/

/*
모범 답안 반영전
	난 flag에 각 시작 인덱스를 저장해감으로서 cycle과 subcycle을 구별했음!
	DFS의 return값에 따라 아래와 같이 구분
	1.s == start:				cycle(flag 유지)
	2.flag[s] == start:			subcycle(발생 이후부터 flag 초기화)
	3.falg[s](!= start) > 0:	이전에 찾은 subcycle과 연결(전부 flag 초기화)
*/