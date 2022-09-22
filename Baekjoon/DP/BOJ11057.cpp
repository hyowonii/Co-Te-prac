/*
  백준 [오르막 수]
  https://www.acmicpc.net/problem/11057
  dp
*/

#include <iostream>
#include <vector>
using namespace std;

#define MOD 10007

int v[1001][10];   // 일의 자리가 j인 i자리수의 개수

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int answer = 0;

  int N;
  cin >> N;

  for(int i=1; i<=N; i++) {
    for(int j=0; j<=9; j++) {
      
      if(i == 1) {
        v[i][j] = 1;
        continue;
      }
      if(j == 0) {
        v[i][j] = 1;
        continue;
      }

      v[i][j] = (v[i][j-1] + v[i-1][j]) % MOD;

    }
  }

  for(auto cnt : v[N]) answer += cnt % MOD;

  cout << answer % MOD;

}