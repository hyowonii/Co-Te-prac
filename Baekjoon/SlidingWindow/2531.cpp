/*
  백준 [회전초밥]
  https://www.acmicpc.net/problem/2531
  슬라이디 윈도우
*/

#include <iostream>
#include <string.h>
using namespace std;

int N, D, K, C;
int A[3000000 + 10];

void InputData()
{
  cin >> N >> D >> K >> C;
  for (int i = 0; i < N; i++)
  {
    cin >> A[i];
  }
}

int Solve()
{
  int isChecked[3000 + 10];
  memset(isChecked, 0, sizeof(isChecked));
  int cnt = 0;

  int res = 0; // 결과

  // 슬라이딩윈도우 초기화
  for (int i = 0; i < K; i++)
  {
    if (!isChecked[A[i]])
      cnt++;
    isChecked[A[i]]++;
  }
  if (!isChecked[C])
    res = cnt + 1;
  else
    res = cnt;

  for (int i = K; i < N + K - 1; i++)
  {
    isChecked[A[i - K]]--;
    if (isChecked[A[i - K]] == 0)
      cnt--;
    if (!isChecked[A[i]])
    {
      cnt++;
    }
    isChecked[A[i]]++;

    if (!isChecked[C])
    {
      if (cnt + 1 > res)
        res = cnt + 1;
    }
    else
    {
      if (cnt > res)
        res = cnt;
    }
  }

  return res;
}

int main()
{
  int ans = -1;

  InputData(); // 입력받는 부분

  // 여기서부터 작성
  ans = Solve();

  cout << ans << endl; // 출력하는 부분
  return 0;
}