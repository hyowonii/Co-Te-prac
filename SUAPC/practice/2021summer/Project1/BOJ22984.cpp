#include <iostream>
using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;
	double p[100002];

	for (int i = 0; i < N; i++) cin >> p[i];

	double total = 0;
	for (int i = 0; i + 1 < N; i++) {
		total += p[i];
		total += p[i] * (1 - p[i + 1]) + (1 - p[i]) * p[i + 1];
	}
	total += p[N - 1];
	
	cout << fixed;
	cout.precision(6);
	cout << total;
}