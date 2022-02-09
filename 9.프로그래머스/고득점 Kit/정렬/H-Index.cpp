/*
H-Index
문제 설명
H-Index는 과학자의 생산성과 영향력을 나타내는 지표입니다. 어느 과학자의 H-Index를 나타내는 값인 h를 구하려고 합니다. 위키백과1에 따르면, H-Index는 다음과 같이 구합니다.

어떤 과학자가 발표한 논문 n편 중, h번 이상 인용된 논문이 h편 이상이고 나머지 논문이 h번 이하 인용되었다면 h의 최댓값이 이 과학자의 H-Index입니다.

어떤 과학자가 발표한 논문의 인용 횟수를 담은 배열 citations가 매개변수로 주어질 때, 이 과학자의 H-Index를 return 하도록 solution 함수를 작성해주세요.

제한사항
과학자가 발표한 논문의 수는 1편 이상 1,000편 이하입니다.
논문별 인용 횟수는 0회 이상 10,000회 이하입니다.
입출력 예
citations	return
[3, 0, 6, 1, 5]	3
입출력 예 설명
이 과학자가 발표한 논문의 수는 5편이고, 그중 3편의 논문은 3회 이상 인용되었습니다. 그리고 나머지 2편의 논문은 3회 이하 인용되었기 때문에 이 과학자의 H-Index는 3입니다.

※ 공지 - 2019년 2월 28일 테스트 케이스가 추가되었습니다.

https://en.wikipedia.org/wiki/H-index "위키백과" ↩
*/

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {
	sort(citations.begin(), citations.end(), greater<int>());
	for (int i = 0; i < citations.size(); ++i) {
		if (citations[i] < i + 1) {
			return i;
		}
	}
	return citations.size();
}

/*
모범 답안
	내림 차순 정렬 이후
	앞에 i개는 (i-1)+1보다 작지 않았는데(i이상인데), 현재가 i+1보다 작다면(i이하라면), H-Index(최댓값)는 i다!

	시간복잡도
		O(NlogN)
	공간복잡도
		O(N)
*/

/*
모범 답안 반영 전

	충분히 1초 안으로 연산 될 것 같아서 아래 같이 풀었다.
	앞으로는 NlogN으로 풀 생각을 좀 더 해보자!

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {
	int answer = 0;
	sort(citations.rbegin(), citations.rend());
	int maxCitation = citations.front();
	for(int i = maxCitation; i > 0; i--){
		if(i <= citations.size() && citations[i-1] >= i){
			return i;
		}
	}
	return answer;
}

	시간 복잡도
		O(max(NlogN, K)) (1<=N<=1,000, 0<=K<=10,000)
	공간 복잡도
		O(N)
*/