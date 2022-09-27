#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {

    sort(citations.rbegin(), citations.rend());

    for(int i = 0; i < citations.size(); ++i){
        if(citations[i] < i + 1){
            return i;
        }
    }

    return citations.size();
}

/*
    시간복잡도
        O(NlogN)
    공간복잡도
        O(N)
*/