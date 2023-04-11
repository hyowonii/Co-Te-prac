/*
  백준 [인간-컴퓨터 상호작용]
  https://www.acmicpc.net/problem/16139
  누적합
*/

#include <iostream>
using namespace std;

string str;
int t;
int alph[200001][26] = {0}; // 인덱스까지 알파벳 나온 수

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  cin >> str >> t;

  for(int i=1; i<=str.size(); i++){
    char c = str[i-1];
    for(int j=0; j<26; j++) alph[i][j] = alph[i-1][j];
    alph[i][c-'a']++;
  }

  // cout << "\n";
  // for(int i=0; i<26; i++) cout << alph[str.size()][i] << " ";
  // cout << "\n";

  while(t--){
    char c;
    int s, e;
    cin >> c >> s >> e;

    cout << alph[e+1][c-'a'] - alph[s][c-'a'] << "\n";
  }
}