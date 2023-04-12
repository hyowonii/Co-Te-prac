/*
  정의 : 서로소 부분 집합들로 나누어진 원소들에 대한 정보를 저장하고 조작하는 자료구조
        한 노드의 부모를 찾거나 두 노드가 한 집합이 되도록 합치거나
        트리 구조 연상하기
  구현
  1) find(x) : x의 부모를 찾는 함수
      - 경로 압축
      - 상수 복잡도를 가짐
  2) union(a,b) : a와 b를 연결하는 함수(한 쪽으로 연결시켜줌)
      - 작은 쪽 or 큰 쪽 중 한 쪽으로 연결시키는 것이 헷갈리지 않음
      - O(lgn)
*/

int n;
int parent[100000];

// 자기자신
void init(){
  for(int i = 1; i <= n; i++) 
    parent[i] = i;
}

int Find(int x){
  if(parent[x] == x) return x;
  return parent[x] = Find(parent[x]);
}

void Union(int x, int y){
  x = Find(x);
  y = Find(y);
  if(x != y){
    if(x < y)
      parent[y] = x;
    else 
      parent[x] = y;
  }
}