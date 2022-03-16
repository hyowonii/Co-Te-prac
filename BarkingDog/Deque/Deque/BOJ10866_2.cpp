#include <iostream>
using namespace std;

const int MAX = 10000;
int dq[MAX];
int head, tail;

void push_front(int val) {
	dq[--head] = val;
}

void push_back(int val) {
	dq[++tail] = val;
}

int pop_front() {
	int pf = dq[head];
	head++;
	return pf;
}

int pop_back() {
	int pb = dq[tail];
	tail--;
	return pb;
}

int size() {
	return tail - head + 1;
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;

	head = MAX/2;
	tail = MAX/2 - 1;

	while (N--) {
		string order;
		cin >> order;

		if (order == "push_front") {
			int val;
			cin >> val;
			push_front(val);
		}
		else if (order == "push_back") {
			int val;
			cin >> val;
			push_back(val);
		}
		else if (order == "pop_front") {
			if (size() == 0) cout << -1 << "\n";
			else cout << pop_front() << "\n";
		}
		else if (order == "pop_back") {
			if (size() == 0) cout << -1 << "\n";
			else cout << pop_back() << "\n";
		}
		else if (order == "size") {
			cout << size() << "\n";
		}
		else if (order == "empty") {
			if (size() == 0) cout << 1 << "\n";
			else cout << 0 << "\n";
		}
		else if (order == "front") {
			if (size() == 0) cout << -1 << "\n";
			else cout << dq[head] << "\n";
		}
		else if (order == "back") {
			if (size() == 0) cout << -1 << "\n";
			else cout << dq[tail] << "\n";
		}
	}
}