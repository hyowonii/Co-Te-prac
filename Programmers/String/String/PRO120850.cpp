/*
  프로그래머스 [문자열 정렬하기 (1)]
  https://school.programmers.co.kr/learn/courses/30/lessons/120850
  문자열
*/

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(string my_string) {
    vector<int> answer;
    
    for(auto c :my_string){
        if(c - '0' >= 0 && c - '0' <= 9){
            answer.push_back(c - '0');
        }
    }
    sort(answer.begin(), answer.end());
    return answer;
}