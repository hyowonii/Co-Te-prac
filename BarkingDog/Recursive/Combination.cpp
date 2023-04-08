// Combination 직접 구현

#include <iostream>
using namespace std;
#define n 4 // n 개 중에서
#define r 3 // r 개 선택

int cArr[r] = {0,};

// 프린트
void printArray(int arr[]){
  for(int i=0; i<r; i++)
    cout << arr[i] << " ";
  cout << "\n";
}

// 조합 (순서x, 중복x)
void combination(int depth, int nxt){
  if(depth == r){
    printArray(cArr);
    return;
  }

  for(int num=nxt; num<=n; num++){
    cArr[depth] = num;
    combination(depth+1, num+1);
  }
}

// 조합 (순서x, 중복o)
void duplicateCombination(int depth, int nxt){
  if(depth == r){
    printArray(cArr);
    return;
  }

  for(int num=nxt; num<=n; num++){
    cArr[depth] = num;
    duplicateCombination(depth+1, num);
  }
}


int main(void){
  cout << "조합 (순서x, 중복x)\n";
  combination(0,1);

  fill(cArr, cArr+n, 0);

  cout << "조합 (순서x, 중복o)\n";
  duplicateCombination(0,1);

  return 0;
}