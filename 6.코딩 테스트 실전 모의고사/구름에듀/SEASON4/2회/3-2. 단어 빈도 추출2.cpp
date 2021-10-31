/*
3-2. 단어 빈도 추출2
*/

#include<string>
#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<set>
using namespace std;

#define LF "\n"

/** 이미 작성된 코드들은 사용하지 않아도 무관합니다.
** 필요하다면 수정/삭제하고 스스로 작성하세요.
*/


/** 입력으로 주어진 모든 줄들을 입력받아 벡터에 채워주는 반환해주는 함수 **/
void readAllLines(vector<string> &lines);
bool compare(pair<string, int>, pair<string, int>);

int main() {
	ios_base::sync_with_stdio(false);
	//모든 줄을 입력받아 준다
	vector<string> lines;
	readAllLines(lines);

	unordered_map<string, int> uM;
	unordered_map<string, set<int>> uMS;
	vector<pair<string, int>> pV;
	string str;
	for (int i = 0; i < lines.size(); i++) {
		str = lines[i];
		//문자열 분리
		//unordered_map에 count
		string temp;
		for (int j = 0; j < str.size(); j++) {
			if (str[j] >= 'A' && str[j] <= 'Z') str[j] += 'a' - 'A';
			if (str[j] >= 'a' && str[j] <= 'z') temp += str[j];
			else {
				if (temp != "") {
					uM[temp]++;
					if (uMS[temp].size() == 10) uMS[temp].erase(uMS[temp].begin());
					uMS[temp].insert(i + 1);
				}
				temp = "";
			}
		}
		if (temp != "") {
			uM[temp]++;
			if (uMS[temp].size() == 10) uMS[temp].erase(uMS[temp].begin());
			uMS[temp].insert(i + 1);
		}
	}
	//uM에서 pV로 담기
	for (auto iter = uM.begin(); iter != uM.end(); iter++) {
		pV.push_back(make_pair(iter->first, iter->second));
	}
	//1.빈도수 2.사전순 정렬
	sort(pV.begin(), pV.end(), compare);
	//최대 100개까지 출력
	int cnt = 1;
	for (int i = 0; i < pV.size(); i++) {
		cout << pV[i].first;
		for (auto iter = uMS[pV[i].first].begin(); iter != uMS[pV[i].first].end(); iter++) {
			cout << " " << *iter;
		}
		cout << "\n";
		if (cnt >= 100) break;
		cnt++;
	}
	return 0;
}

bool compare(pair<string, int> a, pair<string, int> b) {
	return (a.second != b.second ? a.second > b.second : a.first < b.first);
}
void readAllLines(vector<string> &lines)
{
	lines.clear();
	std::string line;
	while (std::getline(std::cin, line))
	{
		lines.push_back(line);
	}
}

/*
모범 답안
	시간복잡도
		O(TNlogTN)
	공간복잡도
		O(TN)
*/