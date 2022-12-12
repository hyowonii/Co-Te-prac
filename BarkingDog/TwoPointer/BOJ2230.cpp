/*
  백준 [수 고르기]
  https://www.acmicpc.net/problem/2230
  투포인터
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

vector<ll> A;
ll result = 10e9;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, m;
  cin >> n >> m;

  for(int i=0; i<n; i++) {
    ll num;
    cin >> num;
    A.push_back(num);
  }

  sort(A.begin(), A.end());

  int st, en=0;

  for(st=0; st<n; st++) {   // 하나의 st에서 가능한 en을 모두 돌고 en이 멈췄을 때 다시 st를 하나 증가시켜 동일한 동작을 반복하는 형태로 수행
    while(en < n && A[en] - A[st] < m) en++;
    if(en >= n) break;  // en이 범위를 벗어나면 그 때의 st 이상에서 en까지 중 m을 넘는 경우가 더 이상 없다는 뜻이므로 모두 멈춤
    result = min(result, A[en] - A[st]);
  }

/*
  for(st=0, en=0; st<A.size(); ) {
    if(A[en] - A[st] >= m) {
      result = min(result, A[en]-A[st]);
      st++;
    } else {
      if(en >= A.size()) st++;
      else en++;
    }
  }
*/

  cout << result;

}