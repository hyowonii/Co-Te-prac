/*
  백준 [한국이 그리울 땐 서버에 접속하지]
  https://www.acmicpc.net/problem/9996
  문자열
*/

#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
  cin.tie(0); cout.tie(0);
  ios::sync_with_stdio(0);

  int n;
  string patern, left, right;
  cin >> n >> patern;

  left = patern.substr(0, 0 + patern.find("*"));
  right = patern.substr(patern.find("*") + 1, patern.size());

  while (n--)
  {
    string s;
    cin >> s;
    bool check = false;

    if (patern.size() - 1 > s.size())
    {
      cout << "NE\n";
    }
    else
    {
      for (int i = 0; i < left.size(); i++)
      {
        if (left[i] != s[i])
        {
          check = true;
          break;
        }
      }
      if (!check) // ****
      {
        for (int i = 0; i < right.size(); i++)
        {
          if (right[i] != s[s.size() - right.size() + i])
          {
            check = true;
            break;
          }
        }
      }
      if (!check)
      {
        cout << "DA\n";
      }
      else
      {
        cout << "NE\n";
      }
    }
  }
  return 0;
}