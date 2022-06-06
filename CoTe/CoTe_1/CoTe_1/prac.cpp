#include <iostream>

using namespace std;

void SwapV(int a, int b)	// Call-by-Value
{							// �ܺ� �� ���� �Ұ���
	int temp = a;
	a = b;
	b = temp;
}

void SwapR(int &a, int &b)	// Call-by-Reference
{							// �ܺ� �� ���� ����	
	int temp = a;
	a = b;
	b = temp;
}

int main(void)
{
	int n1 = 5;
	int n2 = 10;
	int n3 = 1;
	int n4 = 2;

	SwapV(n1, n2);
	SwapR(n3, n4);

	cout << n1 << '\n' << n2 << '\n';
	cout << n3 << '\n' << n4 << '\n';
}