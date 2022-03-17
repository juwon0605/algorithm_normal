/*
최소 스패닝 트리
문제
그래프가 주어졌을 때, 그 그래프의 최소 스패닝 트리를 구하는 프로그램을 작성하시오.
최소 스패닝 트리는, 주어진 그래프의 모든 정점들을 연결하는 부분 그래프 중에서 그 가중치의 합이 최소인 트리를 말한다.
입력
첫째 줄에 정점의 개수 V(1 ≤ V ≤ 10,000)와 간선의 개수 E(1 ≤ E ≤ 100,000)가 주어진다. 다음 E개의 줄에는 각 간선에 대한 정보를 나타내는 세 정수 A, B, C가 주어진다. 이는 A번 정점과 B번 정점이 가중치 C인 간선으로 연결되어 있다는 의미이다. C는 음수일 수도 있으며, 절댓값이 1,000,000을 넘지 않는다.
그래프의 정점은 1번부터 V번까지 번호가 매겨져 있고, 임의의 두 정점 사이에 경로가 있다. 최소 스패닝 트리의 가중치가 -2,147,483,648보다 크거나 같고, 2,147,483,647보다 작거나 같은 데이터만 입력으로 주어진다.
출력
첫째 줄에 최소 스패닝 트리의 가중치를 출력한다.
예제 입력 1
3 3
1 2 1
2 3 2
1 3 3
예제 출력 1
3
출처
문제의 오타를 찾은 사람: BaaaaaaaaaaarkingDog
데이터를 추가한 사람: djm03178, ediya
빠진 조건을 찾은 사람: tjrwodnjs999
*/

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

struct Edge{
	int v1;
	int v2;
	int cost;
	Edge(int a, int b, int c){
		v1 = a;
		v2 = b;
		cost = c;
	}
	bool operator<(const Edge &b) const{
		return cost > b.cost;
	}
};

int find(int);

vector<int> parent;

int main() {
	freopen("input.txt", "rt", stdin);
	int answer = 0;
	int v, e;
	cin >> v >> e;
	parent.resize(v+1);
	for(int i = 1; i <= v; ++i){
		parent[i] = i;
	}

	priority_queue<Edge> edgeQ;
	for(int i = 0; i < e; ++i){
		int a, b, c;
		cin >> a >> b >> c;
		edgeQ.push(Edge(a, b, c));
	}

	while(!edgeQ.empty()){
		int v1 = edgeQ.top().v1;
		int v2 = edgeQ.top().v2;
		int cost = edgeQ.top().cost;
		edgeQ.pop();

		int v1Parent = find(v1);
		int v2Parent = find(v2);
		if(v1Parent != v2Parent){
			parent[v2Parent] = v1Parent;
			answer += cost;
		}
	}

	cout << answer;
	return 0;
}

int find(int v){
	if(parent[v] == v){
		return v;
	}
	else{
		return parent[v] = find(parent[v]);
	}
}

/*
모범 답안

	시간복잡도
		O(ElogE)
	공간복잡도
		O(E)
*/