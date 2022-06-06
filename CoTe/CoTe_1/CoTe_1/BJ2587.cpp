#include <iostream>
#include <algorithm>

using namespace std;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int A[5];
	cin >> A[0] >> A[1] >> A[2] >> A[3] >> A[4];

	sort(A, A+5);

	cout << (A[0] + A[1] + A[2] + A[3] + A[4]) / 5 + (A[0] + A[1] + A[2] + A[3] + A[4]) % 5 << '\n';
	cout << A[2];
}