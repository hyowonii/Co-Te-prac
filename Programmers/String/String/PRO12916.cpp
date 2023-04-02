/*
  프로그래머스 [문자열 내 p와 y의 개수]
  https://school.programmers.co.kr/learn/courses/30/lessons/12916
  문자열
*/

#include <string>
#include <iostream>
using namespace std;

bool solution(string s)
{
    bool answer = true;
    
    int cntp=0, cnty=0;
    for(auto c : s){
        if(c == 'P' || c == 'p') cntp++;
        if(c == 'Y' || c == 'y') cnty++;
    }
    if(cntp != cnty) answer = false;
    
    return answer;
}