/*
  백준 [Puyo Puyo]
  https://www.acmicpc.net/problem/11559
  bfs
*/

// 뿌요를 놓고 난 후, 같은 색 뿌요가 4개 이상 상하좌우로 연결되어 있으면 연결된 같은 색 뿌요들이 한꺼번에 없어진다. = > bfs

#include <iostream>
#include <queue>
#include <vector>
using namespace std;
#define MAXH (12)
#define MAXW (6)
char map[MAXH + 2][MAXW + 2]; // R은 빨강, G는 초록, B는 파랑, P는 보라, Y는 노랑

vector<pair<int, int>> doBomb;

char ch;                    // 터진(터질) 문자
vector<pair<int, int>> tmp; // 터진(터질) 위치 저장. 초기화 해줘야됨!!!!

void InputData()
{
  for (int i = 1; i <= MAXH; i++)
  {
    cin >> &map[i][1];
  }
}

void DebugMap()
{
  cout << "==================================\n";
  for (int i = 1; i <= 12; i++)
  {
    for (int j = 1; j <= 6; j++)
    {
      cout << map[i][j] << " ";
    }
    cout << "\n";
  }
}

// 터지기 수행
int BFS(int x, int y)
{
  static int dx[4] = {-1, 0, 1, 0};
  static int dy[4] = {0, -1, 0, 1};

  ch = map[x][y]; // 터뜨릴 문자
  int cnt = 0;    // 터진 문자 개수

  queue<pair<int, int>> Q;
  Q.push({x, y});
  cnt++;
  map[x][y] = '*';
  tmp.push_back({x, y});

  while (!Q.empty())
  {
    auto cur = Q.front();
    Q.pop();
    // cout << "cur: " << cur.first << ", " << cur.second << "\n";

    for (int dir = 0; dir < 4; dir++)
    {
      int nx = cur.first + dx[dir];
      int ny = cur.second + dy[dir];

      if (nx <= 0 || nx > 12 || ny <= 0 || ny > 6)
        continue;

      if (map[nx][ny] != ch) // 같은 문자 아니면
        continue;
      // cout << nx << ", " << ny << " : " << map[nx][ny] << ", " << ch << "\n";
      cnt++;
      Q.push({nx, ny});
      map[nx][ny] = '*';
      tmp.push_back({nx, ny});
    }
  }

  // DebugMap();

  return cnt;
}

void Move()
{
  for (int j = 1; j <= 6; j++)
  {
    int cnt = 0;
    // 밑에서부터 올라오면서 보면서
    for (int i = 12; i >= 1; i--)
    {
      if (map[i][j] == '*')
      {
        cnt++;
        continue;
      }

      if (cnt)
      {
        map[i + cnt][j] = map[i][j];
        map[i][j] = '.';
      }
    }
  }

  // DebugMap();
}

int Solve()
{
  int cnt = 0;
  int flag = true;
  while (flag)
  {
    flag = false;
    for (int i = 1; i <= 12; i++)
    {
      for (int j = 1; j <= 6; j++)
      {
        if (map[i][j] == '.' || map[i][j] == '*')
          continue;

        int bomb = BFS(i, j); // 터진 개수
        // cout << i << ", " << j << " : " << bomb << "\n";
        // 4개 이상 터졌으면
        if (bomb >= 4)
        {
          // 터진 위치에 내려오기
          tmp.clear();
          flag = true;
        }
        // 4개 미만으로 터졌으면 터지지 않고 map 원상복구
        else
        {
          while (!tmp.empty())
          {
            auto t = tmp.back();
            map[t.first][t.second] = ch;
            tmp.pop_back();
          }
        }
      }
    }
    Move();
    if (flag)
      cnt++;

    // cout << "=====================" << cnt << "=================\n";
  }

  return cnt;
}

int main()
{
  int ans = -1;
  InputData(); // 입력받는 부분

  // 여기서부터 작성
  ans = Solve();
  // cout << BFS(9, 2) << "\n";
  // cout << BFS(11, 1) << "\n";
  // cout << BFS(11, 4) << "\n";

  cout << ans << endl; // 출력하는 부분

  return 0;
}