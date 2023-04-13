/*
  백준 [수학숙제]
  https://www.acmicpc.net/problem/2870
  문자열, 파싱
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<pair<int, string>> m; // 자릿수, 숫자

void Insert(string tmp){
  string s = tmp;
  for(int i=0; i<tmp.size()-1; i++){
    if(tmp[i] == '0') s.erase(0, 1);
    else break;
  }
  tmp = s;
  m.push_back({tmp.size(), tmp});
}

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  cin >> n;
  while(n--){
    string str;
    cin >> str;

    string tmp = "";
    for(auto c : str){
      if(c - '0' >= 0 && c - '0' <= 9){ // 숫자면
        tmp += c;
      }
      else{ // 문자면
        if(tmp != ""){  // 이전에 저장한 숫자
          Insert(tmp);
          tmp = "";
        }
      }
    }
    if(tmp != "") Insert(tmp);
  }

  sort(m.begin(), m.end());

  for(auto s : m) cout << s.second << "\n";
}