/*
  백준 [ATM]
  https://www.acmicpc.net/problem/11399
  정렬, 그리디
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<int> P;

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  cin >> n;
  while(n--){
    int p;
    cin >> p;
    P.push_back(p);
  }

  sort(P.begin(), P.end());

  int sum = 0;
  int tmp = 0;
  for(int i=0; i<P.size(); i++){
    sum += (tmp + P[i]);
    tmp += P[i];
  }

  cout << sum;
}