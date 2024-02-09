/*
  백준 [Tractor]
  https://www.acmicpc.net/problem/5846
  floodfill
*/

#include <iostream>
#include <queue>
#include <cmath>
using namespace std;

int N;
int grids[500 + 10][500 + 10];

int minimum = 500 * 500 + 1; // 최소로 가야되는 개수
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

int S = 0, E = 1000000, D;

void InputData()
{
  cin >> N;
  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < N; j++)
    {
      cin >> grids[i][j];
    }
  }
}

bool BFS()
{
  bool visited[500 + 10][500 + 10] = {0};
  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < N; j++)
    {
      if (visited[i][j])
        continue;

      int cnt = 0;
      queue<pair<int, int>> Q;

      Q.push({i, j});
      visited[i][j] = true;
      cnt++;

      while (!Q.empty())
      {
        auto cur = Q.front();
        Q.pop();

        for (int dir = 0; dir < 4; dir++)
        {
          int nx = cur.first + dx[dir];
          int ny = cur.second + dy[dir];

          if (nx < 0 || nx >= N || ny < 0 || ny >= N)
            continue;
          if (visited[nx][ny])
            continue;

          int sub = abs(grids[cur.first][cur.second] - grids[nx][ny]); // 차이
          if (sub <= D)
          {
            visited[nx][ny] = true;
            Q.push({nx, ny});
            cnt++;
          }
        }
      }

      if (cnt >= minimum)
        return true;
    }
  }

  return false;
}

int Solve()
{
  // 1. minimun 갱신
  minimum = (N * N + 1) / 2; // 최소로 갈 수 있어야 하는 만큼

  // 2. 이분탐색 & DFS
  int ans;
  while (S <= E)
  {
    D = (S + E) / 2;

    if (BFS())
    {
      ans = D;
      E = D - 1;
    }
    else
    {
      S = D + 1;
    }
  }

  return ans;
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