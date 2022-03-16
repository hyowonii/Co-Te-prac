#include <iostream>
#include <cmath>
using namespace std;

int N, x;
int c[1000002][2];
long long result;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> x;
	for (int i = 0; i <= N; i++) {
		int A, d;
		cin >> A >> d;
		c[i][1] = A;
	}

	result = c[0][1];
	for (int i = 0; i < N; i++) {
		result = (long long)x * result + c[i + 1][1];
		result = result % int(1e9 + 7);
	}

	cout << result;
}