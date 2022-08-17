/*
  프로그래머스 [최댓값과 최솟값]
  https://school.programmers.co.kr/learn/courses/30/lessons/12939
  문자열
*/

#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

string solution(string s) {
    string answer = "";
    
    stringstream ss(s);
    ss.str(s);
    vector<int> list;
    string word;
    while (ss >> word) {
        list.push_back(stoi(word));   // 공백으로 구분한 문자들을 배열에 저장
    }
    
    sort(list.begin(), list.end());
    answer += to_string(list[0]);
    answer += " ";
    answer += to_string(list[list.size() - 1]);
    
    return answer;
}