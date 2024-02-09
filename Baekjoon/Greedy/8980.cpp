/*
  백준 [택배]
  https://www.acmicpc.net/problem/8980
  greedy
*/

// 최대한 앞에서 많이 내려야됨

#include <iostream>
#include <algorithm>
using namespace std;

int N; // 마을 수
int C; // 트럭 용량

int M;               // 박스 정보의 개수
int S[10000 + 10];   // 박스를 보내는 마을
int E[10000 + 10];   // 박스를 받는 마을
int NUM[10000 + 10]; // 배송 박스 개수

struct ST
{
  int from, to, amount;
};
ST boxes[10000 + 10]; // 박스 정보들

void InputData()
{
  cin >> N >> C;
  cin >> M;
  for (int i = 0; i < M; i++)
  {
    cin >> S[i] >> E[i] >> NUM[i];
    boxes[i] = {S[i], E[i], NUM[i]};
  }
}

bool comp(ST &a, ST &b)
{
  return a.to < b.to;
}

int Solve()
{
  int total = 0; // 총 택배 개수

  // 1. 정렬 (받는 마을이 가까운 순으로)
  sort(boxes, boxes + M, comp);

  // 2. 가까운 곳에 배달할 것부터 최대한 저장하기
  static int truck[10000 + 10] = {0};
  for (int i = 0; i < M; i++)
  {
    // i번째 마을에 배달할 수 있는 마을들 돌면서
    int portion = C;
    for (int j = boxes[i].from; j < boxes[i].to; j++)
    {
      portion = min(C - truck[j], portion);
    }
    int put = portion;
    if (portion > boxes[i].amount)
    {
      put = boxes[i].amount;
    }

    for (int j = boxes[i].from; j < boxes[i].to; j++)
      truck[j] += put;
    total += put;
  }

  return total;
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