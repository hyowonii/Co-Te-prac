#include <iostream>
#include <vector>
#include <algorithm>

# define MAX 1e12
using namespace std;
long n;

// 에라토스테네스의 체
vector<int> getPrime(long n) {

	vector<int> prime(n + 1);
	//모든 수를 소수라고 가정하고 i번째 인덱스에  i저장.
	for (long i = 2; i <= n; i++)
		prime[i] = i;

	for (long i = 2; i * i <= n; i++) {

		if (prime[i] == i) { //소수의 배수들만 지워야하므로

			for (long j = i * i; j <= n; j += i) {
				if (prime[j]== j) //아직 지워지지 않았을 경우에만 (소인수가 덮어써지는것 방지)
					prime[j] = i; //i의 배수로 지워졌음을 표시
			}

		}
	}

	vector <int> factor; //소인수

	while (n > 1) {
		factor.push_back(prime[n]);
		n = n / prime[n];
	}

	return factor;
}

//vector <int> factorization(long n, vector<int> prime) { // 소인수분해 - dp 역추적 
//
//	vector <int> factor; //소인수
//
//	while (n > 1) {
//		factor.push_back(prime[n]);
//		n = n / prime[n];
//	}
//
//	return factor;
//	
//}

void composition(vector <int> factor) { //합성수 분해

	
	long size = factor.size();
	if (size == 1) { //소인수가 하나라면

		cout << -1; // 합성수로 나타낼 수 없음.
		return;
	}
		
	else if (size % 2 == 0) { //짝수개라면 두개씩 묶어서 출력하기.

		for (long i = 0; i < factor.size(); i+=2) {
			cout << factor[i] * factor[i + 1]<<' ';
		}
		
	}
	else { //홀수개라면 두개씩 묶다가 마지막에 세개 출력
		for (long i = 0; i < factor.size()-3; i += 2) {
			cout << factor[i] * factor[i + 1] << ' ';
		}

		cout << factor[size-3] * factor[size - 2]* factor[size - 1];
	}

}

int main() {

	
	cin >> n;

	vector <int> factor = getPrime(n);
	//vector <int> factor = factorization(n, prime); //소인수분해 

	composition(factor);

}