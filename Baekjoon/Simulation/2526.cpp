/*
  백준 [싸이클]
  https://www.acmicpc.net/problem/2526
  구현
*/

#include <iostream>
using namespace std;

#define MAXL 100

int N, P;

int check[MAXL];
int result;

void InputData()
{
  cin >> N >> P;
}

int Solve(int cnt)
{
  while (true)
  {
    result = (result * N) % P;
    if (check[result] != 0)
    {
      break;
    }
    else
    {
      check[result] = ++cnt;
    }
  }
  return cnt + 1 - check[result];
}

int main()
{
  int ans = -1;
  InputData(); // 입력받는 부분

  // 여기서부터 작성
  check[N] = 1;
  result = N;
  ans = Solve(1);

  cout << ans << endl; // 출력하는 부분
  return 0;
}