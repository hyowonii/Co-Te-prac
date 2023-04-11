/*
  백준 [구간 합 구하기 4]
  https://www.acmicpc.net/problem/11659
  누적합
*/

#include <iostream>
using namespace std;

int n, m;
int num[100001];
int sum[100001] = {0};

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  cin >> n >> m;
  for(int i=1; i<=n; i++) {
    cin >> num[i];
    sum[i] = sum[i-1] + num[i];
  }
  
  while(m--){
    int i, j;
    cin >> i >> j;

    cout << sum[j] - sum[i-1] << "\n";
   
  }
}