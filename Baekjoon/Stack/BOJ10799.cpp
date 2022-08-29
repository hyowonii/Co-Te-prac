/*
  백준 [쇠막대기]
  https://www.acmicpc.net/problem/10799
  스택
*/

#include <iostream>
#include <stack>
using namespace std;

stack<char> brackets;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int answer = 0;

  string str;
  cin >> str;

  for(int i=0; i<str.length(); i++) {
    if(str[i] == '(') 
      brackets.push('(');
    else {  // 닫는 괄호면
      brackets.pop();   // 하나 빼고

      if(str[i-1] == '(')   // 레이저
        answer += brackets.size();  // 스택 사이즈만큼 더하기
      else  // 쇠막대기의 끝
        answer += 1;  // 하나 더하기
    }
  }

  cout << answer;

}