/*
문제 7-B
제목 계획 쇼핑의 제왕
내용
최근 자취를 시작한 김인하는 생활비 절약에 고민이 많다. 김인하는 인하마
트에서 오픈 60주년기념 특별 세일 이벤트를 진행한다는 소식을 알게 되었
다. 김인하는 이번 기회에 자취에 필요한 물품을 최소비용으로 구매 하려고
한다. 김인하는 물품 구매에 앞서 인하마트에서 판매물품 카탈로그를 받았
다. 카탈로그에는 판매하는 물품의 가격, 포장료, 세일 이벤트에 대한 규칙이
적혀 있었다.
김인하는 세일 이벤트 규칙에 따라 카탈로그에 기재된 물품번호 순서대로 물
품을 한 개 씩 구매하여야 한다. 이때, 한 종류의 물품을 두 개 이상 구매할
수는 없다(단, 물품 가격과 포장료가 0인 경우는 없으며, 각 물품 가격과 포
장료는 중복되지 않는다). 김인하는 자유롭게 구매 일정을 계획할 수 있다.
즉, 하루에 모든 물품을 구매하거나 구매 일자를 나누어 물품을 구매하는 것
모두 가능하다.
물품을 구매하기 위해서는 카탈로그에 적힌 물품 가격 및 포장료를 지불해야
한다. 하루에 물품 하나만 구매할 경우 포장료는 없다. 하지만 당일 두 번째
로 구매할 물품부터는 포장료를 추가로 지불해야한다. 또한, 쇼핑을 끝낸 후
당일 구매한 물품 중 가장 저렴한 물품의 가격과 동일한 금액의 수수료를 추
가로 지불해야 한다.
김인하는 최적의 쇼핑 계획을 세워 최소 비용으로 카탈로그의 모든 물품을
하나씩 구매하려 한다. 예를 들어, 인하마트 판매물품 카탈로그가 아래 표와
같을 경우, 김인하의 최적 쇼핑 계획은 아래 계획표와 같이 3일 동안 총
148의 비용을 지불하는 것이다.
인하마트 판매물품 카탈로그
물품번호 물품 가격 포장료
1		 7		   10
2		 50		   30
3		 3		   25
4		 5		   9
5		 29		   14
김인하의 최적 쇼핑 계획표
구매일자 구매 물품번호 물품 가격 포장료 수수료 합계
1일차	 1			   7		 0		7	   14
2일차	 2, 3		   53		 25		3	   81
3일차	 4, 5		   34		 14		5	   53
합계										   148
인하마트 판매물품 카탈로그의 물품 가격 및 포장료가 물품번호 순서대로 주
어졌을 때, 모든 물품을 하나씩 구매할 수 있는 최소 비용을 출력하는 프로
그램을 작성하시오.
사용할 수 있는 언어는 C, C++로 제한한다. 프로그램의 실행 시간은 5초를
초과할 수 없다. C++의 경우 main 함수 내의 시작 지점에 다음 내용을 추
가함으로써 cin 입력 속도가 개선되는 경우도 있다.
std::ios::sync_with_stdio(false);
입력 형식
입력은 표준입력으로 다음과 같이 주어진다. 첫 번째 줄에는 테스트케이스의
수 T(≤ 1000)가 주어진다. 각 테스트케이스의 첫 번째 줄에는 물품의 개수
N(≤ 1000)이 주어진다. 각 테스트케이스의 두 번째 줄부터 N+1 번째 줄
까지는 각 물품의 가격(≤ 1500)과 포장료(≤ 1500)가 공백 하나를 사이에 두
고 주어진다. 이후에 T-1개 테스트케이스도 같은 형식으로 주어진다.
출력 형식
출력은 표준출력으로 표시하며, 총 T줄로 구성된다. 각 테스트케이스 별로
N개의 물품을 카탈로그 순서대로 하나씩 구매할 수 있는 최소 비용을 출력
한다.
예
입력
4
5 // 위의 예제
7 10
50 30
3 25
5 9
29 14
3 // 다음 페이지 예제 1
20 5
10 3
30 12
2 // 다음 페이지 예제 2
10 30
15 20
1 // 다음 페이지 예제 3
100 50
(empty line)
출력
148
85
50
200
(empty line)
예제 1번
인하마트의 판매물품 카탈로그
물품번호 물품 가격 포장료
1		 20		   5
2		 10		   3
3		 30		   12
김인하의 최적 쇼핑 계획표
구매일자 구매 물품번호 물품 가격  포장료  수수료 합계
1일차	 1, 2, 3	   60		  15	  10	 85
합계											 85
예제 2번
인하마트의 판매물품 카탈로그
물품번호 물품 가격 포장료
1		 10		   30
2		 15		   20
김인하의 최적 쇼핑 계획표
구매일자 구매 물품번호 물품 가격 포장료 수수료 합계
1일차	 1			   10		 0		10	   20
2일차	 2			   15		 0		15	   30
합계										   50
예제 2번
인하마트의 판매물품 카탈로그
물품번호 물품 가격 포장료
1		 100	   50
김인하의 최적 쇼핑 계획표
구매일자 구매 물품번호 물품 가격 포장료 수수료 합계
1일차	 1			   100		 0		100	   200
합계										   200
*/

#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<vector>
#include<algorithm>
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
	bool operator<(const Edge &b) const {
		return cost < b.cost;
	}
};
int Find(int);
void Union(int, int);
int parent[1002];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	freopen("input.txt", "rt", stdin);
	int t, n, sumPrice, minCharge, price, packing;
	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 1; i <= n + 1; i++) {
			parent[i] = i;
		}
		vector<Edge> edgeV;
		sumPrice = 0;
		minCharge = 0;
		cin >> price >> packing;
		sumPrice += price;
		edgeV.push_back(Edge(1, n + 1, price));
		for (int i = 2; i <= n; i++) {
			cin >> price >> packing;
			sumPrice += price;
			edgeV.push_back(Edge(i, n + 1, price));
			edgeV.push_back(Edge(i - 1, i, packing));
		}
		sort(edgeV.begin(), edgeV.end());
		for (int i = 0; i < edgeV.size(); i++) {
			int v1Root = Find(edgeV[i].v1);
			int v2Root = Find(edgeV[i].v2);
			if (v1Root != v2Root) {
				Union(v1Root, v2Root);
				minCharge += edgeV[i].cost;
			}
		}
		cout << sumPrice + minCharge << endl;
	}
	return 0;
}

int Find(int v) {
	if (v == parent[v]) return v;
	else {
		return parent[v] = Find(parent[v]);
	}
}
void Union(int v1, int v2) {
	//int v1Root = Find(v1);
	//int v2Root = Find(v2);
	//if (v1Root != v2Root) parent[v2] = v1;
	parent[v2] = v1;
}

/*
모범 답안
	물품 가격의 총합은 변함이 없고 부수 비용(수수료, 포장료)의 최소를 찾는다.
	수수료와 포장료의 최소를 각 물건과 수수료노드(가정)의 MST로 나태낼 수 있다.
	수수료를 수수료노드(가정)와 물건 사이의 비용으로 나타내고,
	포장료를 각 물건 사이의 비용으로 나태낼 수 있다.

	시간 복잡도
		O(TNlogN) (E = 2N)
		O(TElogE) (E는 간선의 개수)
	공간 복잡도
		O(N)
*/

/*
모범 답안 반영전

	DFS에서 for문으로 1~N까지 재귀적으로 DFS의 파라미터로 넣어주면서
	경로를 배열에 저장하여 모든 경우의 수를 나타내고
	각 경우의 총 비용을 계산하여 그 중 최소값을 알아내었다.

	답은 나오나 모든 경우의 수를 계산한다는 점에서
	최소의 연산만 수행하는 MST 방법보다 오래걸린다.

	시간 복잡도
		O(TN^2)
		(아래의 경우 시간 복잡도 계산하는 방법을 정확히 모르겠어서 어림 잡음)
	공간 복잡도
		O(N)


#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
using namespace std;

void DFS(int);
int catalogArr[1000][2];
int buyNumArr[1000];
int n, res, days;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	freopen("input.txt", "rt", stdin);
	int t;
	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> catalogArr[i][0];
			cin >> catalogArr[i][1];
		}
		res = 2147000000;
		days = 0;
		DFS(0);
		cout << res << endl;
	}
	return 0;
}

void DFS(int L) {
	if (L == n) {
		int sum = 0;
		int nowItem = 0;
		for (int i = 0; i < days; i++) {
			if (buyNumArr[i] == 1) {
				sum += (catalogArr[nowItem][0] * 2);
				nowItem++;
			}
			else {
				int minPrice = catalogArr[nowItem][0];
				sum += catalogArr[nowItem][0];
				nowItem++;
				for (int j = 1; j < buyNumArr[i]; j++) {
					if (catalogArr[nowItem][0] < minPrice) minPrice = catalogArr[nowItem][0];
					sum += catalogArr[nowItem][0];
					sum += catalogArr[nowItem][1];
					nowItem++;
				}
				sum += minPrice;
			}
		}
		if (sum < res) res = sum;
	}
	else {
		for (int i = 1; i <= n; i++) {
			if (L + i <= n) {
				buyNumArr[days] = i;
				days++;
				DFS(L + i);
				days--;
			}
		}
	}
}
*/