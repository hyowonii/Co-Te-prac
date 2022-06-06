#include <iostream>
using namespace std;
#include <algorithm>
#include <vector>

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	while (true) {
		int k;
		cin >> k;
		if (k == 0) return 0;
		int num[15];
		for (int i = 0; i < k; i++) cin >> num[i];

		vector<int> v;
		for (int i = 0; i < k; i++) {
			v.push_back((i < 6) ? 0 : 1);
		}

		do {

			for (int i = 0; i < k; i++) {
				if (v[i] == 0) cout << num[i] << " ";
			}
			cout << "\n";

		} while (next_permutation(v.begin(), v.end()));

		cout << "\n";
	}
}