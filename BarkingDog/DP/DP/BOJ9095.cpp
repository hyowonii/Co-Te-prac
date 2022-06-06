#include <iostream>
using namespace std;

int T;
int D[15];

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	D[1] = 1;
	D[2] = 2;
	D[3] = 4;
	cin >> T;
	
	for (int i = 4; i <= 11; i++) {
		D[i] = D[i - 3] + D[i - 2] + D[i - 1];
	}
	
	while (T--) {
		int n;
		cin >> n;
		cout << D[n] << "\n";
	}
}