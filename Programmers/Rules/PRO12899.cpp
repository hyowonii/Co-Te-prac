/*
  프로그래머스 [124 나라의 숫자]
  https://school.programmers.co.kr/learn/courses/30/lessons/12899
  규칙 찾기
*/

#include <string>
#include <vector>

using namespace std;

string solution(int n) {
    string answer = "";
    
    int r;
    int q = n;
    while(q > 0) {
        r = q % 3;
        q = q / 3; 
        
        if(r == 0) {
            answer = "4" + answer;
            q--;
        }
        else if(r == 1) answer = "1" + answer;
        else if(r == 2) answer = "2" + answer;
        
    }
    
    
    
    return answer;
}