/*
  정올 [Uniqueness]
  https://jungol.co.kr/problem/1133
  문자열
*/

#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int N;
char S[10000 + 10][20 + 10];

unordered_map<string, vector<int>> m;

void InputData()
{
  cin >> N;
  for (int i = 1; i <= N; i++)
  {
    cin >> S[i];
    m[S[i]].push_back(i);
  }
}

void Solve()
{
  bool isUnique = true;
  for (int i = 1; i <= N; i++)
  {
    string str = S[i];

    if (m[str].size() > 1)
    {
      isUnique = false;
      cout << str << " ";
      for (auto num : m[str])
        cout << num << " ";
      cout << "\n";
    }
    m[str].clear();
  }

  if (isUnique)
    cout << "unique\n";
}

int main()
{
  InputData(); // 입력받는 부분

  // 여기서부터 작성
  Solve();

  return 0;
}