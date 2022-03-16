#include <iostream>
using namespace std;
#include <algorithm>
#include <vector>

int N;	// 개수
long long X;	// 총 용량
vector<long long> C;
int total = 0;	// 정답 용기 개수

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> X;
	for (int i = 0; i < N; i++) {
		long long k;
		cin >> k;
		if (k == X) {
			total++;
			continue;
		}
		C.push_back(k);
	}
	sort(C.begin(), C.end());

	int left = 0;
	int right = C.size() - 1;
	int remain = C.size();
	while (left < right) {
		
		long long sum = C[left] + C[right] + (double)X / 2;

		if (sum >= X) {
			total++;
			left++;
			right--;
			remain -= 2;
		}
		else {
			left++;
		}
	}
	
	if (remain >= 3) {
		total += (remain / 3);
	}
	cout << total;
}