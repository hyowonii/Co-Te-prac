/*
	백준 [조합 0의 개수]
	https://www.acmicpc.net/problem/2004
	math
*/

#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;

pair<ll, ll> count(ll num) {
	ll cnt5 = 0, cnt2 = 0;

	for (ll i = 5; i <= num; i *= 5) cnt5 += num / i;
	for (ll i = 2; i <= num; i *= 2) cnt2 += num / i;

	pair<ll, ll> rtn = { cnt5,cnt2 };
	return rtn;
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	ll n, m;
	cin >> n >> m;

	ll sub = n - m;

	pair<ll, ll> numerator = count(n);
	pair<ll, ll> denominator1 = count(n - m);
	pair<ll, ll> denominator2 = count(m);

	ll up = numerator.first - (denominator1.first + denominator2.first);
	ll down = numerator.second - (denominator1.second + denominator2.second);

	cout << min(up, down);
}


//25 24 23 22 21 20 19 18 17 16 15 14
//12 11 10 9 8 7 6 5 4 3 2 1