/*
  백준 [키로거]
  https://www.acmicpc.net/problem/5397
  stack
*/

#include <iostream>
#include <stack>
using namespace std;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  stack<char> s1;
  stack<char> s2;

  int t;
  cin >> t;

  while(t--) {

    string str;
    cin >> str;

    for(auto c : str) {
      if(c == '<') {
        if(s1.empty()) continue;

        char temp = s1.top(); s1.pop();
        s2.push(temp);

      } else if(c == '>') {
        if(s2.empty()) continue;

        char temp = s2.top(); s2.pop();
        s1.push(temp);
        
      } else if(c == '-') {
        if(s1.empty()) continue;
        s1.pop();

      } else {
        s1.push(c);

      }
    }

    while(!s1.empty()) {
      char temp = s1.top(); s1.pop();
      s2.push(temp);
    }

    while(!s2.empty()) {
      cout << s2.top();
      s2.pop();
    }

    cout << "\n";

  }

}