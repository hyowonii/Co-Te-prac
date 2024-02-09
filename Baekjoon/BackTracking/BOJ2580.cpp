/*
  백준 [스도쿠]
  https://www.acmicpc.net/problem/2580
  backtracking(dfs)
*/

#include <iostream>
#define MAX 9
using namespace std;

int sudoku[MAX][MAX];
bool Row[MAX][MAX];
bool Col[MAX][MAX];
bool Square[MAX][MAX];

bool flag = false;

void InputData()
{
  for (int i = 0; i < MAX; i++)
  {
    for (int j = 0; j < MAX; j++)
    {
      cin >> sudoku[i][j];
      if (sudoku[i][j] != 0)
      {
        Row[i][sudoku[i][j]] = true;                        // i번째 가로줄에 숫자 sudoku[i][j]가 있으면
        Col[j][sudoku[i][j]] = true;                        // i번째 세로줄에 숫자 sudoku[i][j]가 있으면
        Square[(i / 3) * 3 + (j / 3)][sudoku[i][j]] = true; // i번째 사각형에 숫자 sudoku[i][j]가 있으면
      }
    }
  }
}

void OutputData()
{
  for (int i = 0; i < MAX; i++)
  {
    for (int j = 0; j < MAX; j++)
    {
      cout << sudoku[i][j] << " ";
    }
    cout << endl;
  }
}

void DFS(int Cnt)
{
  if (flag)
    return;

  int x = Cnt / MAX; // x 좌표
  int y = Cnt % MAX; // y 좌표

  if (Cnt == 81)
  {
    OutputData();
    flag = true;
  }

  if (sudoku[x][y] == 0)
  {
    for (int i = 1; i <= 9; i++)
    {
      if (!Row[x][i] && !Col[y][i] && !Square[(x / 3) * 3 + (y / 3)][i])
      {
        Row[x][i] = true;
        Col[y][i] = true;
        Square[(x / 3) * 3 + (y / 3)][i] = true;
        sudoku[x][y] = i;
        DFS(Cnt + 1);
        sudoku[x][y] = 0;
        Row[x][i] = false;
        Col[y][i] = false;
        Square[(x / 3) * 3 + (y / 3)][i] = false;
      }
    }
  }
  else
    DFS(Cnt + 1);
}

void Solve()
{

  DFS(0);
}

int main(void)
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  InputData(); // 입력받는 부분

  // 여기서부터 작성
  Solve();

  return 0;
}