/*
  정올 [소수와 함께하는 여행]
  https://jungol.co.kr/problem/1336
  bfs
*/

#include <iostream>
#include <cmath>
#include <queue>
#include <string>
using namespace std;

int S, E; // 출발 정류장 번호, 도착 정류장 번호

bool isPrime[10000 + 10] = {false}; // 인덱스 수에 대한 소수 여부 저장
int visited[10000 + 10] = {false};  // 몇번째로 해당 수에 도착했는지 저장(최소번째가 저장됨)

void InputData()
{
  cin >> S >> E;
}

// 소수인지 판별하는 함수
bool IsPrime(int num)
{
  for (int i = 2; i <= (int)sqrt(num); i++)
  {
    if (num % i == 0)
      return false;
  }

  return true;
}

int Solve()
{
  // 1. 1000 ~ 9999 까지 모든 수에 대해 소수 여부 판단 & 저장
  for (int num = 1000; num <= 9999; num++)
  {
    if (IsPrime(num))
      isPrime[num] = true;
    else
      isPrime[num] = false;
  }

  // 2.
  // int bus = 0; // 타게 되는 버스 개수(들린 마을 - 1)
  queue<int> Q;
  Q.push(S);
  visited[S] = 1;

  while (!Q.empty())
  {
    S = Q.front();
    Q.pop();
    for (int i = 0; i < 4; i++)
    {
      string str = to_string(S); // 기준 숫자의 문자형
      for (char ch = '0'; ch <= '9'; ch++)
      {
        if (i == 0 && ch == '0') // 천의 자리 0 올 수 없음
          continue;
        // S를 한 자리 바꾸고
        str[i] = ch;
        int tmpS = stoi(str); // 한 자리 바꾼 숫자
        // 소수이고 !visited[tmpS]이면 visited[tmpS] 저장하고 진행
        if (IsPrime(tmpS) && !visited[tmpS])
        {
          visited[tmpS] = visited[S] + 1;
          // cout << tmpS << ": " << visited[tmpS] << "\n";
          Q.push(tmpS);
        }
      }
    }
  }

  return visited[E] - 1;
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