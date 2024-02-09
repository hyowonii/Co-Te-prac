/*
  정올 [등산로 찾기]
  https://jungol.co.kr/problem/1111
  bfs
*/

#include <iostream>
#include <algorithm>
#include <queue>
#include <cmath>
using namespace std;

#define MAXN (105)
int N;                     // 산크기
int eh, ew;                // 목적지 위치 세로, 가로
int map[MAXN][MAXN] = {0}; // 평지는 0으로 저장되어있음

// (0,0) (0,1) ...
// (1,0) (1,1) ...
// ...

int dh[4] = {0, -1, 0, 1};
int dw[4] = {1, 0, -1, 0};
int power[MAXN][MAXN]; // 사용된 힘

void InputData()
{
  cin >> N;
  cin >> eh >> ew;
  for (int h = 1; h <= N; h++)
  {
    for (int w = 1; w <= N; w++)
    {
      cin >> map[h][w];
    }
  }
}

void Init()
{
  // 힘 초기화
  for (int i = 1; i <= N; i++)
  {
    for (int j = 1; j <= N; j++)
    {
      power[i][j] = 0x3f3f3f3f;
    }
  }
}

int Solve()
{
  int result = 0x3f3f3f3f;
  for (int h = 0; h <= N + 1; h++)
  {
    for (int w = 0; w <= N + 1; w++)
    {
      // 평지아니면 컨티뉴 (평지에서 시작하도록)
      if (map[h][w])
        continue;

      queue<pair<int, int>> Q;
      Q.push({h, w});

      while (!Q.empty())
      {
        auto cur = Q.front();
        Q.pop();

        // cout << "======================\n";
        // cout << cur.first << ", " << cur.second << "\n";

        for (int dir = 0; dir < 4; dir++)
        {
          int nh = cur.first + dh[dir];
          int nw = cur.second + dw[dir];

          if (nh < 0 || nh > N + 1 || nw < 0 || nw > N + 1)
            continue;
          if (!map[nh][nw]) // 평지로 돌아갈 필요 없음
            continue;

          // 현재 높이 : map[cur.first][cur.second]
          int now = map[cur.first][cur.second];
          // 이동할 높이 : map[nh][nw]
          int move = map[nh][nw];

          int tmpPower;
          // 동일한 높이로 이동할 때는 힘 +0
          if (now == move)
            tmpPower = power[cur.first][cur.second];
          // 내려갈 때는 높이 차이만큼 힘+
          else if (now > move)
            tmpPower = power[cur.first][cur.second] + (now - move);
          // 올라갈 때는 높이 차의 제곱만큼 힘+
          else
            tmpPower = power[cur.first][cur.second] + pow(move - now, 2);

          if (tmpPower < power[nh][nw])
          {
            power[nh][nw] = tmpPower;
            Q.push({nh, nw});
          }

          // cout << nh << ", " << nw << ", tmpPower: " << tmpPower << ", power: " << power[nh][nw] << "\n";
        }
      }

      result = min(result, power[eh][ew]);
    }
  }

  return result;
}

void PrintDebug()
{
  for (int i = 0; i <= N + 1; i++)
  {
    for (int j = 0; j <= N + 1; j++)
    {
      cout << power[i][j] << "          ";
    }
    cout << "\n";
  }
}

int main()
{
  int ans = -1;
  InputData(); // 입력 받는 부분

  // 여기서부터 작성
  Init();
  ans = Solve();
  // PrintDebug();

  cout << ans << endl; // 출력하는 부분
  return 0;
}