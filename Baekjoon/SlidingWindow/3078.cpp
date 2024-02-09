/*
  백준 [좋은 친구]
  https://www.acmicpc.net/problem/3078
  슬라이딩 윈도우
*/

#include <iostream>
#include <string>
#include <cstring>

using namespace std;

#define MAX_N (300000)

int N, K; // 학생 수, 친구 사이 등수 차이
string name[MAX_N + 10];

int cnt[MAX_N + 10];

void Input_Data(void)
{
  string str;
  cin >> N >> K;
  for (int i = 0; i < N; i++)
  {
    cin >> name[i];
  }

  memset(cnt, 0, sizeof(cnt));
}

long long Solve()
{
  long long result = 0;
  int s = 0, e = 0;
  for (; e <= K; e++)
  {
    cnt[name[e].size()]++;
  }
  e--;

  for (; s < N;)
  {
    // cout << "s: " << s << ", e: " << e << ", " << cnt[name[s].size()] << "\n";
    if (cnt[name[s].size()] >= 2)
    {
      result += (cnt[name[s].size()] - 1);
    }
    cnt[name[s].size()]--;
    s++;
    if (e == N - 1)
      continue;
    e++;
    cnt[name[e].size()]++;
  }

  return result;
}

int main(void)
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  long long sol = -1;

  // 입력 받는 부분
  Input_Data();

  // 여기서부터 작성
  sol = Solve();

  // 출력하는 부분
  cout << sol << '\n';

  return 0;
}