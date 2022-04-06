#include <iostream>

using namespace std;

int paper[3000][3000];
int mone = 0;
int zero = 0;
int one = 0;

void count(int a, int b) {
	if (paper[a][b] == -1) mone++;
	else if (paper[a][b] == 0) zero++;
	else one++;
}

void findPaper(int n, int a, int b) {
	if (n == 1) {
		count(a, b);
		return;
	}

	int num = paper[a][b];	// �������� ���� ����(-1, 0, 1)
	bool tf = true;		// �迭�� ��� ���� ���� �̷�����ִ��� �Ǵ�
	for (int i = a; i < a + n; i++) {	// ���������� �迭�� ���� ���� �Ʒ����� ���� Ž��
		for (int j = b; j < b + n; j++) {
			if (paper[i][j] == num) continue;
			else {		// �迭�� ��� ���� ���� �̷�������� ����
				tf = false;
				break;
			}
		}
	}
	if (tf) {	// �迭�� ��� ���� ���� �̷�����־� tf�� ���� true�� ������
		count(a, b);	// ���� ���� �����ϴ� �޼ҵ�
		return;
	}

	// n/3
	// ������(9��): (a, b), (a+(n/3),b), (a+2(n/3),b), (a,b+(n/3)), (a+(n/3),b+(n/3)), (a+2(n/3),b+(n/3)), (a,b+2(n/3)), (a+(n/3),b+2(n/3)), (a+2(n/3),b+2(n/3)) 
	for (int k = 0; k < 3; k++) {
		for (int l = 0; l < 3; l++) {
			findPaper(n / 3, a + k * (n / 3), b + l * (n / 3));
		}
	}
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;

	for (int i = 0; i < N; i++) 
		for (int j = 0; j < N; j++)
			cin >> paper[i][j];
	
	findPaper(N, 0, 0);

	cout << mone << "\n" << zero << "\n" << one;
}