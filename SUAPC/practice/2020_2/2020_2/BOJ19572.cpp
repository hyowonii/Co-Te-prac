#include <iostream>
using namespace std;

int d1, d2, d3;
double a, b, c;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> d1 >> d2 >> d3;

	a = (double)(d1 + d2 - d3) / 2;
	b = (double)(d1 + d3 - d2) / 2;
	c = (double)(d2 + d3 - d1) / 2;

	if (a <= 0 || b <= 0 || c <= 0) {
		cout << -1;
		return 0;
	}
	else {
		cout << 1 << "\n";
		cout << fixed;
		cout.precision(1);
		cout << a << " " << b << " " << c;
	}

}