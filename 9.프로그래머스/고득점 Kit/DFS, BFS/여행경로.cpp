/*
여행경로
문제 설명
주어진 항공권을 모두 이용하여 여행경로를 짜려고 합니다. 항상 "ICN" 공항에서 출발합니다.

항공권 정보가 담긴 2차원 배열 tickets가 매개변수로 주어질 때, 방문하는 공항 경로를 배열에 담아 return 하도록 solution 함수를 작성해주세요.

제한사항
모든 공항은 알파벳 대문자 3글자로 이루어집니다.
주어진 공항 수는 3개 이상 10,000개 이하입니다.
tickets의 각 행 [a, b]는 a 공항에서 b 공항으로 가는 항공권이 있다는 의미입니다.
주어진 항공권은 모두 사용해야 합니다.
만일 가능한 경로가 2개 이상일 경우 알파벳 순서가 앞서는 경로를 return 합니다.
모든 도시를 방문할 수 없는 경우는 주어지지 않습니다.
입출력 예
tickets	return
[["ICN", "JFK"], ["HND", "IAD"], ["JFK", "HND"]]	["ICN", "JFK", "HND", "IAD"]
[["ICN", "SFO"], ["ICN", "ATL"], ["SFO", "ATL"], ["ATL", "ICN"], ["ATL","SFO"]]	["ICN", "ATL", "ICN", "SFO", "ATL", "SFO"]
입출력 예 설명
예제 #1

["ICN", "JFK", "HND", "IAD"] 순으로 방문할 수 있습니다.

예제 #2

["ICN", "SFO", "ATL", "ICN", "ATL", "SFO"] 순으로 방문할 수도 있지만 ["ICN", "ATL", "ICN", "SFO", "ATL", "SFO"] 가 알파벳 순으로 앞섭니다.
*/

#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

void DFS();
unordered_map<string, vector<string>> ticketM;
unordered_map<string, int> flag;
vector<string> answer, V;
int all;

vector<string> solution(vector<vector<string>> tickets) {
	all = tickets.size() + 1;
	for (int i = 0; i < tickets.size(); i++) {
		if (ticketM.find(tickets[i][0]) != ticketM.end()) {
			ticketM[tickets[i][0]].push_back(tickets[i][1]);
		}
		else {
			vector<string> tempV;
			tempV.push_back(tickets[i][1]);
			ticketM[tickets[i][0]] = tempV;
		}
		flag[tickets[i][0] + tickets[i][1]]++;
	}
	for (auto iter = ticketM.begin(); iter != ticketM.end(); iter++) {
		sort(iter->second.begin(), iter->second.end());
	}
	V.push_back("ICN");
	DFS();
	return answer;
}

void DFS() {
	if (V.size() == all) {
		answer = V;
		return;
	}
	else {
		string now = V.back();
		for (int i = 0; i < ticketM[now].size(); i++) {
			string next = ticketM[now][i];
			if (flag[now + next] > 0) {
				flag[now + next]--;
				V.push_back(next);
				DFS();
				if (V.size() == all) return;
				V.pop_back();
				flag[now + next]++;
			}
		}
	}
}

/*
모범 답안
	(주의사항)
	무조건 알파벳 순으로 가면 모든 경로를 다 못 돌 수도 있음 주의
	같은 티켓이 여러 개일 경우 주의
	tickets[0][0] != "ICN" 주의.
	
	N = 10,000이라 N^2이면 1초 초과일까봐 unordered_map으로 최악의 경우 1/8(N^2)으로 줄여서 풀어서 0.02~0.04ms 나왔는데
	구글링해보면 그냥 N^2으로 푸는게 0.01~0.02ms로 더 빨랐다...
	그래도 항상 효율성에 주의하면서 푸는 연습을 하자!

	시간복잡도
		O(N^2)
	공간복잡도
		O(N)
*/