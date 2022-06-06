#include <iostream>
using namespace std;
#include <algorithm>

int s[302];
int d[302];	

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	int total = 0;
	for (int i = 1; i <= n; i++) {
		cin >> s[i];
		total += s[i];
	}

	if (n <= 2) {
		cout << total;
		return 0;
	}

	d[1] = s[1];
	d[2] = s[1] + s[2];
	d[3] = max(s[1], s[2]) + s[3];
	for (int i = 4; i <= n; i++) {
		d[i] = max(d[i - 2], d[i - 3] + s[i - 1]) + s[i];
	}

	cout << d[n];
}