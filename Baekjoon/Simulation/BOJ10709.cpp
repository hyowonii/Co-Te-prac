/*
  백준 [기상캐스터]
  https://www.acmicpc.net/problem/10709
  구현
*/

#include <iostream>
using namespace std;

int h, w;

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  cin >> h >> w;
  
  for(int i=0; i<h; i++){
    int firstC = -1;
    for(int j=0; j<w; j++){
      char c;
      cin >> c;
      if(c == 'c'){
        cout << 0 << " ";
        firstC = j;
      }
      else{
        if(firstC != -1){
          cout << j - firstC << " ";
        }
        else{
          cout << -1 << " ";
        }
      }
    }
    cout << "\n";
  }
}