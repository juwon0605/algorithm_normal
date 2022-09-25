#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

bool compareRequestTimeAndJobAmount(const vector<int> &a, const vector<int> &b){
    return a[0] != b[0] ? a[0] < b[0]
                        : a[1] < b[1];
}

struct compareJobAmount{
    bool operator()(const vector<int> &a, const vector<int> &b){
        return a[1] > b[1];
    }
};

int solution(vector<vector<int>> jobs) {

    sort(jobs.begin(), jobs.end(), compareRequestTimeAndJobAmount);

    int now = 0;
    int idx = 0;
    int accumTime = 0;
    priority_queue<vector<int>, vector<vector<int>>, compareJobAmount> diskController;

    while(idx < jobs.size() || !diskController.empty()){
        // now보다 전에 요청된 것 disckController에 삽입
        while(idx < jobs.size() && jobs[idx][0] <= now){
            diskController.push(jobs[idx]);
            ++idx;
        }

        // diskController가 empty하면 제일 앞의 jobs 삽입
        if(diskController.empty()){
            diskController.push(jobs[idx]);
            now = jobs[idx][0];
            ++idx;
        }

        // accumTime 누적
        // now 갱신
        vector<int> job = diskController.top();
        diskController.pop();
        int requestTime = job[0];
        int jobAmount = job[1];

        accumTime += now - requestTime + jobAmount;
        now += jobAmount;
    }

    return accumTime / jobs.size();
}