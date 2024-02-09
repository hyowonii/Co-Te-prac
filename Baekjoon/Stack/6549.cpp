/*
  백준 [히스토그램에서 가장 큰 직사각형]
  https://www.acmicpc.net/problem/6549
  stack
*/

#include <iostream>
#include <typeinfo>
#include <stack>
using namespace std;
typedef long long ll;

int N;              // 히스토그램수
int H[100000 + 10]; // 히스토그램 높이

stack<pair<int, int>> s; // 인덱스, 높이

bool InputData()
{
  cin >> N;
  if (N == 0)
    return false;

  for (int i = 0; i < N; i++)
  {
    cin >> H[i];
  }
  return true;
}

// time limit
ll Solve()
{
  ll mxArea = H[0];

  for (ll i = 0; i < N; i++)
  {
    ll mnH = H[i];
    for (ll j = i; j < N; j++)
    {
      if (H[j] < mnH)
        mnH = H[j];
      ll area = (j - i + 1) * mnH;
      if (area > mxArea)
        mxArea = area;
    }
  }

  return mxArea;
}

// time limit
ll Solve2()
{
  ll mxArea = 0;
  for (int i = 0; i < N; i++)
  {
    int height = H[i]; // 최소 높이로 가짐
    int width = 1;
    for (int j = i + 1; j < N; j++)
    {
      if (H[j] >= height)
        width++;
      else
        break;
    }
    for (int k = i - 1; k >= 0; k--)
    {
      if (H[k] >= height)
        width++;
      else
        break;
    }

    ll area = height * width;
    // cout << height << "*" << width << "=" << area << "\n";
    if (area > mxArea)
      mxArea = area;
  }

  return mxArea;
}

ll Solve3()
{
  ll mxArea = 1 * H[0];
  s.push({0, H[0]});
  int i;
  for (i = 1; i < N; i++)
  {
    if (!s.empty() && H[i] >= s.top().second)
    {
      s.push({i, H[i]});
    }
    else
    {
      int idx;
      while (!s.empty() && s.top().second >= H[i])
      {
        ll area = (ll)(i - s.top().first) * (ll)s.top().second;
        if (area > mxArea)
          mxArea = area;
        idx = s.top().first;
        s.pop();
      }
      s.push({idx, H[i]});
    }
  }

  while (!s.empty())
  {
    ll area = (ll)(i - s.top().first) * (ll)s.top().second;
    if (area > mxArea)
      mxArea = area;
    s.pop();
  }

  return mxArea;
}

int main()
{
  long long ans = -1;
  while (InputData())
  { // 입력받는 부분

    // 여기서부터 작성
    ans = Solve3();

    cout << ans << "\n"; // 출력하는 부분
  }
  return 0;
}