/*
  백준 [트리 순회]
  https://www.acmicpc.net/problem/1991
  순회
*/

#include <iostream>
using namespace std;

int n;  // 이진 트리 노드의 개수
int lc[30];
int rc[30];

void preorder(int cur){
  cout << char(cur + 'A' - 1);
  if(lc[cur] != 0) preorder(lc[cur]);
  if(rc[cur] != 0) preorder(rc[cur]);
}

void inorder(int cur){
  if(lc[cur] != 0) inorder(lc[cur]);
  cout << char(cur + 'A' - 1);
  if(rc[cur] != 0) inorder(rc[cur]);
}

void postorder(int cur){
  if(lc[cur] != 0) postorder(lc[cur]);
  if(rc[cur] != 0) postorder(rc[cur]);
  cout << char(cur + 'A' - 1);
}

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for(int i=1; i<=n; i++){
    char c,l,r;
    cin >> c >> l >> r;
    if(l != '.') lc[c-'A'+1] = l-'A'+1;
    if(r != '.') rc[c-'A'+1] = r-'A'+1; 
  }

  // 전위순회
  preorder(1);
  cout << "\n";

  // 중위순회
  inorder(1);
  cout << "\n";

  // 후위순회
  postorder(1);

}