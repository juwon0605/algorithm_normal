/*
타임머신
문제
N개의 도시가 있다. 그리고 한 도시에서 출발하여 다른 도시에 도착하는 버스가 M개 있다. 각 버스는 A, B, C로 나타낼 수 있는데, A는 시작도시, B는 도착도시, C는 버스를 타고 이동하는데 걸리는 시간이다. 시간 C가 양수가 아닌 경우가 있다. C = 0인 경우는 순간 이동을 하는 경우, C < 0인 경우는 타임머신으로 시간을 되돌아가는 경우이다.
1번 도시에서 출발해서 나머지 도시로 가는 가장 빠른 시간을 구하는 프로그램을 작성하시오.
입력
첫째 줄에 도시의 개수 N (1 ≤ N ≤ 500), 버스 노선의 개수 M (1 ≤ M ≤ 6,000)이 주어진다. 둘째 줄부터 M개의 줄에는 버스 노선의 정보 A, B, C (1 ≤ A, B ≤ N, -10,000 ≤ C ≤ 10,000)가 주어진다.
출력
만약 1번 도시에서 출발해 어떤 도시로 가는 과정에서 시간을 무한히 오래 전으로 되돌릴 수 있다면 첫째 줄에 -1을 출력한다. 그렇지 않다면 N-1개 줄에 걸쳐 각 줄에 1번 도시에서 출발해 2번 도시, 3번 도시, ..., N번 도시로 가는 가장 빠른 시간을 순서대로 출력한다. 만약 해당 도시로 가는 경로가 없다면 대신 -1을 출력한다.
예제 입력 1
3 4
1 2 4
1 3 3
2 3 -1
3 1 -2
예제 출력 1
4
3
예제 입력 2
3 4
1 2 4
1 3 3
2 3 -4
3 1 -2
예제 출력 2
-1
예제 입력 3
3 2
1 2 4
1 2 3
예제 출력 3
3
-1
출처
어색한 표현을 찾은 사람: alex9801, myungwoo, rim
문제를 만든 사람: baekjoon
데이터를 추가한 사람: djm03178, doju, ganghe74
*/

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <climits>

using namespace std;

struct Edge {
	int v1;
	int v2;
	int cost;
	Edge(int a, int b, int c) {
		v1 = a;
		v2 = b;
		cost = c;
	}
};

int main() {
	freopen("input.txt", "rt", stdin);
	int n, m;
	cin >> n >> m;
	vector<long long> distance(n + 1, INT_MAX);
	vector<Edge> edgeV;
	int a, b, c;
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		edgeV.push_back(Edge(a, b, c));
	}

	distance[1] = 0;
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < m; j++) {
			int v1 = edgeV[j].v1;
			int v2 = edgeV[j].v2;
			int cost = edgeV[j].cost;
			if (distance[v1] != INT_MAX && distance[v1] + cost < distance[v2]) {
				distance[v2] = distance[v1] + cost;
			}
		}
	}

	for (int j = 0; j < m; j++) {
		int v1 = edgeV[j].v1;
		int v2 = edgeV[j].v2;
		int cost = edgeV[j].cost;
		if (distance[v1] != INT_MAX && distance[v1] + cost < distance[v2]) {
			cout << -1;
			return 0;
		}
	}

	for (int i = 2; i < n; i++) {
		cout << (distance[i] != INT_MAX ? distance[i] : -1) << "\n";
	}
	cout << (distance[n] != INT_MAX ? distance[n] : -1);
	return 0;
}

/*
모범 답안

	벨만 포드 알고리즘 주의사항.
	diatance가 작을 때 갱신하기 때문에 모든 간선의 가중치가 -K(K>0)일 때, 매번 최대 -KM 음수만큼 작아진다.
	따라서 N번의 갱신을 하면 최대 -KNM의 음수가 발생한다.
	이 문제의 경우 int를 사용하면 -KNM = -30,000,000,000여서 underflow가 발생한다.

	시간복잡도
		O(NM)
	공간복잡도
		O(max(N,M))
*/