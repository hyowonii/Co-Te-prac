/*
  프로그래머스 [문자 숫자열과 영단어]
  https://school.programmers.co.kr/learn/courses/30/lessons/81301
  문자열
*/

#include <string>
#include <vector>
#include <map>
#include <regex>

using namespace std;

map<string, int> m;

int solution(string s) {
    /*
    string answer = "";
    
    m["zero"] = 0;
    m["one"] = 1;
    m["two"] = 2;
    m["three"] = 3;
    m["four"] = 4;
    m["five"] = 5;
    m["six"] = 6;
    m["seven"] = 7;
    m["eight"] = 8;
    m["nine"] = 9;
    
    string tmp="";
    for(char c : s){
        if(isdigit(c)) answer += c;
        else tmp += c;
        
        if(m.find(tmp) != m.end()){
            answer += to_string(m[tmp]);
            tmp = "";
        }
    }
        
    return stoi(answer);
    */
    
    int answer = 0;
    
    s = regex_replace(s, regex("zero"), "0");
    s = regex_replace(s, regex("one"), "1");
    s = regex_replace(s, regex("two"), "2");
    s = regex_replace(s, regex("three"), "3");
    s = regex_replace(s, regex("four"), "4");
    s = regex_replace(s, regex("five"), "5");
    s = regex_replace(s, regex("six"), "6");
    s = regex_replace(s, regex("seven"), "7");
    s = regex_replace(s, regex("eight"), "8");
    s = regex_replace(s, regex("nine"), "9");
    
    answer = stoi(s);
    return answer;
}