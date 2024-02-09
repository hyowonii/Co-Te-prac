/*
  정올 [동전 자판기]
  https://jungol.co.kr/problem/1183
  greedy
*/

#include <iostream>
using namespace std;
int W; // 사용할 금액
int coin[6] = {500, 100, 50, 10, 5, 1};
int A[6];   // 각 동전 개수(갖고 있는)
int sol[6]; // 답

void InputData()
{
  cin >> W;
  for (int i = 0; i < 6; i++)
  {
    cin >> A[i];
  }
}
void OutputData(int ans)
{
  cout << ans << "\n";
  for (int i = 0; i < 6; i++)
  {
    cout << A[i] << " ";
  }
  cout << "\n";
}

int Solve()
{
  // greedy

  // 내가 가진 돈 및 동전
  int totalSum = 0, totalCoin = 0;
  for (int i = 0; i < 6; i++)
  {
    totalSum += A[i] * coin[i];
    totalCoin += A[i];
  }

  int have = totalSum - W;
  int cur = 0;
  for (int i = 0; i < 6; i++)
  {
    int mxUse = min(A[i], (have - cur) / coin[i]); // 최대 사용 가능한 개수
    A[i] -= mxUse;
    // cout << A[i] << "\n";
    // sol[i] = mxUse;
    cur += coin[i] * mxUse;
    totalCoin -= mxUse;

    if (cur == have)
      break;
  }

  return totalCoin;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int ans = -1;

  InputData(); // 입력받는 부분

  // 여기서부터 작성
  ans = Solve();

  OutputData(ans); // 출력하는 부분
  return 0;
}