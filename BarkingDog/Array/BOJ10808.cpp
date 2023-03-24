/*
  백준 [알파벳 개수]
  https://www.acmicpc.net/problem/10808
  배열
*/

#include <iostream>
using namespace std;

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);

  string S;
  cin >> S;

  int alphabet[26] = {0};

  for(char c : S){
    alphabet[c-'a']++;
  }

  for(int i : alphabet){
    cout << i << " ";
  }
}