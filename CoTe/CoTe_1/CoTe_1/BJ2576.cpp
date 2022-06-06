#include <iostream>
#include <algorithm>

using namespace std;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n[7];
	cin >> n[0] >> n[1] >> n[2] >> n[3] >> n[4] >> n[5] >> n[6];

	int sum = 0;
	int min = 100;
	for (int i = 0; i < 7; i++) {
		if (n[i] % 2 == 1) {
			sum += n[i];
			if (n[i] < min) min = n[i];
		}
	}

	if (sum == 0) cout << -1;
	else cout << sum << '\n' << min;
	
}