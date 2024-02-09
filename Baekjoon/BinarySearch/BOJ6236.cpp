/*
  백준 [용돈관리]
  https://www.acmicpc.net/problem/6236
  이분탐색
*/

// N일동안 용돈 사용
// M번 인출, K원 만큼

#include <iostream>

using namespace std;

#define MAX_N (100000)

int N, M;
int need[MAX_N];

void Input_Data(void)
{
  cin >> N >> M;
  for (int i = 0; i < N; i++)
  {
    cin >> need[i];
  }
}

bool ispossible(int k)
{
  int money = k;
  int cnt = 1;
  for (int i = 0; i < N; i++)
  {
    if (money < need[i])
    {
      money = k;
      cnt++;
    }
    money -= need[i];
  }

  if (cnt <= M)
    return true;
  else
    return false;
}

int Solve()
{
  int s = 0, e = 0, m;
  // s, e 초기화
  for (int i = 0; i < N; i++)
  {
    s = max(s, need[i]);
    e += need[i];
  }

  while (s < e)
  {
    m = (s + e) / 2; // 현재 K

    if (ispossible(m))
    {
      e = m;
    }
    else
    {
      s = m + 1;
    }
  }

  if (s != m)
    m = s;

  return m;
}

int main(void)
{
  ios_base::sync_with_stdio();
  cin.tie(nullptr);
  cout.tie(nullptr);
  int sol = -1;

  // 입력 받는 부분
  Input_Data();

  // 여기서부터 작성
  sol = Solve();

  // 출력하는 부분
  cout << sol << '\n';

  return 0;
}