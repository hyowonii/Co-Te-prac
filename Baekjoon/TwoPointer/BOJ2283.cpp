/*
  백준 [구간 자르기]
  https://www.acmicpc.net/problem/2283
  투포인터
*/

#include <iostream>
using namespace std;

int n, k;
int cnt[1000001] = {0,};
int A=0, B=0;

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> k;
  while(n--){
    int a, b;
    cin >> a >> b;
    for(int i=a+1; i<=b; i++) cnt[i]++;
  }

  int st = 0, en = 0;
  int sum = 0;
  while(true){
    if(en == 1000001) break;

    if(sum > k) sum -= cnt[++st];
    else if(sum < k) sum += cnt[++en];
    else {
      A = st;
      B = en;
      break;
    }
  }
  

  cout << A << " " << B;
}