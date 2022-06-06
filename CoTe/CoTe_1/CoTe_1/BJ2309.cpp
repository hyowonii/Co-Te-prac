#include <iostream>
#include <algorithm>

using namespace std;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t[9];
	for (int i = 0; i < 9; i++) cin >> t[i];

	int total = 0;
	for (int i = 0; i < 9; i++) total += t[i];

	total -= 100;
	for (int i = 0; i < 9; i++) {
		for (int j = i + 1; j < 9; j++) {
			if (t[i] + t[j] == total) {
				t[i] = 0;
				t[j] = 0;
				sort(t, t + 9);
				for (int i = 2; i < 9; i++) cout << t[i] << '\n';
				return 0;
			}
		}
	}

	
}