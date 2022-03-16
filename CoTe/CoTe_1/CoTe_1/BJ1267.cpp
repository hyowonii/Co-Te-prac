#include <iostream>

using namespace std;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;
	int t[20];
	for (int i = 0; i < N; i++) cin >> t[i];
	
	int Y = 0;
	for (int i = 0; i < N; i++) {
		Y += (t[i] / 30 + 1) * 10;
	}

	int M = 0;
	for (int i = 0; i < N; i++) {
		M += (t[i] / 60 + 1) * 15;
	}

	if (Y < M) cout << 'Y' << ' ' << Y;
	else if (Y > M) cout << 'M' << ' ' << M;
	else cout << "Y M" << ' ' << Y;
}