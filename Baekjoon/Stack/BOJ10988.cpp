/*
  백준 [팰린드롬인지 확인하기]
  https://www.acmicpc.net/problem/10988
  스택, 문자열, 투포인터
*/

#include <iostream>
#include <stack>
using namespace std;

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  string str;
  cin >> str;

/* 스택 풀이

  stack<char> s;

  for(int i=1; i<=str.size(); i++){
    if(str.size() % 2 != 0 && i == str.size() / 2 + 1) continue;
    if(i <= str.size() / 2) s.push(str[i-1]);
    else if(i > str.size() / 2){
      if(s.top() == str[i-1]) s.pop();
    }
  }

  if(s.empty()) cout << 1;
  else cout << 0;

*/

// 투포인터
  // int s=0, e=str.size()-1;
  // while(s <= e){
  //   if(str[s] == str[e]){
  //     s++;
  //     e--;
  //   }
  //   else break;
  // }

  // if(s > e) cout << 1;
  // else cout << 0;

// 문자열
  int len = str.size();
  for(int i=0; i<len/2; i++){
    if(str[i]!=str[str.length()-1-i]){
      cout<<"0"<<"\n";
      return 0;
    }
  }
  cout<<"1"<<"\n";

}