/*
	프로그래머스 [짝지어 제거하기]
	https://school.programmers.co.kr/learn/courses/30/lessons/12973
	stack
*/

#include <iostream>
#include<string>
#include <stack>
using namespace std;

int solution(string s)
{
    int answer = 0;

    stack<char> c;
    for (int i = 0; i < s.length(); i++) {
        if (c.empty() || c.top() != s[i]) c.push(s[i]);
        else if (c.top() == s[i]) c.pop();
    }

    if (c.empty()) answer = 1;

    return answer;
}