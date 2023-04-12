/*
  백준 [가장 긴 증가하는 부분 수열]
  https://www.acmicpc.net/problem/11053
  dp
*/

#include <iostream>
#include <cmath>
using namespace std;

int n;
int a[1001];
int dp[1001];
int maxLen = 0;

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  cin >> n;
  a[0] = 1001;
  for(int i=0; i<n; i++) {
    cin >> a[i];
    dp[i] = 0;

    for(int j=0; j<=i; j++){
      if(a[i] > a[j] && dp[i] < dp[j]){
        dp[i] = dp[j];
      }
    }
    dp[i]++;  // 자기자신
    maxLen = max(maxLen, dp[i]);
  }

  cout << maxLen;
}