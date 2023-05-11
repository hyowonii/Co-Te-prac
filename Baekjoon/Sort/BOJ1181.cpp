/*
  백준 [단어 정렬]
  https://www.acmicpc.net/problem/1181
  정렬(compare 함수 써서)
*/

#include <iostream>
#include <set>
using namespace std;

int n;
set<string> s[20001];
int mxLen = 0;

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  cin >> n;
  while(n--){
    string str;
    cin >> str;
    s[str.size()].insert(str);
    if(str.size() > mxLen) mxLen = str.size();
  }

  for(int i=1; i<=mxLen; i++){
    if(s[i].empty()) continue;
    else{
      for(auto c : s[i])
        cout << c << "\n";
    }
  }

}