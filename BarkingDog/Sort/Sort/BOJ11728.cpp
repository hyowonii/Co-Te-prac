/*
  백준 [배열 합치기]
  https://www.acmicpc.net/problem/11728
  정렬
*/

#include <iostream>
#include <vector>
using namespace std;

int n, m;
int A[1000002];
int B[1000002];
vector<int> C;

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m;
  for(int i=0; i<n; i++) cin >> A[i];
  for(int i=0; i<m; i++) cin >> B[i];

  int p1=0, p2=0;
  while(true){
    if(p1 == n){
      for(; p2 < m; p2++) C.push_back(B[p2]);
      break;
    }
    if(p2 == m){
      for(; p1 < n; p1++) C.push_back(A[p1]);
      break;
    }

    if(A[p1] < B[p2]) {
      C.push_back(A[p1]);
      p1++;
    }
    else {
      C.push_back(B[p2]);
      p2++;
    }
  }

  for(int i=0; i<C.size(); i++) cout << C[i] << " ";

}