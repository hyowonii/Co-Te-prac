/*
  정올 [숫자근]
  https://jungol.co.kr/problem/1260
  구현
*/

// int -> to_string() 으로 변환 후 반복문 돌려 각 자리 수 더하기
// string 길이 1 이하일 때까지 돌림
// 각 숫자에 대한 숫자근 구할 때마다 이전과 비교하여 큰 수를 답으로 저장해두기
// 원래 숫자도 변수에 저장해두고, 숫자근 업데이트할 때 숫자근이 같다면 원래 숫자가 작은 수로 저장

#include <iostream>
using namespace std;
#define MAXN ((int)1e3)
int N;            // 정수개수
int A[MAXN + 10]; // 입력 정수

int digit = 1000001;
int mxDigitRoot = 0;

void InputData()
{
  cin >> N;
  for (int i = 0; i < N; i++)
  {
    cin >> A[i];
  }
}

int DigitRoot(int num)
{
  string str = to_string(num);
  int digitRoot;
  while (str.size() > 1)
  {
    digitRoot = 0;
    for (auto c : str)
    {
      digitRoot += (c - '0');
    }
    str = to_string(digitRoot);
  }

  return digitRoot;
}

int Solve()
{
  for (int i = 0; i < N; i++)
  {

    // 1. 숫자근 계산
    int digitRoot = DigitRoot(A[i]);

    // 2. 숫자근 비교
    if (digitRoot > mxDigitRoot)
    {
      mxDigitRoot = digitRoot;
      digit = A[i];
    }
    else if (digitRoot == mxDigitRoot)
    {
      if (A[i] < digit)
        digit = A[i];
    }
  }

  return digit;
}

int main()
{
  int ans = -1;
  InputData(); // 입력 받는 부분

  // 여기서부터 작성
  ans = Solve();

  cout << ans << endl; // 출력하는 부분
  return 0;
}