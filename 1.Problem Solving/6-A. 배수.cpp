/*
문제 6-A
제목 배수
내용
두 자연수 A, B가 주어질 때 A(< 10^1000)가 B(<100,000)의 배수인지 판정하
는 프로그램을 작성하시오.
사용할 수 있는 언어는 C, C++로 제한한다. 프로그램의 실행 시간은 1초이
다. C++의 경우 main 함수 내의 시작 지점에 다음 내용을 추가하면 cin 입
력 속도가 개선되는 경우도 있다.
std::ios::sync_with_stdio(false);
입력 형식
입력은 표준입력으로 다음과 같이 주어진다. 첫 줄에는 테스트케이스의 수
T(≤ 10,000)가 주어지며, 둘째 줄부터는 각 테스트케이스를 구성하는 2개의
숫자 A(< 10^1000), B(<100,000)가 빈 칸 하나를 사이에 두고 각 줄에 주어진
다.
출력 형식
출력은 표준출력으로 표시하며, 총 T줄로 구성된다. 각 테스트케이스 별로
A가 B의 배수인지 여부(배수라면 1, 아니라면 0)을 한 줄에 하나씩 출력한
다.
예
입력
2
306580397317560752981 23171
2852841814435297692 23171
(empty line)
출력
1
0
(empty line)
*/

#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	freopen("input.txt", "rt", stdin);
	string a;
	string::iterator iter;
	int t, b, res;
	cin >> t;
	while (t--) {
		cin >> a >> b;
		res = 0;
		for (iter = a.begin(); iter != a.end(); iter++) {
			res *= 10;
			res += (*iter - '0');
			res %= b;
		}
		cout << (res == 0 ? 1 : 0) << endl;
	}
	return 0;
}

/*
모범 답안
	시간 복잡도
		O(TN)
	공간 복잡도
		O(N)
*/

/*
모범 답안 반영전

B의 자리수 크기로 나눠서 %을 진행했는데 10의 단위로 나눠서 %를 진행해도 동일함
풀 때에는 A가 매우 크다고 생각해서 iterator로 for문을 돌렸는데,
생각해보니 A.size() < 1000이어서 iterator 안 써도 int로 for문 사용 가능

#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<string>
#include<cmath>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	freopen("input.txt", "rt", stdin);
	string a, subA;
	string::iterator iter;
	int t, b, temp, bDigit, cntDigit, res;
	cin >> t;
	while (t--) {
		cin >> a >> b;
		iter = a.begin();
		temp = b;
		res = bDigit = cntDigit = 0;
		while (temp) {
			temp /= 10;
			bDigit++;
		}
		while (iter + bDigit < a.end()) {
			string subA;
			for (int i = 0; i < bDigit; i++) {
				subA += *iter;
				iter++;
			}
			res *= pow(10, bDigit);
			res += stoi(subA);
			res %= b;
		}
		string subA;
		while (iter != a.end()) {
			subA += *iter;
			iter++;
			cntDigit++;
		}
		res *= pow(10, cntDigit);
		res += stoi(subA);
		res %= b;
		cout << (res == 0 ? 1 : 0) << endl;
	}
	return 0;
}
*/