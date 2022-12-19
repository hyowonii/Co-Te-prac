/*
  프로그래머스 [두 큐 합 같게 만들기]
  https://school.programmers.co.kr/learn/courses/30/lessons/118667
  투포인터
*/

#include <string>
#include <vector>

using namespace std;

int solution(vector<int> queue1, vector<int> queue2) {
    int answer = 0;
    
    long long sum = 0;
    long long sum1=0, sum2=0; // 큐1, 큐2 각각의 원소 합
    for(int i=0; i<queue1.size(); i++) {
        sum1 += queue1[i];
        sum2 += queue2[i];
    }
    sum += (sum1 + sum2);
    
    if(sum % 2 != 0) {
        answer = -1;
    }
    else {
        vector<int>::iterator p1, p2;   // 큐의 포인터를 상수로 두면 안됨(하나의 포인터가 상대 큐로 넘어갈 수 있도록, 상수로 두면 상대 큐로 못넘어감)
        p1 = queue1.begin();    
        p2 = queue2.begin();
        
        while(true) {
            
            if(sum1 == sum2) break; // 두 큐의 합이 같아지면 종료
            
            if(p1 == queue2.end() || p2 == queue1.end()) {  // 탐색완료
                answer = -1;
                break;
            }
            
            if(sum1 > sum2) {
                sum1 -= *p1;
                sum2 += *p1;
                
                p1++;
                if(p1 == queue1.end()) p1 = queue2.begin();   // 상대큐로 넘어가서 계속 진행
            }
            else {
                sum2 -= *p2;
                sum1 += *p2;
                
                p2++;
                if(p2 == queue2.end()) p2 = queue1.begin();   // 상대큐로 넘어가서 계속 진행
            } 
            
            answer++;
        }
    }
    
    
    return answer;
}