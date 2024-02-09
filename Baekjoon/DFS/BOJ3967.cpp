/*
  백준 [매직 스타]
  https://www.acmicpc.net/problem/3967
  dfs
*/

#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
char map[5][10];

vector<pair<int, int>> mapIdx{{0, 4}, {1, 1}, {1, 3}, {1, 5}, {1, 7}, {2, 2}, {2, 6}, {3, 1}, {3, 3}, {3, 5}, {3, 7}, {4, 4}};
char tmpMap[5][10];
bool alph[130] = {false};
bool flag = false;

void InputData()
{
  for (int h = 0; h < 5; h++)
  {
    cin >> map[h];
  }
}
void OutputData()
{
  for (int h = 0; h < 5; h++)
  {
    cout << map[h] << endl;
  }
}

void Init()
{
  for (int i = 0; i < 5; i++)
    for (int j = 0; j < 9; j++)
      tmpMap[i][j] = map[i][j];

  // alph 배열 init
  for (int h = 0; h < 5; h++)
  {
    for (int w = 0; w < 9; w++)
    {
      if (map[h][w] >= 'A' && map[h][w] <= 'L')
        alph[map[h][w]] = true;
    }
  }
}

void DebugTmpMap(char tmpMap[][10])
{
  for (int i = 0; i < 5; i++)
  {
    for (int j = 0; j < 9; j++)
      cout << tmpMap[i][j];
    cout << "\n";
  }
}

bool Comp(char tMap[][10], char rMap[][10])
{
  // cout << "/////Comp/////\n";
  for (int idx = 0; idx < 12; idx++)
  {
    char tCh = tMap[mapIdx[idx].first][mapIdx[idx].second];
    char rCh = rMap[mapIdx[idx].first][mapIdx[idx].second];
    // cout << tCh << ", " << rCh << "\n";
    if (tCh < rCh)
      return true;
    else if (tCh > rCh)
      return false;
    else
      continue;
  }
  return false;
}

bool CheckSum(char tmpMap[][10])
{
  // 0+2+5+7
  // 0+3+6+10
  // 1+2+3+4
  // 7+8+9+10
  // 1+5+8+11
  // 4+6+9+11
  int idxs[6][4] = {{0, 2, 5, 7}, {0, 3, 6, 10}, {1, 2, 3, 4}, {7, 8, 9, 10}, {1, 5, 8, 11}, {4, 6, 9, 11}};
  for (int i = 0; i < 6; i++)
  {
    int result = 0;
    for (int j = 0; j < 4; j++)
    {
      int h = mapIdx[idxs[i][j]].first;
      int w = mapIdx[idxs[i][j]].second;
      char ch = tmpMap[h][w];
      result += ch;
    }
    if (result != 282)
      return false;
  }

  return true;
}

void DFS(int idx /*현재 tmpMap에서 체크해야 되는 인덱스*/)
{
  if (flag)
    return;
  // 종료
  if (idx == 12)
  {
    // 6줄 합 모두 26인지 체크
    if (CheckSum(tmpMap))
    {
      // cout << 1 << "\n";
      // cout << "tmpMap\n";
      // DebugTmpMap(tmpMap);
      // cout << "map\n";
      // DebugTmpMap(map);

      // 정답과 비교해서 앞서는 걸로 갱신
      // if (Comp(tmpMap, map))
      // {
      for (int i = 0; i < 5; i++)
        for (int j = 0; j < 9; j++)
          map[i][j] = tmpMap[i][j];
      // }
      flag = true;
    }

    return;
  }

  if (tmpMap[mapIdx[idx].first][mapIdx[idx].second] != 'x') // 이미 알파벳 있음
  {
    DFS(idx + 1);
  }
  else
  {
    for (char c = 'A'; c <= 'L'; c++)
    {
      if (alph[c])
        continue;
      // c 집어넣기
      tmpMap[mapIdx[idx].first][mapIdx[idx].second] = c;
      alph[c] = true;
      DFS(idx + 1);
      tmpMap[mapIdx[idx].first][mapIdx[idx].second] = 'x';
      alph[c] = false;
    }
  }
}

void Solve()
{
  Init();
  DFS(0);
}

int main()
{
  InputData(); // 입력받는 부분

  // 여기서부터 작성
  // cout << 'A' + 'I' + 'D' + 'L' - 4 * 'A' + 4 << "\n";
  // cout << 22 + 4 * 'A' << "\n";
  Solve();
  // cout << CheckSum(map) << "\n";

  OutputData(); // 출력하는 부분
  return 0;
}