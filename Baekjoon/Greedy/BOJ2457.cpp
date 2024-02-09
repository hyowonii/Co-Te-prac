/*
  백준 [공주님의 정원]
  https://www.acmicpc.net/problem/2457
  그리디
*/

#include <iostream>
#include <vector>

using namespace std;

int N;
vector<pair<int, int>> f;
int answer = 0;

int main(void)
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N;
  while (N--)
  {
    int sm, sd, em, ed;
    cin >> sm >> sd >> em >> ed;
    f.push_back({sm * 100 + sd, em * 100 + ed}); // 날짜 파싱
  }

  int now = 301;
  while (now < 1201)
  {
    int nxt = now;
    for (int i = 0; i < f.size(); i++)
    {
      if (f[i].first <= now && f[i].second > nxt)
        nxt = f[i].second;
    }
    if (nxt == now)
    { // 만족하는 꽃 없음
      cout << 0;
      return 0;
    }
    answer++;
    now = nxt;
  }

  cout << answer;
}