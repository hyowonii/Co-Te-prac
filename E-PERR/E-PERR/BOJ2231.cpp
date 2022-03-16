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

	// �ð��ʰ� �����ϱ� �� �κ��� ���� �׳� 1���� �ݺ��� ������ ��
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