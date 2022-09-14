#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    unordered_multiset<string> answer;

    for(int i = 0; i < participant.size(); ++i){
        answer.insert(participant[i]);
    }

    for(int i = 0; i < completion.size(); ++i){
        answer.erase(answer.find(completion[i]));
    }

    return *answer.begin();
}

/*
모범 답안
    시간 복잡도
        O(N)
    공간 복잡도
        O(N)
*/