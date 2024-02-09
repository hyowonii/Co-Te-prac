/*
  정올 [건물 세우기]
  https://jungol.co.kr/problem/1249
  dfs
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
#define MAXN (10)
int N;                       // 빌딩개수(장소개수)
int A[MAXN + 10][MAXN + 10]; //[빌딩][장소]=비용

vector<int> list;
int mnSum = 10005;

vector<int> result;

void InputData()
{
  cin >> N;
  for (int i = 1; i <= N; i++)
  {
    for (int j = 1; j <= N; j++)
    {
      cin >> A[i][j];
    }
  }
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int ans = -1;
  InputData(); // 입력

  // 여기서부터 작성
  int num = 1;
  for (int i = 1; i <= N; i++)
    list.push_back(i);
  do
  {
    vector<int> tmp;
    int sum = 0;
    for (int i = 1; i <= N; i++)
    {
      sum += A[i][list[i - 1]];
      // cout << list[i - 1] << " ";
      tmp.push_back(list[i - 1]);
    }
    // cout << "\n";
    if (sum < mnSum)
    {
      mnSum = sum;
      result.clear();
      result = tmp;
      tmp.clear();
    }

  } while (next_permutation(list.begin(), list.end()));

  cout << mnSum << "\n"; // 출력
  for (int i = 0; i < result.size(); i++)
    cout << result[i] << " ";

  return 0;
}

// dfs //////////////////////////////////////////////////////
#include <iostream>
using namespace std;
#define MAXN (10)
int N;                          // 빌딩개수(장소개수)
int cost[MAXN + 10][MAXN + 10]; //[빌딩][장소]=비용
int used[MAXN + 10];            // 장소사용여부
int path[MAXN + 10];            //[빌딩]=장소
int sol;                        // 최소비용
int solpath[MAXN + 10];         // 최소비용일경우(path배열 백업)
void DFS(int n, int sum)
{ // 빌딩인덱스, 총비용
  if (sol <= sum)
    return; // 가지치기, 중간 결과가 이전 답보다 안 좋음
  if (n > N)
  { // 종료조건
    sol = sum;
    for (int i = 1; i <= N; i++)
      solpath[i] = path[i];
    return;
  }
  for (int i = 1; i <= N; i++)
  { // 장소
    if (used[i] == 1)
      continue;  // i번 장소 이미 사용중
    used[i] = 1; // 사용표시
    path[n] = i; // n번 빌딩은 i장소에 지음
    DFS(n + 1, sum + cost[n][i]);
    used[i] = 0; // 표시제거
  }
}
int Solve()
{
  sol = 100 * MAXN + 10; // 최솟값 구하므로 최댓값으로 초기화
  DFS(1, 0);             // 빌딩인덱스, 총비용
  return sol;
}
void InputData()
{
  cin >> N;
  for (int i = 1; i <= N; i++)
  {
    for (int j = 1; j <= N; j++)
    {
      cin >> cost[i][j];
    }
  }
}
void OutputData(int sol)
{
  cout << sol << endl;
  for (int i = 1; i <= N; i++)
  {
    cout << solpath[i] << " ";
  }
  cout << endl;
}
int main()
{
  InputData();
  int ans = Solve();
  OutputData(ans);
  return 0;
}
