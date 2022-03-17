/*
최단경로
문제
방향그래프가 주어지면 주어진 시작점에서 다른 모든 정점으로의 최단 경로를 구하는 프로그램을 작성하시오. 단, 모든 간선의 가중치는 10 이하의 자연수이다.
입력
첫째 줄에 정점의 개수 V와 간선의 개수 E가 주어진다. (1 ≤ V ≤ 20,000, 1 ≤ E ≤ 300,000) 모든 정점에는 1부터 V까지 번호가 매겨져 있다고 가정한다. 둘째 줄에는 시작 정점의 번호 K(1 ≤ K ≤ V)가 주어진다. 셋째 줄부터 E개의 줄에 걸쳐 각 간선을 나타내는 세 개의 정수 (u, v, w)가 순서대로 주어진다. 이는 u에서 v로 가는 가중치 w인 간선이 존재한다는 뜻이다. u와 v는 서로 다르며 w는 10 이하의 자연수이다. 서로 다른 두 정점 사이에 여러 개의 간선이 존재할 수도 있음에 유의한다.
출력
첫째 줄부터 V개의 줄에 걸쳐, i번째 줄에 i번 정점으로의 최단 경로의 경로값을 출력한다. 시작점 자신은 0으로 출력하고, 경로가 존재하지 않는 경우에는 INF를 출력하면 된다.
예제 입력 1
5 6
1
5 1 1
1 2 2
1 3 3
2 3 4
2 4 5
3 4 6
예제 출력 1
0
2
3
7
INF
출처
빠진 조건을 찾은 사람: algoshipda
데이터를 추가한 사람: august14, djm03178, sait2000, tolelom
문제를 만든 사람: author5
*/

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

struct Edge{
	int v2;
	int cost;
	Edge(int a, int b){
		v2 = a;
		cost = b;
	}
	bool operator<(const Edge &b) const{
		return cost > b.cost;
	}
};

int main() {
	freopen("input.txt", "rt", stdin);
	int v, e, start;
	cin >> v >> e >> start;
	vector<vector<Edge>> graph(v+1);
	vector<int> distance(v + 1, INT_MAX);
	for(int i = 0; i < e; i++){
		int v1, v2, cost;
		cin >> v1 >> v2 >> cost;
		graph[v1].push_back(Edge(v2, cost));
	}

	priority_queue<Edge> edgeQ;
	edgeQ.push(Edge(start, 0));
	distance[start] = 0;
	while(!edgeQ.empty()){
		int now = edgeQ.top().v2;
		int accum = edgeQ.top().cost;
		edgeQ.pop();

		if(distance[now] < accum) continue;

		for(int i = 0; i < graph[now].size(); i++){
			int next = graph[now][i].v2;
			int cost = graph[now][i].cost;
			if(accum + cost < distance[next]){
				distance[next] = accum + cost;
				edgeQ.push(Edge(next, accum + cost));
			}
		}
	}

	for(int i = 1; i <= v; i++){
		if(distance[i] == INT_MAX) cout << "INF\n";
		else cout << distance[i] << "\n";
	}

	return 0;
}

/*
모범 답안

	시간복잡도
		O(ElogV)
	공간복잡도
		O(E)
*/