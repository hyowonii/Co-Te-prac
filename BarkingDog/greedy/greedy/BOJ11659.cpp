/*
	백준 [구간 합 구하기 4]
	https://www.acmicpc.net/problem/11659
	dp
*/

#include <iostream>
#include <vector>
using namespace std;

int a[100002];
vector<pair<int, int>> v;
long long sum[100002] = { 0 };

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		sum[i] = sum[i - 1] + a[i];
	}
	for (int i = 0; i < m; i++) {
		int s, e;
		cin >> s >> e;
		v.push_back({ s,e });
	}

	for (int i = 0; i < m; i++) {
		int s = v[i].first;
		int e = v[i].second;

		cout << sum[e] - sum[s - 1] << "\n";
	}
}