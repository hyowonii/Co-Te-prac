/*
  백준 [Escaping the farm]
  https://www.acmicpc.net/problem/5921
  dfs
*/

#include <iostream>
using namespace std;

int N;     // 소들의 수
int W[21]; // 소들의 무게

int ans = 1;

void InputData()
{
  cin >> N;
  for (int i = 1; i <= N; i++)
  {
    cin >> W[i];
  }
}

// 자리올림 발생 체크
bool check(int a, int b)
{
  if (a == 0 && b == 0)
    return false;
  while (a != 0 && b != 0)
  {
    if ((a % 10) + (b % 10) >= 10)
      return false;
    a /= 10;
    b /= 10;
  }

  return true;
}

void DFS(int idx, int sum, int cnt)
{
  if (idx == N + 1)
  {
    if (cnt > ans)
      ans = cnt;
    return;
  }

  // cout << sum << ", " << W[idx] << ": " << check(sum, W[idx]) << ", cnt: " << cnt << "\n";

  if (check(sum, W[idx]))
    DFS(idx + 1, sum + W[idx], cnt + 1);
  DFS(idx + 1, sum, cnt);
}

int main()
{
  InputData(); // 입력받는 부분

  // 여기서부터 작성
  DFS(0, 0, 0);

  cout << ans << endl; // 출력하는 부분
  return 0;
}