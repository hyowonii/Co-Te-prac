/*
  정올 [냉장고]
  https://jungol.co.kr/problem/1828
  greedy
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;           // 화학물질 수
int X[100 + 10]; // 최저보관온도
int Y[100 + 10]; // 최고보관온도

vector<pair<int, int>> cs;

void InputData()
{
  cin >> N;
  for (int i = 0; i < N; i++)
  {
    cin >> X[i] >> Y[i];
    cs.push_back({X[i], Y[i]});
  }
}

int Solve()
{
  int cnt = 1;

  // 1. 정렬(최저보관온도 오름차순)
  sort(cs.begin(), cs.end());

  // 2. 카운팅
  int low = cs[0].first;
  int high = cs[0].second;
  for (int i = 1; i < N; i++)
  {
    auto cur = cs[i];

    if (cur.first <= high)
    {
      low = cur.first;
      if (cur.second < high)
        high = cur.second;
    }
    else
    {
      cnt++;
      low = cur.first;
      high = cur.second;
    }
  }

  return cnt;
}

int main()
{
  int ans = -1;

  InputData(); // 입력받는 부분

  // 여기서부터 작성
  ans = Solve();

  cout << ans << endl; // 출력하는 부분
  return 0;
}