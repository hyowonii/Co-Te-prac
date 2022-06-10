/*
	백준 [문자열 교환]
	https://www.acmicpc.net/problem/1522
	수학, 문자열
*/

#include <iostream>
#include <algorithm>

using namespace std;

string s;

int solve(string& s, int x, int len) {
	int ret = 0;
	for (int i = x; i < x + len; i++) {
		if (s[(i + 1) % s.length()] == 'a') ret++;
	}

	return ret;
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> s;

	// 발생할 수 있는 모든 경우 확인

	int cnt = 0;
	int ans = (int)1e9;

	for (int i = 0; i < s.length(); i++)
		if (s[i] == 'b') cnt++;

	for (int i = 0; i < s.length(); i++)
		ans = min(ans, solve(s, i, cnt));

	cout << ans;
}