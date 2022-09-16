/*
베스트앨범
문제 설명
스트리밍 사이트에서 장르 별로 가장 많이 재생된 노래를 두 개씩 모아 베스트 앨범을 출시하려 합니다. 노래는 고유 번호로 구분하며, 노래를 수록하는 기준은 다음과 같습니다.

속한 노래가 많이 재생된 장르를 먼저 수록합니다.
장르 내에서 많이 재생된 노래를 먼저 수록합니다.
장르 내에서 재생 횟수가 같은 노래 중에서는 고유 번호가 낮은 노래를 먼저 수록합니다.
노래의 장르를 나타내는 문자열 배열 genres와 노래별 재생 횟수를 나타내는 정수 배열 plays가 주어질 때, 베스트 앨범에 들어갈 노래의 고유 번호를 순서대로 return 하도록 solution 함수를 완성하세요.

제한사항
genres[i]는 고유번호가 i인 노래의 장르입니다.
plays[i]는 고유번호가 i인 노래가 재생된 횟수입니다.
genres와 plays의 길이는 같으며, 이는 1 이상 10,000 이하입니다.
장르 종류는 100개 미만입니다.
장르에 속한 곡이 하나라면, 하나의 곡만 선택합니다.
모든 장르는 재생된 횟수가 다릅니다.
입출력 예
genres	plays	return
["classic", "pop", "classic", "classic", "pop"]	[500, 600, 150, 800, 2500]	[4, 1, 3, 0]
입출력 예 설명
classic 장르는 1,450회 재생되었으며, classic 노래는 다음과 같습니다.

고유 번호 3: 800회 재생
고유 번호 0: 500회 재생
고유 번호 2: 150회 재생
pop 장르는 3,100회 재생되었으며, pop 노래는 다음과 같습니다.

고유 번호 4: 2,500회 재생
고유 번호 1: 600회 재생
따라서 pop 장르의 [4, 1]번 노래를 먼저, classic 장르의 [3, 0]번 노래를 그다음에 수록합니다.

장르 별로 가장 많이 재생된 노래를 최대 두 개까지 모아 베스트 앨범을 출시하므로 2번 노래는 수록되지 않습니다.
※ 공지 - 2019년 2월 28일 테스트케이스가 추가되었습니다.
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

bool compareByPlays(const pair<string, int>& a, const pair<string, int>& b){
    return a.second > b.second;
}

bool compareByPlaysAndNumber(const pair<int, int>& a, const pair<int, int>& b){
    return a.second != b.second ? a.second > b.second 
                                : a.first < b.first;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    unordered_map<string, int> playOfGenres;
    unordered_map<string, vector<pair<int,int>>> ranksOfGenres;

    for(int i = 0; i < plays.size(); ++i){
        string genre = genres[i];
        int play = plays[i];
        
        playOfGenres[genre] += play;
        ranksOfGenres[genre].push_back(make_pair(i,play));
    }

    vector<pair<string ,int>> sortedPlayOfGenres(playOfGenres.begin(), playOfGenres.end());
    sort(sortedPlayOfGenres.begin(), sortedPlayOfGenres.end(), compareByPlays);

    for(auto& ranksOfGenre : ranksOfGenres){
        sort(ranksOfGenre.second.begin(), ranksOfGenre.second.end(), compareByPlaysAndNumber);
    }

    for(auto playOfGenre : sortedPlayOfGenres){
        string genre = playOfGenre.first;
        vector<pair<int,int>> ranksOfGenre = ranksOfGenres[genre];
        
        answer.push_back(ranksOfGenre[0].first);

        if(ranksOfGenre.size() > 1){
            answer.push_back(ranksOfGenre[1].first);
        }
    }

    return answer;
}

/*
    시간복잡도
        O(NlogN)
    공간복잡도
        O(N)
*/