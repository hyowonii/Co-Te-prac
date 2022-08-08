/*
  프로그래머스 [조이스틱]
  https://school.programmers.co.kr/learn/courses/30/lessons/42860
  greedy
*/

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(string name) {
    int answer = 0;
    
    int shift = name.length() - 1;  // 좌 또는 우 한 쪽 방향으로만 움직였을 때
    
    for(int i=0; i<name.length(); i++){
        if(name[i] == 'A') {
            int target = i;
            // A로만 이루어진 문자열 찾기
            while(name[target] == 'A' && target < name.length()) 
                target += 1;
            
            int left = i == 0 ? 0 : i - 1;
            int right = name.length() - target;
            shift = min(shift, left + right + min(left, right));
        }
    }
    
    answer += shift;
    for(auto c : name) {
        answer += min(c - 'A', 'Z' + 1 - c);
    }
    
    return answer;
}