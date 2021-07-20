/*
05. 백준 1351(무한 수열)
문제
무한 수열 A는 다음과 같다.
A0 = 1
Ai = A⌊i/P⌋ + A⌊i/Q⌋ (i ≥ 1)
N, P와 Q가 주어질 때, AN을 구하는 프로그램을 작성하시오.
입력
첫째 줄에 3개의 정수 N, P, Q가 주어진다.
출력
첫째 줄에 AN을 출력한다.
제한
0 ≤ N ≤ 1012
2 ≤ P, Q ≤ 109
예제 입력 1
7 2 3
예제 출력 1
7
힌트
⌊x⌋는 x를 넘지 않는 가장 큰 정수이다.
*/

#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<unordered_map>
using namespace std;

long long DFS(long long);
unordered_map<long long, long long> uM;
int p, q;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	freopen("input.txt", "rt", stdin);
	uM[0] = 1;
	long long n;
	cin >> n >> p >> q;
	cout << DFS(n);
	return 0;
}

long long DFS(long long L) {
	if (uM.find(L) != uM.end()) return uM[L];
	else {
		long long left = DFS(L / p);
		long long right = DFS(L / q);
		return uM[L] = left + right;
	}
}

/*
모범 답안
	시간복잡도
		O(logN)
	공간복잡도
		O(logN)
*/