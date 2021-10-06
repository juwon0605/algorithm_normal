/*
5. 호텔 연결
설명
철수는 엘리트 나라에서 발달이 잘 안된 외진 곳에 N개의 호텔들을 건설했습니다.
N(1≤N≤1,000)개의 호텔은 (편의상 1...N) 평면(0≤X≤1,000,000; 0≤Y≤1,000,000)상의 정수좌표로 위치를 나타낸다.
대부분의 호텔은 서로 연결되는 도로가 존재하지 않는다. 하지만 몇 개의 호텔은 서로 이미 도로가 연결되어 있는데,
이미 존재하는 두 개의 호텔을 연결하는 M개의 도로(1≤M≤1,000)가 주어진다. 철수는 그의 모든 호텔을 연결하는 추가적인 도로를 건설하려고 한다.
추가적으로 건설되는 도로의 거리가 최소가 되도록 여러분이 도와주세요.
입력
첫째 줄 : 2개의 정수 N, M.
둘째 줄부터 1번 호텔부터 N번 호텔까지 차례대로 N개의 X, Y자료가 주어진다.
N+2번째 줄부터는 M개의 도로 연결 정보가 주어진다. 만약 1 3으로 입력된다면
1번 호텔과 3번 호텔을 연결하는 도로는 이미 존재한다는 의미이다.
출력
모든 호텔을 연결하는 추가적인 도로의 최소 길이를 출력한다. 값은 소수 셋째 자리에서 반올림하여 출력한다.
예시 입력 1
5 2
2 1
4 1
5 1
4 3
1 2
1 2
2 3
예시 출력 1
3.41
*/

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

struct Edge {
	int start;
	int end;
	long long distance;
	Edge(int a, int b, long long c) {
		start = a;
		end = b;
		distance = c;
	}
	bool operator < (const Edge &b) const {
		return distance < b.distance;
	}
};

void link(int, int);
int find(int);
long long calDistance(pair<long long, long long>, pair<long long, long long>);
int parent[1001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	freopen("input.txt", "rt", stdin);
	vector<Edge> edgeV;
	vector<pair<long long, long long>> pV;
	double res = 0;
	long long y, x, llRes;
	int n, m, a, b;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		parent[i] = i;
	}
	pV.push_back(make_pair(0, 0)); // sentinal
	for (int i = 0; i < n; i++) {
		cin >> y >> x;
		pV.push_back(make_pair(y, x));
	}
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		if (find(a) != find(b)) {
			link(a, b);
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			if (find(i) != find(j)) {
				long long distance = calDistance(pV[i], pV[j]);
				edgeV.push_back(Edge(i, j, distance));
			}
		}
	}
	sort(edgeV.begin(), edgeV.end());
	for (int i = 0; i < edgeV.size(); i++) {
		int a = edgeV[i].start;
		int b = edgeV[i].end;
		long long distance = edgeV[i].distance;
		if (find(a) != find(b)) {
			link(a, b);
			res += sqrt(distance);
		}
	}
	cout << fixed;
	cout.precision(2);
	cout << res;
	return 0;
}

int find(int a) {
	if (parent[a] == a) return a;
	else {
		return parent[a] = find(parent[a]);
	}
}
void link(int a, int b) {
	int aParent = find(a);
	int bParent = find(b);
	parent[bParent] = aParent;
}
long long calDistance(pair<long long, long long> a, pair<long long, long long> b) {
	return (b.second - a.second) * (b.second - a.second) + (b.first - a.first)*(b.first - a.first);
}

/*
모범 답안
	시간복잡도
		O(ElongE) (1<=E<=(N-1)^2)
	공간복잡도
		O(max(N,E)) (1<=E<=(N-1)^2)
*/