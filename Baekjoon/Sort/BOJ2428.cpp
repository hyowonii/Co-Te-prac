/*
  백준 [표절]
  https://www.acmicpc.net/problem/2428
  정렬
*/

#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
#define MAXN ((int)1e5)
int N; // 개수
int F[MAXN + 10];

queue<int> q;

void InputData()
{
  cin >> N;
  for (int i = 0; i < N; i++)
  {
    cin >> F[i];
  }
}

long long Solve()
{
  long long total = 0;

  // 1. sort
  sort(F, F + N);

  // 2.
  for (int i = 0; i < N; i++)
  {
    if (q.empty())
    {
      q.push(F[i]);
      continue;
    }

    while (!q.empty() && 10 * q.front() < 9 * F[i])
      q.pop();
    total += q.size();
    q.push(F[i]);
  }

  return total;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long ans = -1;

  InputData(); // 입력받는 부분

  // 여기서부터 작성
  ans = Solve();

  cout << ans << "\n"; // 출력하는 부분
  return 0;
}