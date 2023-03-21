/*
  백준 [수 찾기]
  https://www.acmicpc.net/problem/1920
  이분 탐색
*/

#include <iostream>
#include <algorithm>
using namespace std;

int n;
long long arr[100001];
int m;
long long nums[100001];

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for(int i=0; i<n; i++)
    cin >> arr[i];

  cin >> m;
  for(int j=0; j<m; j++)
    cin >> nums[j];

  sort(arr, arr+n);

  // 이분탐색
  for(int i=0; i<m; i++){
    long long num = nums[i];

//방법1. 직접 구현
    // int st=0, en=n-1;

    // while(st <= en){
    //   int mid = (st+en)/2;

    //   if(num == arr[mid]){
    //     cout << 1 << "\n";
    //     break;
    //   }
    //   else if(num < arr[mid]){
    //     en = mid - 1;
    //   }
    //   else{
    //     st = mid + 1;
    //   }
    // }

    // if(st > en){  // 존재X
    //   cout << 0 << "\n";
    // }

//방법2. STL의 binary_search
    cout << binary_search(arr, arr+n, num) << "\n";
  }

}