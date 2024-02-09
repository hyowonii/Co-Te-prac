/*
  백준 [Road Block]
  https://www.acmicpc.net/problem/5917
  bfs
*/

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int N, M;
int A[10000 + 10];
int B[10000 + 10];
int L[10000 + 10];

int ans;
int mnDis = 0x3f3f3f3f;
bool flag = false;

int map[100 + 10][100 + 10] = {0};
struct ST
{
  int node;
  int dis;
};
vector<int> way;
int mnWay[100 + 10];

void InputData()
{
  cin >> N >> M;
  for (int i = 0; i < M; i++)
  {
    cin >> A[i] >> B[i] >> L[i];

    map[A[i]][B[i]] = L[i];
    map[B[i]][A[i]] = L[i];
  }
}

int Solve()
{
  queue<ST> Q;
  Q.push({1, 0});
  mnWay[1] = 1;
  int tmpMn = 0x3f3f3f3f;

  int visited[100 + 10];
  for (int i = 0; i < 110; i++)
    visited[i] = 0x3f3f3f3f;

  while (!Q.empty())
  {
    auto cur = Q.front();
    Q.pop();
    // cout << cur.dis << ' ' << cur.node << '\n';
    // cout << "N: " << N << "\n";
    if (cur.node == N)
    {
      // cout << "    =" << cur.dis << ", " << tmpMn << "\n";
      if (cur.dis < tmpMn)
      {
        tmpMn = cur.dis;
        // cout << tmpMn << "\n";
      }
    }

    for (int nxt = 2; nxt < 101; nxt++)
    {
      if (!map[cur.node][nxt])
        continue;
      if (cur.dis + map[cur.node][nxt] > visited[nxt])
        continue;

      visited[nxt] = cur.dis + map[cur.node][nxt];
      mnWay[nxt] = cur.node;
      Q.push({nxt, cur.dis + map[cur.node][nxt]});
    }
  }

  if (!flag)
  {
    mnDis = tmpMn;
    flag = true;
  }
  return tmpMn;
}

void Solve2()
{
  int result;
  // 경로들 구함
  int tmp = N;
  while (tmp != 1)
  {
    way.push_back(tmp);
    tmp = mnWay[tmp];
  }
  way.push_back(1);

  // 하나씩 바꿔가면서
  while (!way.empty())
  {
    int a = way.back();
    way.pop_back();
    if (way.empty())
      break;
    int b = way.back();
    // cout << "=============================\n";
    // cout << a << ", " << b << "\n";

    map[a][b] *= 2;
    map[b][a] *= 2;

    result = Solve();
    // cout << a << ", " << b << ", result: " << result << "\n";
    ans = max(ans, result - mnDis);

    map[a][b] /= 2;
    map[b][a] /= 2;
  }
}

int main()
{
  // int ans = -1;

  InputData(); // 입력받는 부분

  // 여기서부터 작성
  mnDis = Solve();
  // cout << mnDis << "\n";
  Solve2();

  // for (int i = 1; i <= N; i++)
  //     cout << mnWay[i] << " ";

  cout << ans << endl; // 출력하는 부분
  return 0;
}