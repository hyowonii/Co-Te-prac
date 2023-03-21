/*
  백준 [좌표 압축]
  https://www.acmicpc.net/problem/18870
  이분 탐색
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int x[1000005];
vector<int> tmp, uni;

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;

//방법1. 일반적 중복제거
  // for(int i=0; i<n; i++){
  //   cin >> x[i];
  //   tmp.push_back(x[i]);
  // }
  // sort(tmp.begin(), tmp.end());
  // for(int i=0; i<n; i++){
  //   if(i == 0 || tmp[i-1] != tmp[i])
  //     uni.push_back(tmp[i]);
  // }

//방법2. STL을 활용한 중복제거
  for(int i=0; i<n; i++){
    cin >> x[i];
    uni.push_back(x[i]);
  }
  sort(uni.begin(), uni.end());
  uni.erase(unique(uni.begin(), uni.end()), uni.end());

  for(int i=0; i<n; i++)
    cout << lower_bound(uni.begin(), uni.end(), x[i]) - uni.begin() << " "; // iterator 활용
}