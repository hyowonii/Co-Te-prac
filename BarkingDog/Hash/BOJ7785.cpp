/*
  백준 [회사에 있는 사람]
  https://www.acmicpc.net/problem/7785
  해사
*/

#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

unordered_set<string> s;

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;

  while(n--) {
    string name, log;
    cin >> name >> log;

    if(log == "enter") s.insert(name);
    else s.erase(name);   // log == "leave"
  }

  vector<string> ans(s.begin(), s.end());
  sort(ans.begin(), ans.end(), greater<string>());
  for(auto x : ans) cout << x << "\n";
}