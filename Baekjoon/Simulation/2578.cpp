/*
  백준 [빙고]
  https://www.acmicpc.net/problem/2578
  구현
*/

#include <iostream>
#include <vector>
using namespace std;

// int A[5 + 10][5 + 10]; // 빙고판
int B[25 + 10]; // 부르는 숫자

struct Pos
{
  int x, y;
} p[25 + 10];

void InputData()
{
  for (int i = 0; i < 5; i++)
  {
    for (int j = 0; j < 5; j++)
    {
      // cin >> A[i][j];
      int n;
      cin >> n;
      p[n] = {i, j};
    }
  }
  for (int i = 0; i < 25; i++)
  {
    cin >> B[i];
  }
}

void init()
{
}

int Solve()
{

  int bingo = 0;              // 빙고 개수
  int bingoCnt[12 + 1] = {0}; // 0~4: 행, 5~9: 열, 10~11: 대각선

  int res = -1; // 정답(몇 번째 수인지)

  for (int i = 0; i < 25; i++)
  {
    int num = B[i];     // 부른 숫자
    int row = p[num].x; // 부른 숫자의 행 위치
    int col = p[num].y; // 부른 숫자의 열 위치

    bingoCnt[row]++;
    bingoCnt[col + 5]++;

    if (bingoCnt[row] == 5)
      bingo++;

    if (bingoCnt[col + 5] == 5)
      bingo++;

    if (row == col)
    {
      bingoCnt[10]++;
      if (bingoCnt[10] == 5)
        bingo++;
    }

    if (row + col == 4)
    {
      bingoCnt[11]++;
      if (bingoCnt[11] == 5)
        bingo++;
    }

    if (bingo >= 3)
    {
      res = i + 1;
      break;
    }
  }

  return res;
}

int main()
{
  cin.tie(0);
  ios_base::sync_with_stdio(0);

  int ans = -1;
  InputData(); // 입력받는 부분

  // 여기서부터 작성
  init();
  ans = Solve();

  cout << ans << endl; // 출력하는 부분
  return 0;
}