/*
  프로그래머스 [문자열 나누기]
  https://school.programmers.co.kr/learn/courses/30/lessons/140108
  문자열
*/

#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 0;
    
    int num = s.length();
    int i, j;
    for(int i=0; i<num; i++){
        int cntx = 0;
        int cntnx = 0;
        int x = s[i];
        
        for(j=i; j<num; j++){
            if(s[j] == x) cntx++;
            else cntnx++;
            if(cntx == cntnx) break;
        }
        i=j;
        answer++;
    }
    
    return answer;
}