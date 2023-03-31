/*
  프로그래머스 [문자열 다루기 기본]
  https://school.programmers.co.kr/learn/courses/30/lessons/12918
  문자열
*/

#include <string>
#include <vector>
#include <typeinfo>
#include <iostream>

using namespace std;

bool solution(string s) {
    bool answer = true;
    
    if(s.size() != 4 && s.size() != 6) return false;
    for(auto c : s){
        if(c - '0' < 0 || c - '0' > 9) return false;
    }
    
    return answer;
}