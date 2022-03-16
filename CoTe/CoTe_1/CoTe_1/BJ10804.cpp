#include <iostream>

using namespace std;
/*
int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int num[20];
	for (int i = 0; i < 20; i++) num[i] = i + 1;

	int t[10][2];
	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 2; j++)
			cin >> t[i][j];

	for (int i = 0; i < 10; i++) {
		int s = t[i][0];
		int e = t[i][1];
		for (int j = s-1, k = e-1; j < k; j++, k--) {
			swap(num[j], num[k]);
		}
	}

	for (int i = 0; i < 20; i++) cout << num[i] << ' ';
}
*/

int num[21];

/*
// 카드를 역순으로 놓는 함수
void reverse(int a, int b) {
	for (int i = 0; i < (b - a + 1) / 2; i++)
		swap(num[a + i], num[b - i]);
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	for (int i = 1; i <= 20; i++) num[i] = i;

	for (int i = 1; i <= 10; i++) {
		int a, b;
		cin >> a >> b;
		reverse(a, b);
	}

	for (int i = 1; i <= 20; i++) cout << num[i] << ' ';
}
*/

// STL reverse 이용한 풀이
int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	for (int i = 1; i <= 20; i++) num[i] = i;

	for (int i = 1; i <= 10; i++) {
		int a, b;
		cin >> a >> b;
		reverse(num + a, num + b + 1);
	}

	for (int i = 1; i <= 20; i++) cout << num[i] << ' ';
}