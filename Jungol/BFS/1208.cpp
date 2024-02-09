/*
  정올 [귀가]
  https://jungol.co.kr/problem/1208
  bfs
*/

// 모든 목장은 하나 이상의 길로 서로 연결되어 있음
// 대문자 알파벳 : 소 있는 목장
// 소문자 알파벳 : 소 없는 목장
// 헛간 : Z (소 있을 수도, 없을 수도)

#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <cmath>
using namespace std;

int P;
char N1[10000 + 10];
char N2[10000 + 10];
int L[10000 + 10]; // 두 목장 N1, N2 간의 거리

// 답
char farm;            // 가장 먼저 도착하는 소가 있던 목장 번호
int sol = 0x3f3f3f3f; // 소가 걸었던 거리

int V[130][130]; // 두 지점 간의 거리
set<char> cows;  // 출발할 수 있는 소들

// 두 지점 간의 거리 최대로 초기화
void Init()
{
  for (int i = 0; i < 130; i++)
    for (int j = 0; j < 130; j++)
      V[i][j] = 0x3f3f3f3f;
}

void InputData()
{
  cin >> P;
  for (int i = 0; i < P; i++)
  {
    cin >> N1[i] >> N2[i] >> L[i];

    // V initialize
    V[N1[i]][N2[i]] = min(V[N1[i]][N2[i]], L[i]);
    V[N2[i]][N1[i]] = V[N1[i]][N2[i]];

    // 출발 가능한 소들 저장
    if (N1[i] >= 'A' && N1[i] <= 'Y')
      cows.insert(N1[i]);
    if (N2[i] >= 'A' && N2[i] <= 'Y')
      cows.insert(N2[i]);
  }
}

void PrintDebug()
{
  cout << "V[B][d] : " << V['B']['d'] << "\n";
  cout << "V[d][Z] : " << V['d']['Z'] << "\n";

  for (auto c : cows)
    cout << c << " ";
  cout << "\n";
}

void Solve()
{
  // 출발 가능한 소들 돌면서
  for (char start : cows)
  {
    queue<pair<int, int>> Q; // {지점, 거리}
    int visited[130];
    for (int i = 0; i < 130; i++)
      visited[i] = 0x3f3f3f3f;

    Q.push({start, 0});
    visited[start] = 0;

    while (!Q.empty())
    {
      auto cur = Q.front();
      Q.pop();

      if (cur.first == 'Z')
      {
        if (cur.second < sol)
        {

          sol = cur.second;
          farm = start;
          // cout << farm << ", " << sol << "\n";
        }
        continue;
      }

      for (int nxt = 0; nxt < 130; nxt++)
      {
        if (V[cur.first][nxt] == 0x3f3f3f3f)
          continue;
        if (cur.second + V[cur.first][nxt] > visited[nxt])
          continue;
        visited[nxt] = cur.second + V[cur.first][nxt];
        Q.push({nxt, cur.second + V[cur.first][nxt]});
      }
    }
  }
}

int main()
{
  Init();
  InputData(); // 입력받는 부분

  // 여기서부터 작성
  // PrintDebug();
  Solve();

  cout << farm << " " << sol << endl; // 출력하는 부분
  return 0;
}