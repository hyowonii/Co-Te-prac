#include <iostream>
#include <algorithm>
using namespace std;
#include <deque>

deque<int> DQ;
int cnt = 0;

void getFront() {
	DQ.pop_front();
}

void moveLeft() {
	int f = DQ.front();
	DQ.pop_front();
	DQ.push_back(f);
	cnt++;
}

void moveRight() {
	int b = DQ.back();
	DQ.pop_back();
	DQ.push_front(b);
	cnt++;
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, M;
	cin >> N >> M;
	for (int i = 1; i < N + 1; i++) DQ.push_back(i);

	while (M--) {
		int num;
		cin >> num;
		int idx = find(DQ.begin(), DQ.end(), num) - DQ.begin();

		while (num != DQ.front()) {
			if (idx <= DQ.size() / 2) {
				moveLeft();
			}
			else {
				moveRight();
			}
		}
		getFront();
	}

	cout << cnt;
	

}