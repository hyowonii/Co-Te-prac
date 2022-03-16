#include <iostream>
#include <vector>
#include <algorithm>

# define MAX 1e12
using namespace std;
long n;

// �����佺�׳׽��� ü
vector<int> getPrime(long n) {

	vector<int> prime(n + 1);
	//��� ���� �Ҽ���� �����ϰ� i��° �ε�����  i����.
	for (long i = 2; i <= n; i++)
		prime[i] = i;

	for (long i = 2; i * i <= n; i++) {

		if (prime[i] == i) { //�Ҽ��� ����鸸 �������ϹǷ�

			for (long j = i * i; j <= n; j += i) {
				if (prime[j]== j) //���� �������� �ʾ��� ��쿡�� (���μ��� ��������°� ����)
					prime[j] = i; //i�� ����� ���������� ǥ��
			}

		}
	}

	vector <int> factor; //���μ�

	while (n > 1) {
		factor.push_back(prime[n]);
		n = n / prime[n];
	}

	return factor;
}

//vector <int> factorization(long n, vector<int> prime) { // ���μ����� - dp ������ 
//
//	vector <int> factor; //���μ�
//
//	while (n > 1) {
//		factor.push_back(prime[n]);
//		n = n / prime[n];
//	}
//
//	return factor;
//	
//}

void composition(vector <int> factor) { //�ռ��� ����

	
	long size = factor.size();
	if (size == 1) { //���μ��� �ϳ����

		cout << -1; // �ռ����� ��Ÿ�� �� ����.
		return;
	}
		
	else if (size % 2 == 0) { //¦������� �ΰ��� ��� ����ϱ�.

		for (long i = 0; i < factor.size(); i+=2) {
			cout << factor[i] * factor[i + 1]<<' ';
		}
		
	}
	else { //Ȧ������� �ΰ��� ���ٰ� �������� ���� ���
		for (long i = 0; i < factor.size()-3; i += 2) {
			cout << factor[i] * factor[i + 1] << ' ';
		}

		cout << factor[size-3] * factor[size - 2]* factor[size - 1];
	}

}

int main() {

	
	cin >> n;

	vector <int> factor = getPrime(n);
	//vector <int> factor = factorization(n, prime); //���μ����� 

	composition(factor);

}