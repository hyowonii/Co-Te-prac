/*
  백준 [참외밭]
  https://www.acmicpc.net/problem/2477
  수학, 구현
*/

#include <iostream>
#include <vector>
using namespace std;

int K;         // 1m^2의 넓이에 자라는 참외 개수
int A[6 + 10]; // i번째 변의 방향 (1: 동, 2: 서, 3: 남, 4: 북)
int B[6 + 10]; // i번째 변의 길이

int mw = 0, mh = 0; // 맥스 가로, 세로

void InputData()
{
  cin >> K;
  for (int i = 0; i < 6; i++)
  {
    cin >> A[i] >> B[i];
    // 확장
    A[i + 6] = A[i];
    B[i + 6] = B[i];
  }
}

int CalArea()
{
  // 1. 전체 직사각형 넓이(맥스 가로 * 맥스 세로)
  int rec1;

  // 2. 작은 직사각형 넓이
  int rec2;
  for (int i = 0; i < 6; i++)
  {
    if (A[i] == A[i + 2] && A[i + 1] == A[i + 3])
    {
      rec2 = B[i + 1] * B[i + 2];
      // 전체 가로, 세로 길이 => 전체 직사각형 넓이
      mw = B[i + 4];
      mh = B[i + 5];
      rec1 = mw * mh;
      break;
    }
  }

  // 3. 큰 직사각형 - 작은 직사각형
  return rec1 - rec2;
}

int Solve()
{
  // 1. 1m^2의 넓이에 자라는 참외 개수

  // 2. 참외밭 넓이 (둘레 길이 활용)
  int area = CalArea();

  // 3. 1m^2 참외 개수 * 밭 넓이
  return K * area;
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