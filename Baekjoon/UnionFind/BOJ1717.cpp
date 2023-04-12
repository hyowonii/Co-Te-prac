/*
  
*/

#include <iostream>
using namespace std;

int n, m;
int parent[1000001];

int Find(int a){
  if(parent[a] == a) return a;
  return Find(parent[a]);
}

void Union(int a, int b){
  a = Find(a);
  b = Find(b);
  if(a != b){
    if(a > b){
      parent[b] = a;
    }
    else{
      parent[a] = b;
    }
  }
  
}

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  cin >> n >> m;

  for(int i=0; i<=n; i++){
    parent[i] = i;
  }

  while(m--){
    int c, a, b;
    cin >> c >> a >> b;
    if(c == 0){
      Union(a, b);
    }
    else{
      if(Find(a) == Find(b)) cout << "YES\n";
      else cout << "NO\n";
    }
  }
}