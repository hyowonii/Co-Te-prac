/*
  백준 [색종이2]
  https://www.acmicpc.net/problem/2567
  구현
*/

#include <iostream>
using namespace std;

int N;
int A[100 + 10];
int B[100 + 10];

bool board[100 + 10][100 + 10];
int di[4] = {-1, 0, 1, 0};
int dj[4] = {0, -1, 0, 1};

void init()
{
  for (int i = 0; i <= 100; i++)
    for (int j = 0; j <= 100; j++)
      board[i][j] = false;
}

void InputData()
{
  cin >> N;
  init();
  for (int i = 0; i < N; i++)
  {
    cin >> A[i] >> B[i];
    // 1. 보드 위에 그리기
    for (int x = A[i]; x < A[i] + 10; x++)
      for (int y = B[i]; y < B[i] + 10; y++)
        board[x][y] = true;
  }
}

int Solve()
{
  int len = 0;
  // 2. 보드 돌기
  for (int i = 0; i < 100; i++)
  {
    for (int j = 0; j < 100; j++)
    {
      if (board[i][j] == true)
      {
        for (int dir = 0; dir < 4; dir++)
        {
          int ni = i + di[dir];
          int nj = j + dj[dir];
          if (board[ni][nj] == false)
            len++;
        }
      }
    }
  }

  return len;
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