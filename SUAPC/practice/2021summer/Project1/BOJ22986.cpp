#include <iostream>
using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie();

	int T;
	cin >> T;
	while (T--) {
		long N;
		long K;
		cin >> N >> K;

		long total = 0;
		long no = N - K - 1 > 0 ? N - K - 1 : 0;

		total = N * (N + 1) / 2 - no * (no + 1) / 2;
		total *= 4; 

		cout << total << "\n";
	}
}