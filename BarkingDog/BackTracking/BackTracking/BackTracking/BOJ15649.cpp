#include <iostream>

using namespace std;

int N, M;
int arr[10];
bool isused[10];

void func(int k) {	// 현재 k개까지 수를 택했음

	if (k == M) {	// M개를 모두 택했으면
		for (int i = 0; i < M; i++) cout << arr[i] << ' ';
		cout << "\n";
		return;
	}

	for (int i = 1; i <= N; i++) {	
		if (!isused[i]) {	// 아직 i가 사용되지 않았으면
			arr[k] = i;	// k번째 수를 i로 
			isused[i] = 1;	// i를 사용되었다고 표시
			func(k + 1);
			isused[i] = 0;	// k번째 수를 i로 정한 모든 경우에 대해 다 확인했으므로 이제 i를 사용되지 않았다고 명시
		}
	}
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;

	func(0);
}