#include <iostream>

using namespace std;


int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T;
	cin >> T;

	while (T--) {
		int N;
		cin >> N;
		long long num[100];
		for (int i = 0; i < N; i++) cin >> num[i];

		int append = 0;

		for (int i = 1; i < N; i++) {
			if (num[i - 1] < num[i]) continue;
			while (num[i - 1] >= num[i]) {
				if (num[i - 1] == num[i]) {
					if(num[i-1])
				}
				num[i] = num[i] * 10 + 9;
				append++;
			}
		}

		cout << append << "\n";
	}
}