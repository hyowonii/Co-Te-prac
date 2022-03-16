#include <iostream>
#include <algorithm>

using namespace std;

/*
void eut(int A[])
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int ones = 0;
	int zeros = 0;
	for (int i = 0; i < 4; i++) {
		if (A[i] == 1) ones++;
		else zeros++;
	}

	if (zeros == 1) cout << 'A' << '\n';
	else if (zeros == 2) cout << 'B' << '\n';
	else if (zeros == 3) cout << 'C' << '\n';
	else if (zeros == 4) cout << 'D' << '\n';
	else cout << 'E' << '\n';
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int a[4];
	int b[4];
	int c[4];
	cin >> a[0] >> a[1] >> a[2] >> a[3];
	cin >> b[0] >> b[1] >> b[2] >> b[3];
	cin >> c[0] >> c[1] >> c[2] >> c[3];

	eut(a);
	eut(b);
	eut(c);

}*/

int result, input;
string res = "DCBAE";

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	for (int r = 0; r < 3; r++) {
		result = 0;
		for (int c = 0; c < 4; c++) {
			cin >> input;
			result += input;
		}
		cout << res[result] << '\n';
	}
}