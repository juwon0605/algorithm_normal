/*
4. 제품 이동
설명
섬이 많은 나라로 유명한 인도네시아는 N(1≤N≤10,000)개의 섬으로 이루어진 나라이다.
이 섬들은 다리로 연결되어 있는데, 각 다리는 통과하려면 무게제한이 있다. 이 무게제한을 넘어가면 다리는 무너지게 된다.
엘리트 무역회사는 이들 섬 중 2개에 공장이 있는데 항상 두 공장에서 서로 제품을 이동하는 작업을 한다.
섬의 개수 N과 각 섬을 연결하는 다리 정보가 주어지면 한 번의 이동으로 옮길 수 있는 제품의 최대 무게를 구하세요.
단 다리의 무게제한은 제품의 무게제한으로만 가정한다. 모든 다리는 양방향입니다.
입력
첫째 줄에 N, M(1≤M≤100,000)이 주어진다.
다음 M개의 줄에 걸처 다리에 대한 정보를 나타내는 세 자연수 A, B(1≤A, B≤N), C(1≤C≤1,000,000,000)가 주어진다.
세 자연수의 의미는 A섬과 B섬이 다리가 연결되어 있으며, 다리를 이동하는 제품의 최대 무게는 C라는 의미이다.
마지막 줄에 두 공장이 있는 섬의 번호가 주어진다.
출력
첫째 줄에 답을 출력한다.
예시 입력 1
5 6
1 2 5
1 3 3
1 4 2
2 4 2
3 4 4
4 5 3
1 5
예시 출력 1
3
*/

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct Edge {
	int v2;
	int weight;
	Edge(int a, int b) {
		v2 = a;
		weight = b;
	}
	bool operator<(const Edge &b) const {
		return weight < b.weight;
	}
};

void dijkstra(int);
vector<Edge> graph[10001];
int weightArr[10001];
int n, m;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	freopen("input.txt", "rt", stdin);
	int a, b, c, start, end;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		graph[a].push_back(Edge(b, c));
		graph[b].push_back(Edge(a, c));
	}
	cin >> start >> end;
	dijkstra(start);
	cout << weightArr[end];
	return 0;
}

void dijkstra(int start) {
	priority_queue<Edge> pQ;
	pQ.push(Edge(start, 2147000000));
	weightArr[start] = 2147000000;
	while (!pQ.empty()) {
		int cur = pQ.top().v2;
		int weight = pQ.top().weight;
		pQ.pop();
		if (weight < weightArr[cur]) continue;
		for (int i = 0; i < graph[cur].size(); i++) {
			int next = min(weight, graph[cur][i].weight);
			if (next > weightArr[graph[cur][i].v2]) {
				weightArr[graph[cur][i].v2] = next;
				pQ.push(Edge(graph[cur][i].v2, next));
			}
		}
	}
}

/*
모범 답안
	시간복잡도
		O(ElongE) 
	공간복잡도
		O(E)
*/