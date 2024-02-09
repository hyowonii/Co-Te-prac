/*
  백준 [탈출]
  https://www.acmicpc.net/problem/3055
  bfs
*/

#include <iostream>
#include <queue>
using namespace std;
#define MAXN (50)
int R, C;                       // 지도 세로, 가로 크기
char map[MAXN + 10][MAXN + 10]; // 비어있는 곳은 '.', 홍수지역은 '*', 바위지역은 'X', 비버의 굴은 'D', 그리고 화가의 위치는 'S'

// 화가(S) --> 비버의 굴(D)
// 화가(S), 홍수(*) 매 분마다 사방으로 이동
// 화가(S) -> 바위(X), 홍수(*) 불가능
// 홍수(*) -> 바위(X), 비버의 굴(D) 불가능

char tmpMap[MAXN + 10][MAXN + 10]; // 실제 이용할 맵
pair<int, int> D;                  // 비버의 굴 위치
queue<pair<int, int>> Q1;
queue<pair<int, int>> Q2;
queue<pair<int, int>> QS1; // 화가
queue<pair<int, int>> QS2;
int visited[MAXN + 10][MAXN + 10] = {0};

void InputData()
{
  cin >> R >> C;
  for (int i = 0; i < R; i++)
  {
    cin >> map[i];
  }
}

void Init()
{
  Q1 = queue<pair<int, int>>(); // 큐 초기화
  Q2 = queue<pair<int, int>>();
  QS1 = queue<pair<int, int>>();
  QS2 = queue<pair<int, int>>();

  // map -> tmpMap 복사
  for (int i = 0; i < R; i++)
    for (int j = 0; j < C; j++)
    {
      tmpMap[i][j] = map[i][j];

      // & visited 초기화
      visited[i][j] = 0;

      // & 화가 위치 저장
      if (map[i][j] == 'S')
      {
        QS2.push({i, j});
        visited[i][j] = 1;
        tmpMap[i][j] = '.';
      }

      // & 홍수 위치 큐에 저장
      if (map[i][j] == '*')
        Q2.push({i, j});

      // & 비버 굴 위치 저장
      if (map[i][j] == 'D')
        D = {i, j};
    }
}

int Solve()
{
  static int dr[4] = {-1, 0, 1, 0};
  static int dc[4] = {0, 1, 0, -1};

  // 홍수(*) 확산 & 화가 이동 bfs
  while (!QS2.empty())
  {
    // 1. 홍수 확산(사방으로 한번만)
    Q1 = Q2;
    Q2 = queue<pair<int, int>>();
    while (!Q1.empty())
    {
      auto cur = Q1.front();
      Q1.pop();

      for (int dir = 0; dir < 4; dir++)
      {
        int nr = cur.first + dr[dir];
        int nc = cur.second + dc[dir];

        if (nr < 0 || nr >= R || nc < 0 || nc >= C)
          continue;
        if (tmpMap[nr][nc] == 'X' || tmpMap[nr][nc] == 'D' || tmpMap[nr][nc] == '*')
          continue;

        tmpMap[nr][nc] = '*';
        Q2.push({nr, nc}); // 다음 번에 진행할 홍수들
      }
    }

    // 2. 화가 이동 bfs
    QS1 = QS2;
    QS2 = queue<pair<int, int>>();
    while (!QS1.empty())
    {
      auto cur = QS1.front();
      QS1.pop();

      // cout << cur.first << ", " << cur.second << "\n";

      for (int dir = 0; dir < 4; dir++)
      {
        int nr = cur.first + dr[dir];
        int nc = cur.second + dc[dir];

        if (nr < 0 || nr >= R || nc < 0 || nc >= C)
          continue;
        if (tmpMap[nr][nc] == 'X' || tmpMap[nr][nc] == '*')
          continue;
        if (visited[nr][nc])
          continue;

        visited[nr][nc] = visited[cur.first][cur.second] + 1;
        // cout << nr << ", " << nc << ": " << visited[nr][nc] << "\n";
        QS2.push({nr, nc});
      }
    }
  }

  return visited[D.first][D.second] - 1;
}

int main()
{
  int ans = -1;
  InputData(); // 입력 받는 부분

  // 여기서부터 작성
  Init();
  ans = Solve();

  if (ans == -1)
    cout << "KAKTUS" << endl; // 출력 하는 부분
  else
    cout << ans << endl;

  // // tmpMap 출력
  // cout << "\n";
  // for (int i = 0; i < R; i++)
  // {
  //     for (int j = 0; j < C; j++)
  //         cout << tmpMap[i][j];
  //     cout << "\n";
  // }
  // cout << "\n";

  // // visited 출력
  // for (int i = 0; i < R; i++)
  // {
  //     for (int j = 0; j < C; j++)
  //         cout << visited[i][j];
  //     cout << "\n";
  // }

  return 0;
}