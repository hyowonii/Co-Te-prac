/*
  백준 [트럭 주차]
  https://www.acmicpc.net/problem/2979
  구현
*/

#include <iostream>
using namespace std;

int a, b, c;
int car[101];
int result = 0;

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  cin >> a >> b >> c;
  for(int i=0; i<3; i++){
    int s, e;
    cin >> s >> e;
    for(int k=s; k<e; k++) car[k]++;
  }

  for(int i=1; i<=100; i++){
    if(car[i] == 1) result += a;
    else if(car[i] == 2) result += (2*b);
    else if(car[i] == 3) result += (3*c);
  }

  cout << result;
}