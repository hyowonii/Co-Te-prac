/*
  백준 [수 정렬하기5]
  https://www.acmicpc.net/problem/15688
  정렬
*/

#include <iostream>
#include <algorithm>
using namespace std;

int n;
int freq[2000001];

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for(int i=0; i<n; i++) {
    int num;
    cin >> num;
    freq[num + 1000000]++;  // +1000000
  }
  int i=1;
  for(int i=0; i<= 2000000; i++){
    while(freq[i]--) cout << i-1000000 << "\n"; // -1000000
  }
}