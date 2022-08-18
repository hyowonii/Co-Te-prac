/*
  프로그래머스 [올바른 괄호]
  https://school.programmers.co.kr/learn/courses/30/lessons/12909
  stack
*/

#include<string>
#include <iostream>
#include <stack>

using namespace std;

bool solution(string s)
{
    bool answer = true;
    
    stack<char> st;
    
    for(auto c : s) {
        if(c == '(') {
            st.push('(');
        }
        else if(c == ')') {
            if(st.empty()) return false;
            st.pop();
        }
    }
    
    if(!st.empty()) answer = false;

    return answer;
}