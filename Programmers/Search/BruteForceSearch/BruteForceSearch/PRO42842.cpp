/*
  프로그래머스 [카펫]
  https://school.programmers.co.kr/learn/courses/30/lessons/42842
  완전탐색
*/

#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    
    int sumR = (brown - 4) / 2;
    int mulR = yellow;
    
    for(int a=1; a<=sumR; a++) {
        int b = sumR - a;
        if(a * b == mulR) {
            answer.push_back(a>b ? a+2 : b+2);
            answer.push_back(a>b ? b+2 : a+2);
            break;
        }
    }
    
    
    
    return answer;
}