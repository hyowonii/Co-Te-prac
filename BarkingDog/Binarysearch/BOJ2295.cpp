/*
  백준 [세 수의 합]
  https://www.acmicpc.net/problem/2295
  이분탐색
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define ll long long

int n;
ll a[1002];
vector<ll> twos;


int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for(int i=0; i<n; i++)
    cin >> a[i];
  sort(a, a+n);
  for(int i=0; i<n; i++)
    for(int j=i; j<n; j++)
      twos.push_back(a[i]+a[j]);
  sort(twos.begin(), twos.end());
  for(int i=n-1; i>0; i--){
    for(int j=0; j<i; j++){
      if(binary_search(twos.begin(), twos.end(), a[i]-a[j])){
        cout << a[i];
        return 0;
      }
    }
  }


}