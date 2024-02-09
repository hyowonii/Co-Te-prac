/*
  백준 [연속부분최대곱]
  https://www.acmicpc.net/problem/2670
  dp
*/

#include <iostream>
#include <stdio.h>
using namespace std;

int N;
double D[10000 + 10];

double mult[10000 + 10];

void InputData()
{
  cin >> N;
  for (int i = 0; i < N; i++)
  {
    cin >> D[i];
  }
}

double Solve()
{

  double mx = -1; // 최대값

  double res = 1;
  for (int i = 0; i < N; i++)
  {
    if (res >= 1.0)
      res *= D[i];
    else
      res = D[i];

    if (res > mx)
      mx = res;
  }

  return mx;
}

int main()
{
  cin.tie(0);
  ios_base::sync_with_stdio(0);

  double ans = -1;

  InputData(); // 입력받는 부분

  // 여기서부터 작성
  ans = Solve();

  printf("%.3lf\n", ans); // 출력하는 부분
  return 0;
}