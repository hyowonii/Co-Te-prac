/*
  프로그래머스 [문자열 안에 문자열]
  https://school.programmers.co.kr/learn/courses/30/lessons/120908
  문자열
*/

#include <string>
#include <vector>

using namespace std;

int solution(string str1, string str2) {
    int answer = 0;
    
    int p1=0, p2=0;
    while(p1 != str1.length() && p2 != str2.length()){
        char c1 = str1[p1];
        char c2 = str2[p2];
        
        if(c1 == c2) {
            p1++;
            p2++;
        }
        else {
            p1++;
            p2 = 0;
        }
    }
    
    if(p2 == str2.length()) return 1;
    else return 2;
    
}