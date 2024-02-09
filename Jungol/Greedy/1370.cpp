/*
  정올 [회의실 배정]
  https://jungol.co.kr/problem/1370
  greedy
*/

#include <iostream>
#include <tuple>
#include <vector>
#include <algorithm>
using namespace std;

int N;             // 회의 개수
int ID[500 + 10];  // 회의 번호
int S[500 + 10];   // 시작 시간
int E[500 + 10];   // 종료 시간
int sol[500 + 10]; // 배정 가능한 회의 배열

vector<tuple<int, int, int>> t;

void InputData()
{
  cin >> N;
  for (int i = 0; i < N; i++)
  {
    cin >> ID[i] >> S[i] >> E[i];
    t.push_back(make_tuple(E[i], S[i], ID[i]));
  }
}
void OutputData(int ans)
{
  cout << ans << endl;           // 배정 가능한 최대 회의 수
  for (int i = 1; i <= ans; i++) // 배정 회의 번호 시간대순 출력
  {
    cout << sol[i] << " ";
  }
  cout << endl;
}

int Solve()
{
  sort(t.begin(), t.end());
  int time = get<0>(t[0]); // 가장 빨리 끝나는 시간
  int cnt = 1;             // 회의 개수
  sol[cnt] = get<2>(t[0]); // 회의 번호
  for (int i = 1; i < N; i++)
  {
    int nstart = get<1>(t[i]);
    if (nstart >= time)
    {
      cnt++;
      sol[cnt] = get<2>(t[i]);
      time = get<0>(t[i]);
    }
  }

  return cnt;
}

int main()
{
  cin.tie(0);
  ios_base::sync_with_stdio(0);

  int ans = -1;

  InputData(); // 입력받는 부분

  // 여기서부터 작성
  ans = Solve();

  OutputData(ans); // 출력하는 부분
  return 0;
}