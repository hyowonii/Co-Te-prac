#include <iostream>
#include <algorithm>
using namespace std;

int N;
int c[500002];
int result = 1;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++) cin >> c[i];
	sort(c, c + N);
	
	int cnt = 1;
	for(int i=0;i<N-1;i++){
		if (c[i] == c[i + 1]) {
			cnt++;
			result = max(result, cnt);
		}
		else {
			cnt = 1;
		}
	}

	cout << result;
}