/*
	���� [�Ҽ����Ӹ����]
	https://www.acmicpc.net/problem/1990
	����
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


	// �ð��ʰ� �ڵ�

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

	// �Ҽ����� & �Ӹ��������
	for (int num = a; num <= 10000000; num++) {		// 1���� 1����� �� �Ҽ�&�Ӹ������ ���� ��� ����غ��� 10000000�� ���� ����
		if (num > b) break;
		if(isPalindrome(to_string(num)) && isPrime(num))	// isPalindrome�� ���� üũ�ؾ� �ð��ʰ�X
			cout << num << "\n";

	}

	cout << -1;

	return 0;
}