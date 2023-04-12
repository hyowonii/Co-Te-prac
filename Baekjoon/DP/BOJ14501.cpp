/*
  
*/

#include <iostream>
#include <cmath>
using namespace std;

int n;
pair<int,int> v[16];
int dp[16] = {0};
int maxGain = 0;

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  cin >> n;
  for(int i=1; i<=n; i++){
    int t, p;
    cin >> t >> p;
    v[i] = {t,p};
    
    for(int j=1; j<=i; j++){
      if(i - j >= v[j].first && dp[j] > dp[i]){
        dp[i] = dp[j];
      }
    }
    if(i + v[i].first - 1 <= n) {
      dp[i] += v[i].second;
      maxGain = max(dp[i], maxGain);  
    }
  }

  cout << maxGain;
}