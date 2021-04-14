/*
02. 배열 2(문자열 뒤집기)

배열은 연속된 메모리 영역에 저장된 데이터로, 조회가 O(1), 추가 및 삭제가 O(n) 복잡도를 가지고 있다.
즉, 조회는 빠르고 추가 및 삭제는 느리다.
*/

/*
문제 2) 문자열 뒤집기
	주어진 문자열을 거꾸로 뒤집은 문자열을 만드는 함수를 작성하라.

	예) hello => olleh
	예) happy new year => reay wen yppah
*/

/*
출제 의도
	난이도: 쉬움
	배열 조회, 순회, 반복문 등 기본적인 프로그래밍 경험이 있는가?
	간단한 swap 기능을 구현할 수 있는가?
	자바의 StringBuilder API를 알고 있는가?
*/

#include<iostream>
#include<string>
using namespace std;

/*
풀이 1)
	String 변수를 만들고 거꾸로 순회하면서 읽은 Char를 삽입한다.

	시간 복잡도: O(N)
	공간 복잡도: O(N)
*/

string solution1(string &message) {
	string reverseStr;
	for (int i = message.size() - 1; i >= 0; i--) {
		reverseStr += message[i];
	}
	return reverseStr;
}

/*
풀이 2)
	String 입력을 절반 순회하면서 Swap한다.

	시간 복잡도: O(N)	O(N/2)
	공간 복잡도: O(1)
*/

string solution2(string &message) {
	int size = message.size();
	for (int i = 0; i < size / 2; i++) {
		char temp = message[i];
		message[i] = message[size - 1 - i];
		message[size - 1 - i] = temp;
	}
	return message;
}

int main() {
	string message1 = "Hello";
	string message2 = "Hello";

	cout << solution1(message1) << endl;
	cout << solution2(message2) << endl;
	return 0;
}