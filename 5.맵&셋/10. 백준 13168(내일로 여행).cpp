/*
10. 백준 13168(내일로 여행)
문제
친한 친구인 승현이와 지학이는 여름방학 때 여행을 가기로 계획했습니다. 해외여행은 금전적으로 부담이 많기 때문에 둘은 한국의 여러 도시를 여행하기로 했습니다. 한국에는 N개의 도시가 있으며, 승현이는 이 중 여행할 M개의 도시를 결정했습니다. 여행 경로에서 같은 도시를 여러 번 방문할 수 있으며, 여행을 시작하는 도시와 끝내는 도시는 같습니다.
한국에는 두 도시 사이를 오갈 수 있는 K개의 교통수단이 있습니다. 교통수단의 종류는 기차, 지하철, 버스, 택시, 비행기 등으로 다양합니다. 특히 기차 코스는 매우 세부적으로 나뉘어 있어서 무궁화호(Mugunghwa), ITX-새마을(ITX-Saemaeul), ITX-청춘(ITX-Cheongchun), KTX, S-Train, V-Train 등이 있습니다. 모든 교통수단은 한 번 이용하는 데 필요한 비용이 정해져 있습니다. 승현이와 지학이는 계획한 M개의 도시를 최소비용으로 차례대로 움직일 것입니다.
한편, 코레일에서는 ‘내일로’라는 특별한 기차표를 판매하고 있습니다. 방학 동안, 젊은 청년들은 R원을 주고 내일로 티켓을 살 수 있습니다. 한 번 내일로 티켓을 사면, 며칠 동안 무궁화호, ITX-새마을, ITX-청춘은 무료로 이용할 수 있으며, S-Train과 V-Train은 50% 할인된 가격으로 이용할 수 있습니다. KTX나 지하철, 또는 다른 교통수단에 대해서는 할인이 적용되지 않습니다.
지학이는 자신이 아무것도 하지 않는 것에 죄책감을 느끼기 때문에, 자신들의 여행에서 내일로 티켓이 필요한지 생각해보기로 했습니다. 지학이를 도와 내일로 티켓을 사는 것과 사지 않는 것 중 어떤 선택이 더 좋은 지 구하는 프로그램을 작성하세요.
입력
첫 번째 줄에는 한국에 있는 도시의 수 N(1 ≤ N ≤ 100)과 1인당 내일로 티켓의 가격 R(1 ≤ R ≤ 1,000,000)이 주어집니다. 두 번째 줄에는 N개의 도시의 이름이 주어집니다. 도시의 이름은 알파벳 대소문자로 구성된 길이 20 이하의 문자열입니다. 세 번째 줄에는 승현이와 지학이가 여행할 도시의 수 M(1 ≤ M ≤ 200)이 주어집니다. 네 번째 줄에는 승현이와 지학이가 여행할 M개 도시의 이름이 주어집니다. 이 도시들은 앞서 언급된 N개의 도시 중 하나입니다. 다섯 번째 줄에는 교통수단의 수 K(1 ≤ K ≤ 10,000)가 주어집니다. 마지막 K개의 줄에는 교통수단에 대한 정보가 주어집니다. 줄마다 교통수단의 종류 Typei, 양 끝 도시 Si, Ei, 1인당 비용 Costi (1 ≤ Costi ≤ 100,000)가 주어집니다. Typei는 ‘Subway’, ‘Bus’, ‘Taxi’, ‘Airplane’, ‘KTX’, ‘S-Train’, ‘V-Train’, ‘ITX-Saemaeul’, ‘ITX-Cheongchun’, ‘Mugunghwa’ 중 하나이며, 모든 도시는 주어진 K개의 교통수단을 이용하여 갈 수 있음이 보장되어 있습니다.
한국에는 이름이 같은 도시가 있을 수 있다. 따라서, N개의 도시의 이름에는 같은 도시의 이름이 두 번 이상 주어질 수도 있다. 이 경우 이러한 도시를 모두 같은 도시라고 생각해야 한다.
출력
한줄에 내일로 티켓을 사는 것이 좋으면 ‘Yes’를 출력하고 그렇지 않으면 ‘No’를 출력합니다. 내일로 티켓을 사더라도 비용이 정확히 같다면 ‘No’를 출력합니다.
예제 입력 1
14 40000
Boseong Busan Changwon Cheonan Chuncheon Daegu Daejeon Gwangju Jeonju Jinju Masan Seoul Suncheon Yeosu
9
Seoul Jeonju Suncheon Yeosu Suncheon Boseong Jinju Busan Seoul
23
KTX Seoul Busan 20000
KTX Seoul Gwangju 12000
KTX Gwangju Yeosu 8000
KTX Seoul Jinju 17000
ITX-Saemaeul Seoul Cheonan 7000
ITX-Cheongchun Seoul Chuncheon 3000
V-Train Chuncheon Daegu 10000
Subway Seoul Cheonan 2000
ITX-Saemaeul Cheonan Daejeon 4000
ITX-Saemaeul Daejeon Daegu 10000
ITX-Saemaeul Daegu Busan 7000
Mugunghwa Daejeon Daegu 6000
Mugunghwa Daejeon Gwangju 5000
Mugunghwa Gwangju Jeonju 1500
Mugunghwa Jeonju Suncheon 4000
Mugunghwa Suncheon Yeosu 1500
S-Train Busan Changwon 3000
S-Train Changwon Masan 1000
S-Train Masan Jinju 2000
S-Train Jinju Suncheon 2000
S-Train Suncheon Boseong 1000
Bus Busan Jinju 1500
Bus Suncheon Jinju 4000
예제 출력 1
Yes
예제 입력 2
5 50000
Seoul Cheonan Daejeon Daegu Busan
3
Seoul Busan Seoul
5
ITX-Saemaeul Seoul Cheonan 7000
ITX-Saemaeul Cheonan Daejeon 4000
ITX-Saemaeul Daejeon Daegu 10000
ITX-Saemaeul Daegu Busan 7000
KTX Seoul Busan 24999
예제 출력 2
No
힌트
예제 1에서 내일로 티켓을 구매하는 경우 최소비용은 다음과 같다.
서울 → 전주 : 0원 (서울 → 천안 → 대전 → 광주 → 전주)
전주 → 순천 : 0원 (전주 → 순천)
순천 → 여수 : 0원 (순천 → 여수)
여수 → 순천 : 0원 (여수 → 순천)
순천 → 보성 : 500원 (순천 → 보성)
보성 → 진주 : 1,500원 (보성 → 순천 → 진주)
진주 → 부산 : 1,000원 (진주 → 순천 → 전주 → 광주 → 대전 → 대구 → 부산)
부산 → 서울 : 0원 (부산 → 대구 → 대전 → 천안 → 서울)
총합 : 3,000원 + 40,000원(내일로 티켓)
내일로 티켓을 구매하지 않는 경우 최소비용은 다음과 같다.
서울 → 전주 : 12,500원 (서울 → 천안(지하철) → 대전 → 광주 → 전주)
전주 → 순천 : 4,000원 (전주 → 순천)
순천 → 여수 : 1,500원 (순천 → 여수)
여수 → 순천 : 1,500원 (여수 → 순천)
순천 → 보성 : 1,000원 (순천 → 보성)
보성 → 진주 : 3,000원 (보성 → 순천 → 진주)
진주 → 부산 : 1,500원 (진주 → 부산)
부산 → 서울 : 18,500원 (부산 → 진주 → 서울)
총합 : 43,500원
출처
University > 전국 대학생 프로그래밍 대회 동아리 연합 여름 대회 > UCPC 2016 J번
*/

#define _CRT_SECURE_NO_WARNINGS
#define INF 999999

#include<iostream>
#include<string>
#include<unordered_map>
#include<vector>
#include<algorithm>
using namespace std;

struct Edge {
	string city1;
	string city2;
	double cost;
	Edge(string a, string b, double c) {
		city1 = a;
		city2 = b;
		cost = c;
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	freopen("input.txt", "rt", stdin);
	double dp[100][100], dp2[100][100];
	unordered_map<string, int> cityToIdx;
	unordered_map<string, vector<Edge>> edgeUM;
	vector<string> pathV;
	string city, city2, transport;
	double cost, before = 0, after = 0;
	int n, r, m, k, idx = 0;
	cin >> n >> r;
	for (int i = 0; i < n; i++) {
		cin >> city;
		if (cityToIdx.find(city) == cityToIdx.end()) {
			cityToIdx[city] = idx++;
		}
		for (int j = 0; j < n; j++) {
			dp[i][j] = (i == j ? 0 : INF);
			dp2[i][j] = (i == j ? 0 : INF);
		}
	}
	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> city;
		pathV.push_back(city);
	}
	cin >> k;
	for (int i = 0; i < k; i++) {
		cin >> transport >> city >> city2 >> cost;
		edgeUM[transport].push_back(Edge(city, city2, cost));
		if (dp[cityToIdx[city]][cityToIdx[city2]] > cost) {
			dp[cityToIdx[city]][cityToIdx[city2]] = cost;
			dp[cityToIdx[city2]][cityToIdx[city]] = cost;
		}
	}
	for (int t = 0; t < idx; t++) {
		for (int i = 0; i < idx; i++) {
			for (int j = 0; j < idx; j++) {
				dp[i][j] = min(dp[i][j], dp[i][t] + dp[t][j]);
			}
		}
	}
	for (int i = 0; i < pathV.size() - 1; i++) {
		city = pathV[i];
		city2 = pathV[i + 1];
		before += dp[cityToIdx[city]][cityToIdx[city2]];
	}
	for (auto iter = edgeUM.begin(); iter != edgeUM.end(); iter++) {
		for (int i = 0; i < (*iter).second.size(); i++) {
			city = (*iter).second[i].city1;
			city2 = (*iter).second[i].city2;
			if ((*iter).first == "Mugunghwa" || (*iter).first == "ITX-Saemaeul" || (*iter).first == "ITX-Cheongchun") {
				cost = (*iter).second[i].cost = 0;
			}
			else if ((*iter).first == "S-Train" || (*iter).first == "V-Train") {
				cost = (*iter).second[i].cost /= 2;
			}
			else {
				cost = (*iter).second[i].cost;
			}
			if (dp2[cityToIdx[city]][cityToIdx[city2]] > cost) {
				dp2[cityToIdx[city]][cityToIdx[city2]] = cost;
				dp2[cityToIdx[city2]][cityToIdx[city]] = cost;
			}
		}
	}
	for (int t = 0; t < idx; t++) {
		for (int i = 0; i < idx; i++) {
			for (int j = 0; j < idx; j++) {
				dp2[i][j] = min(dp2[i][j], dp2[i][t] + dp2[t][j]);
			}
		}
	}
	for (int i = 0; i < pathV.size() - 1; i++) {
		city = pathV[i];
		city2 = pathV[i + 1];
		after += dp2[cityToIdx[city]][cityToIdx[city2]];
	}
	cout << (before > after + r ? "Yes" : "No");
	return 0;
}

/*
모범 답안
	시간복잡도
		O(N^3)
	공간복잡도
		O(N^2)
*/