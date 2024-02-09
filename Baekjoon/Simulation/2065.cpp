/*
  백준 [나룻배]
  https://www.acmicpc.net/problem/2065
  구현
*/

#include <iostream>
#include <string>
#include <queue>
using namespace std;

#define MAXN ((int)1e4)
int M, T, N; // 배에태울수있는수, 배이동시간, 손님수
int AT[MAXN + 10];
string SIDE[MAXN + 10];

int arrived[MAXN + 10];

queue<int> q[2]; // 0:왼, 1:오
int side = 0;    // 0:왼, 1:오
int totalT = 0;
int arvCnt = 0; // 도착한 사람 수 카운트

void InputData()
{
  cin >> M >> T >> N;
  for (int i = 0; i < N; i++)
  {
    cin >> AT[i] >> SIDE[i];
    if (SIDE[i] == "left")
      q[0].push(i);
    else
      q[1].push(i);
  }
}
void OutputData()
{
  for (int i = 0; i < N; i++)
  {
    cout << arrived[i] << "\n";
  }
}

void Solve()
{
  while (arvCnt < N)
  {
    // 현재 선착장에서 사람 태울 수 있음
    if (!q[side].empty() && (totalT >= AT[q[side].front()]))
    {
      int cnt = 0; // 태울 수 있는 사람 수
      while (!q[side].empty() && totalT >= AT[q[side].front()] && cnt < M)
      {
        cnt++;
        arvCnt++;
        arrived[q[side].front()] = totalT + T;
        // cout << "arrived[" << q[side].front() << "] = " << totalT + T << "\n";
        q[side].pop();
      }
      side = 1 - side;
      totalT += T;
    }
    else
    {
      // 현재 큐가 비어있는 경우
      if (q[side].empty())
      {
        side = 1 - side;
        // 반대쪽 선착장에 손님 있으면
        if (!q[side].empty() && totalT < AT[q[side].front()])
          totalT = AT[q[side].front()];
        totalT += T;
      }
      // 현재 큐가 비어있지 않은데, 손님이 나중에 도착하면
      else
      {
        // // 현재 선착장에 손님이 먼저 도착하면
        // if (!q[1 - side].empty() && AT[q[side].front()] <= AT[q[1 - side].front()])
        // {
        //   totalT = AT[q[side].front()];
        // }
        // // 반대쪽 선착장에 손님이 먼저 도착하면
        // else
        // {
        //   side = 1 - side;
        //   if (totalT < AT[q[side].front()])
        //     totalT = AT[q[side].front()];
        //   totalT += T; // 배 이동 시간
        // }

        // 반대쪽 선착장에 손님이 먼저 도착하면
        if (!q[1 - side].empty() && AT[q[side].front()] > AT[q[1 - side].front()])
        {
          side = 1 - side;
          if (totalT < AT[q[side].front()])
            totalT = AT[q[side].front()];
          totalT += T;
        }
        // 현재 선착장에 손님이 먼저 도착하면
        else
          totalT = AT[q[side].front()];
      }
    }
  }
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  InputData(); // 입력받는 부분

  // 여기서부터 작성
  Solve();

  OutputData(); // 출력하는 부분
  return 0;
}