/*
  정올 [저글링 방사능 오염]
  https://jungol.co.kr/problem/1078
  bfs
*/

#include <iostream>
#include <queue>
#include <cstring>
#include <cmath>
using namespace std;

#define MAXN (100)
int W, H;                       // 지도의 가로 세로 크기
char map[MAXN + 10][MAXN + 10]; // 지도 정보('1':저글링, '0':빈곳)
int sw, sh;                     // 시작위치 가로 세로 좌표

int dh[4] = {-1, 0, 1, 0};
int dw[4] = {0, -1, 0, 1};
int visited[MAXN + 10][MAXN + 10];

void InputData()
{
  cin >> W >> H;
  for (int i = 1; i <= H; i++)
  {
    cin >> &map[i][1];
  }
  cin >> sw >> sh;
}

void Solve()
{

  queue<pair<int, int>> Q;
  Q.push({sh, sw});
  visited[sh][sw] = 3;

  while (!Q.empty())
  {
    auto cur = Q.front();
    Q.pop();

    for (int dir = 0; dir < 4; dir++)
    {
      int nh = cur.first + dw[dir];
      int nw = cur.second + dh[dir];

      if (nw <= 0 || nw > W || nh <= 0 || nh > H)
        continue;
      if (map[nh][nw] == '0' || visited[nh][nw])
        continue;

      visited[nh][nw] = visited[cur.first][cur.second] + 1;
      Q.push({nh, nw});
    }
  }
}

void PrintResult()
{
  int mx = 0;
  int cnt = 0;
  for (int i = 1; i <= H; i++)
  {
    for (int j = 1; j <= W; j++)
    {
      // cout << visited[i][j];
      mx = max(mx, visited[i][j]);
      if (map[i][j] == '1' && !visited[i][j])
        cnt++;
    }
    // cout << "\n";
  }

  cout << mx << "\n";
  cout << cnt << "\n";
}

int main()
{
  InputData(); // 입력 받는 부분

  // 여기서부터 작성
  memset(visited, 0, sizeof(visited));
  Solve();
  PrintResult();

  return 0;
}