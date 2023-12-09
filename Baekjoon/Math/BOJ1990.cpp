/*
	백준 [소수인팰린드롬]
	https://www.acmicpc.net/problem/1990
	수학
*/

#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;


bool isPrime(int num) {
	if (num < 2) return false;

	for (int i = 2; i <= sqrt(num); i++) {
		if (num % i == 0) return false;
	}
	return true;
}

bool isPalindrome(string num) {

	string numstr = num;
	reverse(num.begin(), num.end());
	string numstr_rev = num;

	if (numstr == numstr_rev) return true;
	else return false;


	// 시간초과 코드

	//int st = 0, en = numstr.length() - 1;

	//while (st < en) {
	//	//if (st >= en) break;
	//	if (numstr[st] != numstr[en]) return false;
	//	st += 1; en -= 1;
	//}

	//return true;
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int a, b;
	cin >> a >> b;

	// 소수인지 & 팰린드롬인지
	for (int num = a; num <= 10000000; num++) {		// 1부터 1억까지 중 소수&팰린드롬인 수를 모두 출력해보면 10000000를 넘지 않음
		if (num > b) break;
		if(isPalindrome(to_string(num)) && isPrime(num))	// isPalindrome을 먼저 체크해야 시간초과X
			cout << num << "\n";

	}

	cout << -1;

	return 0;
}