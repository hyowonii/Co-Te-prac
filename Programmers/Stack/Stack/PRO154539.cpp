/*
  프로그래머스 [뒤에 있는 큰 수 찾기]
  https://school.programmers.co.kr/learn/courses/30/lessons/154539
  스택
*/

#include <string>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer(numbers.size());
    fill(answer.begin(), answer.end(), -1);
    
    stack<int> s;   // 인덱스 저장
    
    for(int idx=0; idx<numbers.size(); idx++){
        if(s.empty()) s.push(idx);
        else{
            while(!s.empty() && numbers[idx] > numbers[s.top()]){
                answer[s.top()] = numbers[idx];
                s.pop();
            }
            s.push(idx);
        }
    }
    
    return answer;
}