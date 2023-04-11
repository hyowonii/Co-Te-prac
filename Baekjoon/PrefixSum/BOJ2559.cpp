/*
  백준 [수열]
  https://www.acmicpc.net/problem/2559
  투포인터
*/

#include <iostream>
using namespace std;

int n, k;
int temp[100001];
int result = 0;

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  cin >> n >> k;
  for(int i=0; i<n; i++) cin >> temp[i];

  int st = 0, en = st + k;
  int prev = 0;
  for(int i=st; i<en; i++) prev += temp[i];
  result = prev;

  while(en < n){
    int sum = prev - temp[st] + temp[en];
    result = max(sum, result);
    prev = sum;
    st++;
    en++;
  }

  cout << result;
}