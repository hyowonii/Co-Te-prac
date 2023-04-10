/*
  백준 [균형잡힌 세상]
  https://www.acmicpc.net/problem/4949
  stack
*/

#include <iostream>
#include <stack>
using namespace std;

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);

  while(1){
    string str;
    getline(cin, str);
    if(str[0] == '.') break;

    stack<char> S;
    string result = "yes";

    for(auto c : str){
      if(c == '('){
        S.push('(');
      }
      if(c == '['){
        S.push('[');
      }
      if(c == ')'){
        if(!S.empty() && S.top() == '('){
          S.pop();
        }
        else{
          result = "no";
          break;
        }
      }
      if(c == ']'){
        if(!S.empty() && S.top() == '['){
          S.pop();
        }
        else{
          result = "no";
          break;
        }
      }
    }
    if(!S.empty()) result = "no";
    cout << result << "\n";
  }
}