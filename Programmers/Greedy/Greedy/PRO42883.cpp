/*
    ���α׷��ӽ� [ū �� �����]
    https://programmers.co.kr/learn/courses/30/lessons/42883?language=cpp
    greedy
*/

#include <string>
#include <vector>

using namespace std;

string solution(string number, int k) {
    string answer = "";

    int num = number.size() - k;
    int idx = number.size() - num;  // 시작 인덱스
    int fin = 0;    // 포문 종료
    while(fin < number.size() && answer.size() < num){
        int des = idx;
        for(int i=idx; i>=fin; --i){
            if(number[i] >= number[des]) des = i;
        }
        answer += number[des];
        fin = des+1;
        idx++;
    }

    return answer;
}