/*
  백준 [분수찾기]
  https://www.acmicpc.net/problem/1193
  구현
*/

#include <iostream>
using namespace std;

int num;

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  cin >> num;

  int i = 1;  // i번째 대각선
  while(num > i){
    num -= i;
    i++;
  }

  if(i % 2 == 1){ // 홀수번째 대각선
    cout << i - num + 1 << "/" << num;
  }
  else{
    cout << num << "/" << i - num + 1;
  }
}