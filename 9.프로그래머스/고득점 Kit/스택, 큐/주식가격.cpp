/*
주식가격
문제 설명
초 단위로 기록된 주식가격이 담긴 배열 prices가 매개변수로 주어질 때, 가격이 떨어지지 않은 기간은 몇 초인지를 return 하도록 solution 함수를 완성하세요.

제한사항
prices의 각 가격은 1 이상 10,000 이하인 자연수입니다.
prices의 길이는 2 이상 100,000 이하입니다.
입출력 예
prices	return
[1, 2, 3, 2, 3]	[4, 3, 1, 1, 0]
입출력 예 설명
1초 시점의 ₩1은 끝까지 가격이 떨어지지 않았습니다.
2초 시점의 ₩2은 끝까지 가격이 떨어지지 않았습니다.
3초 시점의 ₩3은 1초뒤에 가격이 떨어집니다. 따라서 1초간 가격이 떨어지지 않은 것으로 봅니다.
4초 시점의 ₩2은 1초간 가격이 떨어지지 않았습니다.
5초 시점의 ₩3은 0초간 가격이 떨어지지 않았습니다.
※ 공지 - 2019년 2월 28일 지문이 리뉴얼되었습니다.
*/

#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> prices) {
	int n = prices.size();
	vector<int> answer(n);
	stack<int> greaterS;
	for (int i = 0; i < n; i++) {
		while (!greaterS.empty() && prices[greaterS.top()] > prices[i]) {
			answer[greaterS.top()] = i - greaterS.top();
			greaterS.pop();
		}
		greaterS.push(i);
	}
	while (!greaterS.empty()) {
		answer[greaterS.top()] = n - greaterS.top() - 1;
		greaterS.pop();
	}
	return answer;
}

/*
모범 답안

	answer[i]를 인덱스나 크기 순서대로 채우지 않을 수 있다.
	stack에 while을 사용하면 오름차순이나 내림차순을 만드는데 효과적이다!

	시간 복잡도
		O(N)
	공간 복잡도
		O(N)
*/

/*
모범 답안 반영 전

	시간 복잡도
		O(NlogN)
	공간 복잡도
		O(N)

#include <string>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

bool comparePrice(pair<int, int>, pair<int, int>);

vector<int> solution(vector<int> prices) {
	int n = prices.size();
	vector<int> answer(n);
	vector<pair<int, int>> priceSorted;
	for (int i = 0; i < n; i++) {
		priceSorted.push_back(make_pair(i, prices[i]));
	}
	sort(priceSorted.begin(), priceSorted.end(), comparePrice);

	set<int> indexS;
	int maxIndex = -1;
	for (int i = 0; i < n; i++) {
		int nowIndex = priceSorted[i].first;
		if (maxIndex < nowIndex) {
			maxIndex = nowIndex;
			answer[nowIndex] = n - nowIndex - 1;
		}
		else {
			auto nextIter = indexS.upper_bound(nowIndex);
			answer[nowIndex] = *nextIter - nowIndex;
		}
		indexS.insert(nowIndex);
	}
	return answer;
}

bool comparePrice(pair<int, int> a, pair<int, int> b) {
	return a.second != b.second ? a.second < b.second : a.first < b.first;
}
*/