/*
소수 찾기
문제 설명
한자리 숫자가 적힌 종이 조각이 흩어져있습니다. 흩어진 종이 조각을 붙여 소수를 몇 개 만들 수 있는지 알아내려 합니다.

각 종이 조각에 적힌 숫자가 적힌 문자열 numbers가 주어졌을 때, 종이 조각으로 만들 수 있는 소수가 몇 개인지 return 하도록 solution 함수를 완성해주세요.

제한사항
numbers는 길이 1 이상 7 이하인 문자열입니다.
numbers는 0~9까지 숫자만으로 이루어져 있습니다.
"013"은 0, 1, 3 숫자가 적힌 종이 조각이 흩어져있다는 의미입니다.
입출력 예
numbers	return
"17"	3
"011"	2
입출력 예 설명
예제 #1
[1, 7]으로는 소수 [7, 17, 71]를 만들 수 있습니다.

예제 #2
[0, 1, 1]으로는 소수 [11, 101]를 만들 수 있습니다.

11과 011은 같은 숫자로 취급합니다.
*/

#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

void DFS(string);
bool isPrimeNumber(int);

unordered_set<int> save;
vector<int> flag;
string copyNumbers;
int answer;

int solution(string numbers) {
    
    flag.resize(numbers.size());
    copyNumbers = numbers;

    DFS("");

    return answer;
}

void DFS(string numbers){
    if(numbers != ""){

        int number = stoi(numbers);

        if(save.find(number) == save.end() && 
            isPrimeNumber(number)){
            
            ++answer;
        }

        save.insert(number);
    }

    for(int i = 0; i < copyNumbers.size(); ++i){
        if(flag[i] == 0){
            flag[i] = 1;
            DFS(numbers + copyNumbers[i]);
            flag[i] = 0;
        }        
    }
}

bool isPrimeNumber(int number){

    if(number <= 1){
        return false;
    }

    for(int i = 2; i * i <= number; ++i){
        if(number % i == 0){
            return false;
        }
    }

    return true;
}

/*
    시간복잡도
        O(N^N)
    공간복잡도
        O(N)
*/