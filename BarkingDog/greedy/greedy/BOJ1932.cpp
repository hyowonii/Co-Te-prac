/*
	백준 [정수 삼각형]
	https://www.acmicpc.net/problem/1932
	dp
*/

#include <iostream>
#include <algorithm>
using namespace std;

int triangle[502][502];
int sum[502][502];
int answer = 0;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			cin >> triangle[i][j];
			sum[i][j] = max(triangle[i][j] + sum[i - 1][j - 1], triangle[i][j] + sum[i - 1][j]);
			answer = max(answer, sum[i][j]);
		}
	}

	cout << answer;
}