/*
조이스틱
문제 설명
조이스틱으로 알파벳 이름을 완성하세요. 맨 처음엔 A로만 이루어져 있습니다.
ex) 완성해야 하는 이름이 세 글자면 AAA, 네 글자면 AAAA

조이스틱을 각 방향으로 움직이면 아래와 같습니다.

▲ - 다음 알파벳
▼ - 이전 알파벳 (A에서 아래쪽으로 이동하면 Z로)
◀ - 커서를 왼쪽으로 이동 (첫 번째 위치에서 왼쪽으로 이동하면 마지막 문자에 커서)
▶ - 커서를 오른쪽으로 이동 (마지막 위치에서 오른쪽으로 이동하면 첫 번째 문자에 커서)
예를 들어 아래의 방법으로 "JAZ"를 만들 수 있습니다.

- 첫 번째 위치에서 조이스틱을 위로 9번 조작하여 J를 완성합니다.
- 조이스틱을 왼쪽으로 1번 조작하여 커서를 마지막 문자 위치로 이동시킵니다.
- 마지막 위치에서 조이스틱을 아래로 1번 조작하여 Z를 완성합니다.
따라서 11번 이동시켜 "JAZ"를 만들 수 있고, 이때가 최소 이동입니다.
만들고자 하는 이름 name이 매개변수로 주어질 때, 이름에 대해 조이스틱 조작 횟수의 최솟값을 return 하도록 solution 함수를 만드세요.

제한 사항
name은 알파벳 대문자로만 이루어져 있습니다.
name의 길이는 1 이상 20 이하입니다.
입출력 예
name	return
"JEROEN"	56
"JAN"	23
출처

※ 공지 - 2019년 2월 28일 테스트케이스가 추가되었습니다.
※ 공지 - 2022년 1월 14일 지문 수정 및 테스트케이스가 추가되었습니다. 이로 인해 이전에 통과하던 코드가 더 이상 통과하지 않을 수 있습니다.
*/

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(string name) {
	int n = name.size();
	int sumOfUpDown = 0;
	for (int i = 0; i < n; i++) {
		int numOfUp = name[i] - 'A';
		int numOfDown = 'Z' - name[i] + 1;
		sumOfUpDown += min(numOfUp, numOfDown);
	}

	int sumOfLeftRight = n - 1;
	for (int i = 0; i < n; i++) {
		int notAOrN = i + 1;
		while (notAOrN < n && name[notAOrN] == 'A') {
			++notAOrN;
		}
		sumOfLeftRight = min(sumOfLeftRight, i + n - notAOrN + min(i, n - notAOrN));
	}

	return sumOfUpDown + sumOfLeftRight;
}

/*
모범 답안

	한 방향으로 일직선으로 가는 경우와 최소한으로 되돌아가는 경우를 비교한다.
	최소한으로 되돌아가는 경우는 아래와 같이 계산할 수 있다.
	원점에서 i까지 거리를 a, 원점에서 i이후 A가 아닌 첫 알파벳까지 뒤로가는 경우를 b라고 했을 때
	a까지 왔다가 b까지 되돌아가거나 b까지 왔다가 a까지 되돌아가는 경우는 min(a+a+b, b+b+a) = min(2a+b, a+2b) = a+b+min(a,b)이다.
	i가 A여도 상관 없다. 그리고 i가 A일 때 A가 아닌 알파벳이 없으면 i = 0일 때 a = 0, b = n - n = 0이 된다.

	시간복잡도
		O(N)
	공간복잡도
		O(1)
*/

/*
모범 답안 반영 전

	위아래를 계산하고 나서 좌우를 제대로 계산해내지 못해서 못 풀었음.
	처음에는 왼쪽이나 오른쪽으로 한 번에 쭉가는 경우만 생각해서 틀렸음.
	되돌아가는 경우도 있음을 알고나서 매번 A가 아닌 가장 가까운 쪽으로 갔는데 틀렸음.
	최소한으로 되돌아가는 방법을 못찾고 A가 아닌 가장 먼 곳이 가까운 곳으로 이동하게 구현했는데 틀렸음.

	시간복잡도
		O(N)
	공간복잡도
		O(1)

#include <string>
#include <vector>

using namespace std;

int solution(string name) {
	int sum = 0;
	int numOfNotA = 0;
	for (int i = 0; i < name.size(); i++) {
		int numOfUp = name[i] - 'A';
		int numOfDown = 'Z' - name[i] + 1;
		sum += (numOfUp < numOfDown ? numOfUp : numOfDown);
		if (name[i] != 'A') {
			++numOfNotA;
		}
	}

	int now = 0;
	if (name[0] != 'A') {
		--numOfNotA;
	}
	while (numOfNotA--) {
		int maxRightDistance = name.size();
		int minRightDistance = name.size();
		int maxLeftDistance = name.size();
		int minLeftDistance = name.size();
		for (int i = 1; i <= name.size() / 2; i++) {
			if (name[(now + i) % name.size()] != 'A') {
				maxRightDistance = i;
				if (minRightDistance > i) {
					minRightDistance = i;
				}
			}
			if (name[now - i] != 'A') {
				maxLeftDistance = i;
				if (minLeftDistance > i) {
					minLeftDistance = i;
				}
			}
		}
		if (maxRightDistance <= maxLeftDistance) {
			now = (now + minRightDistance) % name.size();
			sum += minRightDistance;
		}
		else {
			if (now - minLeftDistance < 0) {
				now = name.size() + (now - minLeftDistance);
			}
			else {
				now -= minLeftDistance;
			}
			sum += minLeftDistance;
		}
	}
	return sum;
}
*/