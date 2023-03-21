/*
  백준 [숫자 카드2]
  https://www.acmicpc.net/problem/10816
  이분 탐색
*/

#include <iostream>
#include <algorithm>
using namespace std;

int n;
long long arr[500001];
int m;


int lower_idx(long long num){
  int st = 0, en = n;
  int mid;
  while(st < en){
    mid = (st+en)/2;
    if(num <= arr[mid]){
      en = mid;
    }
    else{
      st = mid + 1;
    }
  }
  return st;
}

int upper_idx(long long num){
  int st = 0, en = n;
  int mid;
  while(st < en){
    mid = (st+en)/2;
    if(num < arr[mid]){
      en = mid;
    }
    else{
      st = mid + 1;
    }
  }
  return st;
}

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for(int i=0; i<n; i++)
    cin >> arr[i];

  sort(arr, arr+n);

  cin >> m;

  while(m--){
    long long num;
    cin >> num;

//방법1. 직접 구현
    // int lowerIdx = lower_idx(num);
    // int upperIdx = upper_idx(num);
    // int cnt = upperIdx - lowerIdx;
    // if(cnt <= 0) cout << 0 << " ";
    // else cout << cnt << " ";

//방법2. STL
    cout << upper_bound(arr, arr+n, num) - lower_bound(arr, arr+n, num) << " ";
  }
}