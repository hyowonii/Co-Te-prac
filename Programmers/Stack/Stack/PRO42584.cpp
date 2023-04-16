/*
  프로그래머스 [주식가격]
  https://school.programmers.co.kr/learn/courses/30/lessons/42584
  스택
*/

#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer(prices.size());
    
/* 스택 풀이    
    stack<int> s;   // 인덱스 저장
    for(int idx=0; idx<prices.size(); idx++){
        if(s.empty()) s.push(idx);
        else{
            while(!s.empty() && prices[idx] < prices[s.top()]){
                answer[s.top()] = idx - s.top();
                s.pop();
            }
            s.push(idx);
        }
    }
    while(!s.empty()){
        answer[s.top()] = prices.size() - 1 - s.top();
        s.pop();
    }
*/
    
/* 이중포문 - 아마 tl? 근데 이 문제에서는 안터짐
    for(int i=0; i<prices.size(); i++){
        for(int j=i+1; j<prices.size(); j++){
            if(prices[i] > prices[j]) {
                answer[i] = j - i;
                break;
            }
        }
        if(answer[i] == 0) answer[i] = prices.size() - 1 - i;
    }
*/
    
    return answer;
}
