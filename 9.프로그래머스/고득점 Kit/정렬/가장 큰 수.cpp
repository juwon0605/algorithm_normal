﻿/*
가장 큰 수
문제 설명
0 또는 양의 정수가 주어졌을 때, 정수를 이어 붙여 만들 수 있는 가장 큰 수를 알아내 주세요.

예를 들어, 주어진 정수가 [6, 10, 2]라면 [6102, 6210, 1062, 1026, 2610, 2106]를 만들 수 있고, 이중 가장 큰 수는 6210입니다.

0 또는 양의 정수가 담긴 배열 numbers가 매개변수로 주어질 때, 순서를 재배치하여 만들 수 있는 가장 큰 수를 문자열로 바꾸어 return 하도록 solution 함수를 작성해주세요.

제한 사항
numbers의 길이는 1 이상 100,000 이하입니다.
numbers의 원소는 0 이상 1,000 이하입니다.
정답이 너무 클 수 있으니 문자열로 바꾸어 return 합니다.
입출력 예
numbers	return
[6, 10, 2]	"6210"
[3, 30, 34, 5, 9]	"9534330"
※ 공지 - 2021년 10월 20일 테스트케이스가 추가되었습니다.
*/

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool compare(string, string);

string solution(vector<int> numbers) {
	string answer = "";
	vector<string> strV;
	for (int i = 0; i < numbers.size(); i++) {
		strV.push_back(to_string(numbers[i]));
	}
	sort(strV.begin(), strV.end(), compare);
	for (int i = 0; i < strV.size(); i++) {
		answer += strV[i];
	}
	if (answer[0] == '0') {
		answer = "0";
	}
	return answer;
}

bool compare(string a, string b) {
	return a + b > b + a;
}

/*
모범 답안
	string 비교는 앞자리 아스키 코드 크기로 비교! (없음 < 숫자 < 대문자 < 소문자)

	시간복잡도
		O(NlogN)
	공간복잡도
		O(N)
*/