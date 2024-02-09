/*
  백준 [경비원]
  https://www.acmicpc.net/problem/2564
  구현
*/

// 경계로만 이동

#include <iostream>
#include <cmath>
using namespace std;

int w, h, n;
int dir[100 + 10];
int len[100 + 10];

void InputData()
{
  cin >> w >> h;
  cin >> n;
  for (int i = 0; i <= n; i++)
  {
    cin >> dir[i] >> len[i];
  }
}

int Solve()
{
  int dis = 0;

  // 동근이
  int Ddir = dir[n];
  int Dlen = len[n];

  for (int i = 0; i < n; i++)
  {
    // 상점 위치
    int Sdir = dir[i];
    int Slen = len[i];

    // 1. 같은 쪽
    if (Ddir == Sdir)
    {
      dis += abs(Dlen - Slen);
    }
    // 2. 마주보는 쪽
    else if (Ddir + Sdir == 3) // 북<->남
    {
      int tmp1 = Dlen + h + Slen;             // 왼쪽으로 돌기
      int tmp2 = (w - Dlen) + h + (w - Slen); // 오른쪽으로 돌기
      dis += min(tmp1, tmp2);
    }
    else if (Ddir + Sdir == 7) // 동<->서
    {
      int tmp1 = Dlen + w + Slen;             // 위쪽으로 돌기
      int tmp2 = (h - Dlen) + w + (h - Slen); // 아래쪽으로 돌기
      dis += min(tmp1, tmp2);
    }
    // 3. 옆으로 붙어있는 쪽
    else
    {
      if (Ddir + Sdir == 4) // 북<->서
      {
        dis += (Dlen + Slen);
      }
      else if (Ddir + Sdir == 6) // 남<->동
      {
        if (Ddir == 2)
        {
          dis += ((w - Dlen) + (h - Slen));
        }
        else
        {
          dis += ((h - Dlen) + (w - Slen));
        }
      }
      else
      {
        if (Ddir == 3 || Ddir == 2) // 서<->남
        {
          if (Ddir == 3)
          {
            dis += ((h - Dlen) + Slen);
          }
          else
          {
            dis += (Dlen + (h - Slen));
          }
        }
        else // 동<->북
        {
          if (Ddir == 4)
          {
            dis += (Dlen + (w - Slen));
          }
          else
          {
            dis += ((w - Dlen) + Slen);
          }
        }
      }
    }
  }

  return dis;
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