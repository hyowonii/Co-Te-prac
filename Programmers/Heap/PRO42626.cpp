/*
  프로그래머스 [더 맵게]
  https://school.programmers.co.kr/learn/courses/30/lessons/42626
  heap
*/

// 정확성 통과, 시간 초과 코드
/*
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int calcul(int a, int b){
    return a + b * 2;
}

int solution(vector<int> scoville, int K) {
    int answer = 0;
    
    vector<int>::iterator iter;
    iter = scoville.begin();
    
    while(1){
        sort(scoville.begin(), scoville.end());
        if(scoville[0]>=K) return answer;
        if(scoville.size() == 1) return -1;
        
        answer++;
        int newScov = calcul(scoville[0], scoville[1]);
        scoville.erase(scoville.begin()+1); scoville.erase(scoville.begin()); 
        scoville.push_back(newScov);
        cout<<newScov<<"\n";
    }
    
    return answer;
}
*/

// 정답 코드
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

int calcul(int a, int b){
    return a + b * 2;
}

int solution(vector<int> scoville, int K) {
    int answer = 0;
    
    priority_queue<int, vector<int>, greater<int>> pq(scoville.begin(), scoville.end());
    
    while(pq.size() > 1 && pq.top() < K){
        int a = pq.top(); pq.pop();
        int b = pq.top(); pq.pop();
        int newScov = calcul(a,b);
        
        pq.push(newScov);
        answer++;
    }
    
    if(pq.top() < K) return -1;
    
    return answer;
}