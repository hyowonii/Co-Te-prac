/*
  백준 [쇠막대기]
  https://www.acmicpc.net/problem/10799
  stack
*/

#include <iostream>
#include <stack>
using namespace std;

stack<char> s;
int result = 0;

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  string str;
  cin >> str;

  for(int i=0; i<str.size(); i++){
    if(str[i] == '('){
      s.push('(');
    }
    else{
      s.pop();
      if(str[i-1] == '('){ // 레이저
        result += s.size();
      }
      else{
        result += 1;
      }
    }
  }

  cout << result;
}