/*
  백준 [좋은 단어]
  https://www.acmicpc.net/problem/3986
  stack
*/

#include <iostream>
#include <stack>
using namespace std;

int n;
int result = 0;

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  cin >> n;
  while(n--){
    stack<char> s;

    string str;
    cin >> str;

    for(auto c : str){
      if(s.empty()) s.push(c);
      else{
        if(c == s.top()) s.pop();
        else s.push(c);
      }
    }
    
    if(s.empty()) result++;
  }

  cout << result;
}