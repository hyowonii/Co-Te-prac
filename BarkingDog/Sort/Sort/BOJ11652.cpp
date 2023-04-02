/*
  백준 [카드]
  https://www.acmicpc.net/problem/11652
  
*/

#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;

int n;
long long arr[100001];
int cnt=0;
int mxcnt=0;
long long mxval = -pow(2,62) - 1;

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for(int i=0; i<n; i++) cin >> arr[i];

  sort(arr, arr+n);
  for(int i=0; i<n; i++){
    if(i == 0 || arr[i-1] == arr[i]) cnt++;
    else{
      if(cnt > mxcnt){
        mxcnt = cnt;
        mxval = arr[i-1];
      }
      cnt = 1;
    }
  }
  if(cnt > mxcnt) mxval = arr[n-1];
  cout << mxval;
}