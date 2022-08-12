/*
  프로그래머스 [3진법 뒤집기]
  https://school.programmers.co.kr/learn/courses/30/lessons/68935?language=cpp
  수학
*/

#include <string>
#include <vector>
#include <cmath>

using namespace std;

int solution(int n) {
    int answer = 0;
    
    string str;
    while(n>0){
        str += to_string(n%3);
        n /= 3;
    }
    
    int exp=0;
    for(int i=str.size()-1; i>=0; i--) {
        answer += (str[i] - '0')*pow(3,exp);
        exp++;
    }
    
    return answer;
}