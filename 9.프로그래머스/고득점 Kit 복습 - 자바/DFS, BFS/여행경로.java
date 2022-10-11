/*
여행경로
문제 설명
주어진 항공권을 모두 이용하여 여행경로를 짜려고 합니다. 항상 "ICN" 공항에서 출발합니다.

항공권 정보가 담긴 2차원 배열 tickets가 매개변수로 주어질 때, 방문하는 공항 경로를 배열에 담아 return 하도록 solution 함수를 작성해주세요.

제한사항
모든 공항은 알파벳 대문자 3글자로 이루어집니다.
주어진 공항 수는 3개 이상 10,000개 이하입니다.
tickets의 각 행 [a, b]는 a 공항에서 b 공항으로 가는 항공권이 있다는 의미입니다.
주어진 항공권은 모두 사용해야 합니다.
만일 가능한 경로가 2개 이상일 경우 알파벳 순서가 앞서는 경로를 return 합니다.
모든 도시를 방문할 수 없는 경우는 주어지지 않습니다.
입출력 예
tickets	return
[["ICN", "JFK"], ["HND", "IAD"], ["JFK", "HND"]]	["ICN", "JFK", "HND", "IAD"]
[["ICN", "SFO"], ["ICN", "ATL"], ["SFO", "ATL"], ["ATL", "ICN"], ["ATL","SFO"]]	["ICN", "ATL", "ICN", "SFO", "ATL", "SFO"]
입출력 예 설명
예제 #1

["ICN", "JFK", "HND", "IAD"] 순으로 방문할 수 있습니다.

예제 #2

["ICN", "SFO", "ATL", "ICN", "ATL", "SFO"] 순으로 방문할 수도 있지만 ["ICN", "ATL", "ICN", "SFO", "ATL", "SFO"] 가 알파벳 순으로 앞섭니다.

문제가 잘 안풀린다면😢
힌트가 필요한가요? [코딩테스트 연습 힌트 모음집]으로 오세요! → 클릭
*/

import java.util.*;

class Solution {
    HashMap<String,ArrayList<String>> arrivalsByDeparture = new HashMap<>();
    HashMap<String,Integer> counts = new HashMap<>();
    Stack<String> answer = new Stack<>();
    int n;
    
    public String[] solution(String[][] tickets) {
        n = tickets.length;
        
        for(String[] ticket : tickets){
            String departure = ticket[0];
            String arrival = ticket[1];
            
            ArrayList<String> arrivals = arrivalsByDeparture.getOrDefault(departure, new ArrayList<>());
            arrivals.add(arrival);
            arrivalsByDeparture.put(departure,arrivals);
            
            int count = counts.getOrDefault(departure+arrival,0);
            counts.put(departure+arrival, count+1);
        }

        for(Map.Entry<String,ArrayList<String>> entry : arrivalsByDeparture.entrySet()){
            ArrayList<String> arrivals = entry.getValue();
            arrivals.sort((a,b) -> a.compareTo(b));
        }
        
        answer.add("ICN");
        DFS("ICN");
        
        return answer.toArray(new String[0]);
    }
    
    boolean DFS(String now){
        if(answer.size() == n + 1){
            return true;
        }
        else{
            for(String next : arrivalsByDeparture.getOrDefault(now, new ArrayList<>())){
                int count = counts.get(now+next);
                if(count > 0){
                    counts.put(now+next, count-1);
                    answer.push(next);
                    if(DFS(next)) return true;
                    answer.pop();
                    counts.put(now+next, count);
                }
            }
        }
        
        return false;
    }
}

/*
    시간복잡도
		O(N^2)
	공간복잡도
		O(N)
*/