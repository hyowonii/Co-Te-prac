#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	int P[1000];
	cin >> N;
	for (int i = 0; i < N; i++) cin >> P[i];

	sort(P, P + N);

	int result = 0;
	int i = 0;
	while (N) {
		result += (P[i] * N);
		i++;
		N--;
	}

	cout << result;
}