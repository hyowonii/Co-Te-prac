/*
  정올 [도서관]
  https://jungol.co.kr/problem/2247
  greedy
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
int S[10000 + 10];
int E[10000 + 10];
int present = 0;
int absent = 0;

vector<pair<int, int>> v;

void InputData(void)
{
  cin >> N;
  for (int i = 0; i < N; i++)
  {
    cin >> S[i] >> E[i];
    v.push_back({S[i], E[i]});
  }
}

void Solve()
{
  // 1. 정렬 (시작 시간, 끝 시간) 기준
  sort(v.begin(), v.end());

  // 2.
  int s = v[0].first;
  int e = v[0].second;
  int tmpPresent = e - s;
  int tmpAbsent = 0;
  for (int i = 1; i < N; i++)
  {
    if (v[i].first <= e) // 연결됨
    {
      if (v[i].second < e)
        continue;

      tmpPresent += (v[i].second - e);
      e = v[i].second;

      if (tmpAbsent > absent)
        absent = tmpAbsent;
      tmpAbsent = 0;
    }
    else // 공백 생김
    {
      tmpAbsent = (v[i].first - e);
      s = v[i].first;
      e = v[i].second;

      if (tmpPresent > present)
        present = tmpPresent;
      tmpPresent = e - s;
    }
  }
  if (tmpAbsent > absent)
    absent = tmpAbsent;
  if (tmpPresent > present)
    present = tmpPresent;
}

int main(void)
{
  InputData(); // 입력받는 부분

  // 여기서부터 작성
  Solve();

  cout << present << " " << absent << endl; // 출력하는 부분
  return 0;
}