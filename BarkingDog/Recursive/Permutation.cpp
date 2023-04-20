// Permutation 직접 구현

#include <iostream>
using namespace std;
#define n 4 // n 개 중에서
#define r 3 // r 개 선택

int pArr[r] = {0,};
bool check[n+1] = {false,};

// 프린트
void printArray(int arr[]){
  for(int i=0; i<r; i++)
    cout << arr[i] << " ";
  cout << "\n";
}

// 순열 (순서o, 중복x)
void permutation(int depth){
  if(depth == r){
    printArray(pArr);
    return;
  }

  for(int num=1; num<=n; num++){  // 1부터 4까지
    if(!check[num]){
      pArr[depth] = num;
      check[num] = true;
      permutation(depth + 1);
      check[num] = false;
    }
  }
}

// 순열 (순서o, 중복o)
void duplicatePermutation(int depth){
  if(depth == r){
    printArray(pArr);
    return;
  }

  for(int num=1; num<=n; num++){
    pArr[depth] = num;
    duplicatePermutation(depth + 1);
  }
}

int main(void){
  cout << "순열 (순서o, 중복x)\n";
  permutation(0);

  fill(pArr, pArr+r, 0);
  fill(check, check+n, false);

  cout << "순열 (순서o, 중복o)\n";
  duplicatePermutation(0);

  int a[5] = {0,1,1,1,1};
  do{
    for(int i=0; i<5; i++)
      if(a[i] == 0) cout << i << " ";
    cout << "\n";
  }while(next_permutation(a, a+5));

  return 0;
}