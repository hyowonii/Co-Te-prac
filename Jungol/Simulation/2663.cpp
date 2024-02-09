/*
  정올 [폭탄 돌리기]
  https://jungol.co.kr/problem/2663
  구현
*/

// 변수1 : 가진 사람. (k + n) % 8
// 변수2 : 현재 시간. 총 시간이 210~211 사이면 정답
// T => 1. 시간 더하고 2. 다음 번호로 넘기기
// F or P => 시간만 더하고, 번호 넘기지 않음
// 모든 퀴즈가 끝나면 마지막 번호가 답

#include <iostream>
using namespace std;
#define MAXN (100)

int K;             // 처음 폭탄을 가진 사람 번호
int N;             // 퀴즈 개수
int T[MAXN + 10];  // 걸린 시간
char Z[MAXN + 10]; // 정답 여부

int curtime = 0;

void InputData()
{
  cin >> K;
  cin >> N;
  for (int i = 0; i < N; i++)
  {
    cin >> T[i] >> Z[i];
  }
}

int main()
{
  int ans = -1;
  InputData(); // 입력받는 부분

  // 여기서부터 작성
  for (int i = 0; i < N; i++)
  {
    curtime += T[i];
    if (curtime > 210)
    {

      break;
    }
    if (Z[i] == 'T')
    {
      K = (K + 1) % 8;
    }
  }
  ans = (K == 0) ? 8 : K;

  cout << ans << endl; // 출력하는 부분
  return 0;
}