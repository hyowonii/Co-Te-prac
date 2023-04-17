/*
  백준 [농구 경기]
  https://www.acmicpc.net/problem/1159
  문자열
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int alph[26] = {0};
string result = "";

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  cin >> n;
  while(n--) {
    string str;
    cin >> str;
    alph[str[0] - 'a']++;
  }

  for(int i=0; i<26; i++){
    if(alph[i] >= 5) result += ('a'+i);
  }

  if(result == "") cout << "PREDAJA";
  else cout << result;

}