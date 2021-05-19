/*
문제 5-A
제목 회문 판별
내용
인하대 컴퓨터공학과 김인하 학생은 영문 알파벳 대소문자와 특수문자로 구
성된 공백이 없는 문자열에 대한 회문 판별 프로그램을 작성하려 한다. 여기
서, 회문(回文, palindrome)이란 뒤에서부터 읽어도 앞에서부터 읽었을 때와
같은 순서의 문자로 구성되는 문자열을 의미한다. 단, 이 프로그램은 회문
판별 시 알파벳의 대소문자를 구분하지 않으며, 특수문자도 회문 판별 시 고
려하지 않는다. 또한, 문자열에는 영문 알파벳이 한 글자 이상 포함된다. 예
를 들어, 문자열 “Eye!”, “Radar”는 회문이다. 하지만 문자열 “Book”,
“Inha_university”는 회문이 아니다.
임의의 문자열 S가 주어졌을 때, S가 회문일 경우 “Yes”, 회문이 아닐 경우
“No”를 출력하는 프로그램을 작성하시오. 단, 영문 알파벳 한 글자로 구성된
문자열의 경우 회문으로 간주한다.
사용할 수 있는 언어는 C, C++로 제한한다. 프로그램의 실행 시간은 5초를
초과할 수 없다. C++의 경우 main 함수 내의 시작 지점에 다음 내용을 추
가함으로써 cin 입력 속도가 개선되는 경우도 있다.
std::ios::sync_with_stdio(false);
입력 형식
입력은 표준입력으로 다음과 같이 주어진다. 첫 번째 줄에는 테스트케이스의
수 T(≤ 1000)가 주어진다. 이후 T줄에는 각 테스트케이스의 문자열 S 가
한 줄에 하나씩 주어진다. 문자열 의 최대 길이는 10,000자이다.
출력 형식
출력은 표준출력으로 표시하며, 총 T줄로 구성된다. 각 줄에는 테스트케이스
별로 문자열 가 회문일 경우 “Yes"를, 아닐 경우는 “No”를 출력한다.
예
입력
4
Eye!
Adam
Inha_University!
race!car?
(empty line)
출력
Yes
No
No
Yes
(empty line)
*/

#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

bool isValid(int);
bool isSame(int, int);
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	freopen("input.txt", "rt", stdin);
	string s;
	int t;
	cin >> t;
	while (t--) {
		cin >> s;
		bool isCircular = true;
		int start = 0;
		int end = s.size() - 1;
		while (start <= end) {
			while (!isValid(s[start])) start++;
			while (!isValid(s[end])) end--;
			if (!isSame(s[start], s[end])) {
				isCircular = false;
				break;
			}
			start++;
			end--;
		}
		cout << (isCircular ? "Yes" : "No") << endl;
	}
	return 0;
}

bool isValid(int readInt) {
	if ((readInt >= 65 && readInt <= 90)
		|| (readInt >= 97 && readInt <= 122)) {
		return true;
	}
	return false;
}

bool isSame(int a, int b) {
	if (a == b) return true;
	else if (abs(a - b) == 32) return true;
	return false;
}

/*
모범 답안
	시간 복잡도
		O(TN)
	공간 복잡도
		O(N)
*/