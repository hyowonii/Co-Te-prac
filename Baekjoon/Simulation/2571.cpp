/*
  백준 [색종이3]
  https://www.acmicpc.net/problem/2571
  구현
*/

#include <iostream>
#include <vector>
#include <cstring>
#include <cmath>
using namespace std;

int N; // 색종이 수
int X[100 + 10];
int Y[100 + 10];

int board[100 + 10][100 + 10];

void InputData()
{
  cin >> N;
  memset(board, 0, sizeof(board));
  for (int i = 0; i < N; i++)
  {
    cin >> X[i] >> Y[i];

    // 채우기
    for (int a = X[i]; a < X[i] + 10; a++)
      for (int b = Y[i]; b < Y[i] + 10; b++)
        board[a][b] = 1;
  }

  // for (int a = 0; a < 101; a++)
  // {
  //     for (int b = 0; b < 101; b++)
  //         cout << board[a][b];
  //     cout << "\n";
  // }
}

bool CheckRec(int xl, int yl, int xr, int yr)
{
  for (int x = xl; x <= xr; x++)
  {
    for (int y = yl; y <= yr; y++)
    {
      if (board[x][y] == 0) // 빈 곳 포함되어 있으면 직사각형 안됨
        return false;
    }
  }

  return true;
}

int Solve()
{
  int mxArea = 100;
  // 1. 전체 채우기 - 입력에서 수행

  // 2. 전체 보드를 돌면서 좌상향(xl,yl), 우하향(xr,yr) 꼭짓점 지정하여 직사각형 만들고 체크
  for (int xl = 0; xl < 100; xl++)
  {
    for (int yl = 0; yl < 100; yl++)
    {
      if (board[xl][yl] == 0) // 색종이 아님
        continue;

      for (int xr = xl + 1; xr < 101; xr++)
      {
        for (int yr = yl + 1; yr < 101; yr++)
        {
          if (board[xr][yr] == 0) // 색종이 아님
            break;

          int area = (xr - xl + 1) * (yr - yl + 1);
          if (mxArea > area)
            continue;

          // 가능한 직사각형인지 체크
          if (CheckRec(xl, yl, xr, yr))
          {
            mxArea = area;
          }

          // cout << xl << ", " << yl << ", " << xr << ", " << yr << ", maxArea: " << mxArea << "\n";
        }
      }
    }
  }

  return mxArea;
}

int main()
{
  int ans = 10 * 10;
  InputData(); // 입력받는 부분

  // 여기서부터 작성
  ans = Solve();

  cout << ans << endl; // 출력하는 부분
  return 0;
}