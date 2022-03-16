#include <iostream>
using namespace std;
#include <cmath>

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;

	int digit = 0;
	int num = N;
	while (num) {
		digit++;
		num /= 10;
	}

	// 시간초과 없으니까 이 부분은 없이 그냥 1부터 반복문 돌려도 됨
	int k = N - ((int)(N / (pow(10, digit-1))) + 9 * (digit - 1));
	if (k < 0) {
		cout << 0;
		return 0;
	}
	int result = 0;
	for (int i = k; i < N; i++) {
		result = i;
		for (int j = i; j > 0; j /= 10) {
			result += (j % 10);
		}
		if (result == N) {
			cout << i;
			return 0;
		}
	}

	cout << 0;
}