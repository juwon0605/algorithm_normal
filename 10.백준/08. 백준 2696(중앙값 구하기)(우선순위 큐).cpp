/*
중앙값 구하기
어떤 수열을 읽고, 홀수번째 수를 읽을 때 마다, 지금까지 입력받은 값의 중앙값을 출력하는 프로그램을 작성하시오.
예를 들어, 수열이 1, 5, 4, 3, 2 이면, 홀수번째 수는 1번째 수, 3번째 수, 5번째 수이고, 1번째 수를 읽었을 때 중앙값은 1, 3번째 수를 읽었을 때는 4, 5번째 수를 읽었을 때는 3이다.
입력
첫째 줄에 테스트 케이스의 개수 T(1 ≤ T ≤ 1,000)가 주어진다. 각 테스트 케이스의 첫째 줄에는 수열의 크기 M(1 ≤ M ≤ 9999, M은 홀수)이 주어지고, 그 다음 줄부터 이 수열의 원소가 차례대로 주어진다. 원소는 한 줄에 10개씩 나누어져있고, 32비트 부호있는 정수이다.
출력
각 테스트 케이스에 대해 첫째 줄에 출력하는 중앙값의 개수를 출력하고, 둘째 줄에는 홀수 번째 수를 읽을 때 마다 구한 중앙값을 차례대로 공백으로 구분하여 출력한다. 이때, 한 줄에 10개씩 출력해야 한다.
예제 입력 1
3
9
1 2 3 4 5 6 7 8 9
9
9 8 7 6 5 4 3 2 1
23
23 41 13 22 -3 24 -31 -11 -8 -7
3 5 103 211 -311 -45 -67 -73 -81 -99
-33 24 56
예제 출력 1
5
1 2 3 4 5
5
9 8 7 6 5
12
23 23 22 22 13 3 5 5 3 -3
-7 -3
출처
ICPC > Regionals > North America > Greater New York Region > 2009 Greater New York Programming Contest D번
문제를 번역한 사람: baekjoon
잘못된 데이터를 찾은 사람: tncks0121
*/


#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <vector>
#include <set>

using namespace std;

int main() {
	freopen("input.txt", "rt", stdin);
	int t;
	cin >> t;
	while (t--) {
		int m;
		cin >> m;
		vector<int> numV(m);
		for (int i = 0; i < m; i++) {
			cin >> numV[i];
		}
		vector<int> answerV;

		multiset<int> multiS;
		multiS.insert(numV[0]);
		auto iter = multiS.find(numV[0]);
		answerV.push_back(*iter);

		for (int i = 1; i < m; ++i) {
			int now = numV[i];
			multiS.insert(now);
			if (now < *iter) {
				--iter;
			}
			if (i % 2 == 0) {
				++iter;
				answerV.push_back(*iter);
			}
		}

		cout << answerV.size() << "\n";
		for (int i = 0; i < answerV.size(); ++i) {
			if (i != 0 && i % 10 == 0) cout << "\n";
			cout << answerV[i] << " ";
		}
		cout << "\n";
	}

	return 0;
}


/*
모범 풀이1

	시간복잡도
		O(TMlogM)
	공간복잡도
		O(M)
*/

/*
모범 풀이2

	시간복잡도
		O(TMlogM)
	공간복잡도
		O(M)

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
	freopen("input.txt", "rt", stdin);
	int t;
	cin >> t;
	while (t--) {
		int m;
		cin >> m;
		vector<int> numV(m);
		for (int i = 0; i < m; i++) {
			cin >> numV[i];
		}
		vector<int> answerV;
		int center = numV[0];
		answerV.push_back(center);

		priority_queue<int> smallQ;
		priority_queue<int, vector<int>, greater<int>> largeQ;
		for (int i = 1; i < m; ++i) {
			int now = numV[i];
			if(now < center) smallQ.push(now);
			else largeQ.push(now);

			if(i % 2 == 0){
				while(smallQ.size() > largeQ.size()){
					largeQ.push(center);
					center = smallQ.top();
					smallQ.pop();
				}
				while(smallQ.size() < largeQ.size()){
					smallQ.push(center);
					center = largeQ.top();
					largeQ.pop();
				}
				answerV.push_back(center);
			}

		}

		cout << answerV.size() << "\n";
		for (int i = 0; i < answerV.size(); i++) {
			if (i != 0 && i % 10 == 0) cout << "\n";
			cout << answerV[i] << " ";
		}
		cout << "\n";
	}

	return 0;
}
*/

/*
모범 풀이 반영 전

	답은 맞았음!

	시간복잡도
		O(TMlogM)
	공간복잡도
		O(M)

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
	freopen("input.txt", "rt", stdin);
	int t;
	cin >> t;
	while (t--) {
		int m;
		cin >> m;
		vector<int> numV(m);
		for (int i = 0; i < m; i++) {
			cin >> numV[i];
		}
		vector<int> answerV;
		int center = numV[0];
		answerV.push_back(center);

		priority_queue<int> smallQ;
		priority_queue<int, vector<int>, greater<int>> largeQ;
		for (int i = 1; i < m; i += 2) {
			int first = numV[i];
			int second = numV[i + 1];
			if (center < first && center < second) {
				largeQ.push(first);
				largeQ.push(second);
				smallQ.push(center);
				center = largeQ.top();
				largeQ.pop();
			}
			else if (first < center && second < center) {
				smallQ.push(first);
				smallQ.push(second);
				largeQ.push(center);
				center = smallQ.top();
				smallQ.pop();
			}
			else {
				smallQ.push(min(first, second));
				largeQ.push(max(first, second));
			}
			answerV.push_back(center);
		}

		cout << answerV.size() << "\n";
		for (int i = 0; i < answerV.size(); i++) {
			if (i != 0 && i % 10 == 0) cout << "\n";
			cout << answerV[i] << " ";
		}
		cout << "\n";
	}

	return 0;
}
*/