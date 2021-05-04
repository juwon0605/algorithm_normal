/*
문제 2-C
제목 최소 문자열 탐색
내용
영수는 문서 작업용 프로그램을 작성하고 있다. 기본적인 프로그램은 마무리
하고 추가적으로 새로운 문자열 탐색 기능을 구현하려고 한다.
해당 기능은 아래와 같다.
1. 영문 알파벳 대소문자로 구성된 임의의 문자열 S와 R이 주어졌을 때 S의
부분문자열(substring) 중 R의 모든 문자를 포함하는 가장 짧은 부분문자
열을 찾아낸다. 단, R의 길이는 S의 길이보다 짧거나 같고, R의 문자들
이 이 부분문자열 내에 나타나는 순서는 상관없다. 이 조건을 만족하는 S
의 부분문자열을 최소 문자열이라 정의하자. R에 같은 문자가 여러 개 있
을 경우 최소 문자열은 같은 문자들을 중복해서 포함해야 한다(즉, R이
“Aaab”이고 S가 “cacAba”라면 최소문자열은 “acAba”이다).
2. 최소 문자열이 존재하는 경우 최소 문자열의 문자 개수를 출력하고 존재
하지 않는 경우 0을 출력한다.
예를 들어, 문자열 S가 “INHACODEBANC”라 주어지고 문자열 R이 “ABC”
라 주어진다면 R의 모든 문자(A, B, C)를 포함하는 최소 문자열은 “BANC”
이며 문자 개수 4를 출력한다.
문자열 S와 R이 주어졌을 때, 위 조건을 만족하는 최소 문자열의 문자 개수
를 출력하는 프로그램을 작성하시오.
사용할 수 있는 언어는 C, C++로 제한한다. 프로그램의 실행 제한 시간은 5
초이다. C++의 경우 main 함수 내의 시작 지점에 다음 내용을 추가함으로써
cin 입력 속도를 개선할 수 있다.
std::ios::sync_with_stdio(false);
입력 형식
입력은 표준 입력으로 다음과 같이 주어진다. 첫 번째 줄에는 테스트케이스
의 수 T(≤ 1000)가 주어진다. 각 테스트케이스의 첫 번째 줄에는 문자열 S
가 주어진다. 각 테스트케이스의 두 번째 줄에는 문자열 R이 주어진다. 이후
에는 같은 형태의 테스트케이스가 T-1개 더 반복된다.
출력 형식
출력은 표준 출력으로 T줄에 걸쳐 표시하며, 각 테스트케이스 별로 탐색결과
에 따라 최소 문자열의 문자 개수 또는 0을 한 줄에 출력한다.
예
입력
4
INHACODEBANC
ABC
MERRYCHRIsTMAS
sHE
Abracadabra
Magic
cacAba
Aaab
(empty line)
출력
4
9
0
5
(empty line)
*/

#define _CRT_SECURE_NO_WARNINGS
#define INF 2147000000

#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

void DFS(int);
int *flag;
int res = INF;
string s, r;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	freopen("input.txt", "rt", stdin);
	int t;
	cin >> t;
	while (t--) {
		cin >> s >> r;
		flag = new int[r.size()];
		fill(flag, flag + r.size(), -1);
		DFS(0);
		cout << (res != INF ? res : 0) << endl;
		res = INF;
	}
	return 0;
}
void DFS(int L) {
	if (L == s.size()) {
		int minimum = INF, max = 0;
		for (int i = 0; i < r.size(); i++) {
			if (flag[i] == -1) return;
			if (minimum > flag[i]) minimum = flag[i];
			if (max < flag[i]) max = flag[i];
		}
		res = min(res, max - minimum + 1);
	}
	else {
		for (int i = 0; i < r.size(); i++) {
			if (s[L] == r[i] && flag[i] == -1) {
				flag[i] = L;
				DFS(L + 1);
				flag[i] = -1;
			}
		}
		DFS(L + 1);
	}
}

/*
모범 답안
	시간복잡도

	공간복잡도

*/

/*
모범 답안 반영전

	DFS로 완전탐색 해서 풀었음.
	시간복잡도
		O(2^N)
	공간복잡도
		O(N)

	(보완 사항)
	unoredered_map으로 S의 원소가 R의 원소에 있는지를
	O(R)이 아니라 O(1)으로 탐색할 수 있음.
	시간 복잡도
		O(2^N * NM) -> O(2^N * N)
	결과적으로 시간복잡도가 O(2^N)으로 동일해서 보완하지 않음.
*/