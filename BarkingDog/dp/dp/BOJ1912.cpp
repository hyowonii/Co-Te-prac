/*
	백준 [연속합]
	https://www.acmicpc.net/problem/1912
	dp
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int a[100010], d[100010];

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int num;
		cin >> a[i];
		d[i] = a[i];
	}

	for (int i = 1; i <= n; i++) {
		d[i] = max(d[i], d[i - 1] + a[i]);	// 연속 중 숫자 한 개 이상 선택 - 연속 수 합 누적 -> 그 중 가장 큰 값
	}

	cout << *max_element(d + 1, d + n + 1);
}
