/*
  백준 [Social Distancing]
  https://www.acmicpc.net/problem/18877
  이분탐색
*/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define MAXNM ((int)1e5)
int N, M;                // 소마리수, 잔디구간 개수
long long A[MAXNM + 10]; // 잔디 구간 시작
long long B[MAXNM + 10]; // 잔디 구간 끝

vector<pair<long long, long long>> q;
long long s = 0, e = 0, m, pos; // pos: 소 위치

void InputData()
{
  cin >> N >> M;
  for (int i = 0; i < M; i++)
  {
    cin >> A[i] >> B[i];
    q.push_back({A[i], B[i]});
  }
}

bool ispossible(long long d)
{
  pos = q[0].first; // 첫번째 소
  int idx = 0;      // 잔디 번호

  for (int i = 1; i < N; i++)
  {
    pos += d; // 다음 소 위치

    if (pos <= q[idx].second)
      continue;

    while (idx < M && pos > q[idx].second)
    {
      idx++;
    }
    if (idx >= M)
      return false;

    if (pos >= q[idx].first)
      continue;
    else
      pos = q[idx].first;
  }

  return true;
}

long long Solve()
{
  long long result = 0;
  // 1. sort
  sort(q.begin(), q.end());
  e = q[M - 1].second;

  // 2.
  while (s <= e)
  {
    m = (s + e) / 2;

    // cout << m << "\n";

    if (ispossible(m))
    {
      result = m;
      s = m + 1;
    }
    else
    {
      e = m - 1;
    }
  }

  return result;
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