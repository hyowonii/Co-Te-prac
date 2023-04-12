/*
  백준 [알고리즘 수업 - 피보나치 수 1]
  https://www.acmicpc.net/problem/24416
  dp
*/

#include <iostream>
using namespace std;

int N;
int f[41];
int cnt1=0, cnt2=0;

int fib(int n) {
  if (n == 1 || n == 2){
    cnt1++;
    return 1;   // 코드 1
  }
  else 
    return (fib(n - 1) + fib(n - 2));
}

int fibonacci(int n) {
    f[1] = f[2] = 1;
    for(int i=3; i<=n; i++){
      f[i] = f[i-1] + f[i-2];   // 코드 2
      cnt2++;
    }
    return f[n];
}

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  cin >> N;

  fib(N);
  fibonacci(N);

  cout << cnt1 << " " << cnt2;
}