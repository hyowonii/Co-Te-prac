#include <iostream>
#include <queue>
using namespace std;

int N;
queue<int> Q;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> N;
	for (int i = 1; i < N+1; i++) {
		Q.push(i);
	}

	while (Q.size() > 1) {
		Q.pop();
		Q.push(Q.front());
		Q.pop();
	}
	cout << Q.front();
}