/*
  백준 [ROT13]
  https://www.acmicpc.net/problem/11655
  문자열
*/

#include <iostream>
using namespace std;

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  string str;
  getline(cin, str);

  string newstr;
  for(auto c : str){
    if(c == ' ') newstr += " ";
    else if(c - '0' >= 0 && c - '0' <= 9) newstr += c;
    else{
      if(c - 'A' >= 0 && c - 'A' < 26){ // 대문자
        char newc = (c - 'A' + 13) % 26 + 'A';
        newstr += newc;
      }
      else{ // 소문자
        char newc = (c - 'a' + 13) % 26 + 'a';
        newstr += newc;
      }
    }
  }

  cout << newstr;
}