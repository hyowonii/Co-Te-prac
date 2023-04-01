/*
  백준 [보석 도둑]
  https://www.acmicpc.net/problem/1202
  
*/

#include <iostream>
#include <set>
#include <algorithm>
using namespace std;
#define X first
#define Y second

long long answer = 0;

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, k;
  cin >> n >> k;
  pair<int, int> jewel[300003]; // 가격, 무게
  for(int i=0; i<n; i++){
    cin >> jewel[i].Y >> jewel[i].X;
  }
  sort(jewel, jewel+n);
  
  multiset<int> bag;
  for(int i=0; i<k; i++) {
    int c;
    cin >> c;
    bag.insert(c);
  }

  for(int i=n-1; i>=0; i--){  // 가격 높은 순부터
    int m, v;
    tie(v, m) = jewel[i];
    auto it = bag.lower_bound(m);
    if(it == bag.end()) continue; // **** lower_bound 없는 경우 ****
    answer += v;
    bag.erase(it);
  }

  cout << answer;
}