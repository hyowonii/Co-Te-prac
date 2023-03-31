/*
  백준 [군형잡힌 세상]
  https://www.acmicpc.net/problem/4949
  stack
*/

#include <iostream>
#include <stack>
using namespace std;

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);

  while(true){
    string str;
    getline(cin, str);
    if(str[0] == '.') break;

    stack<char> s;
    string result = "yes";
    
    for(auto c : str){
      if(c == '(') s.push('(');
      if(c == '[') s.push('[');
      if(c == ')'){
        if(!s.empty() && s.top() == '(') s.pop();
        else {
          result = "no";
          break;
        }
      }
      if(c == ']'){
        if(!s.empty() && s.top() == '[') s.pop();
        else {
          result = "no";
          break;
        }
      }
    }
    if(!s.empty()) result = "no";
    cout << result << "\n";
  }
}