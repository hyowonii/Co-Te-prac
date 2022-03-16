#include <iostream>
#include <vector>
using namespace std;

#define MOD 1000000
int sum[5002];

int solution(string s, int length) {
	
	sum[0] = 1;

	for (int i = 1; i < length; i++) {
		if (s[i] - '0' >= 1)
			sum[i] = (sum[i] + sum[i - 1]) % MOD;

		int temp = (s[i - 1] - '0') * 10 + (s[i] - '0');

		if (10 <= temp && temp < 27)
			sum[i] = (sum[i] + sum[i - 2]) % MOD;
	}

	return sum[length - 1];
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	string s;
	cin >> s;

	s = ' ' + s;
	int answer = solution(s, s.length());

	cout << answer;
	return 0;
}