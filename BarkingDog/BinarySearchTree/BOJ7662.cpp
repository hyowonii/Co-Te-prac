/*
  백준 [이중 우선순위 큐]
  https://www.acmicpc.net/problem/7662
  이분탐색트리
*/

#include <iostream>
#include <set>
using namespace std;

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t;
  cin >> t;

  while(t--){
    int k;
    cin >> k;

    multiset<int> ms;
    while(k--){
      char c;
      int n;
      cin >> c >> n;

      if(c == 'I') ms.insert(n);
      else if(c == 'D') {
        if(ms.empty()) continue;  // 멀티셋 비어있을 땐 삭제 동작 안됨
        if(n == 1){
          ms.erase(prev(ms.end()));
        } else if(n == -1){
          ms.erase(ms.begin());
        }
      }
    }

    if(ms.empty()) cout << "EMPTY\n";
    else {
      cout << *prev(ms.end()) << " " << *ms.begin() << "\n";
    }
  }
}