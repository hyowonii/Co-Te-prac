/*
  백준 [과자 나눠주기]
  https://www.acmicpc.net/problem/16401
  이분탐색
*/

#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
#define ll long long

int m, n;
int s[1000001];
ll maxLen = 0;

bool check(ll len){
  int cnt = 0;
  for(int i=0; i<n; i++){
    cnt += (s[i] / len);
  }
  if(cnt >= m) return true;
  else return false;
}

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  cin >> m >> n;
  for(int i=0; i<n; i++) cin >> s[i];

  sort(s, s+n);

  ll st = 1, en = 0x7ffffffff; // 막대과자 길이 있을 범위
  while(st < en){
    ll mid = (st + en) / 2;
    if(check(mid)){
      maxLen = max(maxLen, mid);
      st = mid + 1;
    }
    else en = mid;
  }

  cout << maxLen;
}