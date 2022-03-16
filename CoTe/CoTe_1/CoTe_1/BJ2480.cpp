#include <iostream>
#include <algorithm>

using namespace std;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int prize;
	int a, b, c;
	cin >> a >> b >> c;

	if (a == b && a == c) {
		prize = 10000 + a * 1000;
	}
	else if (a != b && a != c && b != c) {
		prize = max({ a,b,c }) * 100;
	}
	else {
		if (a != b) prize = 1000 + c * 100;
		else if (a != c) prize = 1000 + b * 100;
		else prize = 1000 + a * 100;
	}

	cout << prize;
}