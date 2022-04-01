#include <iostream>

using namespace std;

int N;
long long result = 0;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;

	for (int i = 1; i <= N; i++) {
		result += (N / i) * i;
	}

	cout << result;
}