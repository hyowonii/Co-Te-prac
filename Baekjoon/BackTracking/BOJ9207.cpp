/*
  백준 [페그 솔리테어]
  https://www.acmicpc.net/problem/9207
  backtracking(dfs)
*/

#include <iostream>
using namespace std;
#define MAXH (5)
#define MAXW (9)
char map[MAXH + 2][MAXW + 2];
int solremain, solmove;

int dh[4][2] = {{1, 2}, {-1, -2}, {0, 0}, {0, 0}};
int dw[4][2] = {{0, 0}, {0, 0}, {1, 2}, {-1, -2}};

void InputData()
{
  for (int h = 1; h <= MAXH; h++)
  {
    cin >> &map[h][1];
  }
}

void DebugMap()
{
  for (int h = 1; h <= MAXH; h++)
  {
    for (int w = 1; w <= MAXW; w++)
      cout << map[h][w] << " ";
    cout << "\n";
  }
}

void Init()
{
  solremain = 8;
  solmove = 0;
}

int CountO()
{
  int result = 0;
  for (int h = 1; h <= MAXH; h++)
    for (int w = 1; w <= MAXW; w++)
      if (map[h][w] == 'o')
        result++;
  return result;
}

bool isInBoundary(int h, int w)
{
  if (h <= 0 || h > MAXH || w <= 0 || w > MAXW)
    return false;
  return true;
}

void DFS(int move)
{
  for (int h = 1; h <= MAXH; h++)
  {
    for (int w = 1; w <= MAXW; w++)
    {
      int cntO = CountO();
      if (cntO < solremain)
      {
        solremain = cntO;
        solmove = move;
        // cout << solremain << ", " << solmove << "\n";
        // DebugMap();
      }

      if (map[h][w] != 'o')
        continue;

      // 핀 뛰어넘기
      for (int dir = 0; dir < 4; dir++)
      {
        int pinH = h + dh[dir][0];
        int pinW = w + dw[dir][0];
        if (!isInBoundary(pinH, pinW))
          continue;
        if (map[pinH][pinW] == 'o') // 옆에 핀이 있으면
        {
          int holeH = h + dh[dir][1];
          int holeW = w + dw[dir][1];
          if (!isInBoundary(holeH, holeW))
            continue;
          if (map[holeH][holeW] == '.') // 핀 너머 다음칸이 빈칸이면
          {
            map[pinH][pinW] = '.'; // 핀 제거
            // 핀 이동
            map[h][w] = '.';
            map[holeH][holeW] = 'o';
            if (w == 8)
              DFS(move + 1);
            else
              DFS(move + 1);
            map[pinH][pinW] = 'o';
            map[h][w] = 'o';
            map[holeH][holeW] = '.';
          }
        }
      }
    }
  }
}

void Solve()
{
  DFS(0);
}

int main()
{
  int T;
  cin >> T;
  for (int t = 1; t <= T; t++)
  {
    InputData(); // 입력받는 부분

    // 여기서부터 작성
    Init();
    Solve();

    cout << solremain << " " << solmove << endl; // 출력하는 부분
  }
  return 0;
}