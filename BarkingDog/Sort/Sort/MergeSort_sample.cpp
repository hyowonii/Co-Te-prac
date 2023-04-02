#include <iostream>
using namespace std;

int n = 10;
int arr[1000001] = {6, 2, 13, 7, 3, 4, 10, 9, 1, 5};
int tmp[1000001];

void merge(int st, int en){
  int mid = (st+en)/2;
  int p1=st, p2=mid;
  for(int i=st; i<en; i++){
    if(p1 == mid) tmp[i] = arr[p2++];
    else if(p2 == en) tmp[i] = arr[p1++];
    else if(arr[p1] <= arr[p2]) tmp[i] = arr[p1++];
    else tmp[i] = arr[p2++];
  }
  for(int i=st; i<en; i++) arr[i] = tmp[i];
}

void merge_sort(int st, int en){
  if(en-st == 1) return;  // 배열의 크기가 1일 때
  int mid = (st+en)/2;
  merge_sort(st, mid);
  merge_sort(mid, en);
  merge(st, en);
}

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);

  merge_sort(0, n);
  for(int i=0; i<n; i++) cout << arr[i] << " ";
}