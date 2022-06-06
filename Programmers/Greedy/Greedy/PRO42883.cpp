/*
    프로그래머스 [큰 수 만들기]
    https://programmers.co.kr/learn/courses/30/lessons/42883?language=cpp
    greedy
*/

#include <string>
#include <vector>

using namespace std;

string solution(string number, int k) {
    string answer = "";

    int n = number.length() - k;    // 만들어야 하는 자리수

    for (int i = 0, idx = -1; i < n; i++) {
        char max = '0';
        for (int j = idx + 1; j <= k + i; j++) {  // k+j까지가 지울 수 있는 최소 자리
            if (max < number[j]) {
                max = number[j];
                idx = j;
            }
        }
        answer += max;
    }

    return answer;
}