#include <iostream>
using namespace std;
#include <algorithm>
#include <math.h>

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	long long K;
	long v[200000];
	cin >> N >> K;
	for (int i = 0; i < N; i++) cin >> v[i];
	sort(v, v + N);

	long long mx = 0;
	for (int i = 1; i < N; i++) {
		long long nmax = v[0] * (i) + v[i] * (N - i);
		mx = max(mx, nmax);
	}

	cout << ((K + mx - 1) / mx);
}