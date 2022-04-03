#include <iostream>
#include <vector>

using namespace std;

int N;

int counting(int cntE) {
	return pow(2, cntE) - 1 - cntE;
}

//WHEWHEE
void findWHEE(string whee) {
	long long cnt = 0;
	for (int i = whee.size() - 1; i >= 0; i--) {
		if (whee[i] == 'E') {
			int cntE = 1;
			for (int j = i - 1; j >= 0; j--) {
				if (whee[j] == 'E') {
					cntE++;
					for (int k = j - 1; k >= 0; k--) {
						if (whee[k] == 'H') {
							for (int l = k - 1; l >= 0; l--) {
								if (whee[l] == 'W') {
									cout << cntE << "\n";
									cnt += counting(cntE) % 1000000007;
									cout << "-" << counting(cntE) << "\n";
									cnt % 1000000007;
								}
							}
						}
					}
				}
			}
		}
	}
	cout << cnt % 1000000007;
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	string whistle;
	cin >> whistle;
	
	findWHEE(whistle);
}