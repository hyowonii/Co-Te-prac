#include <iostream>

using namespace std;

const int MAX = 1000000;
int dat[MAX];
int head, tail;

void push(int x) {
	dat[tail++] = x;
}

void pop() {
	head++;
}

int size() {
	return tail - head;
}

int empty() {
	if (head >= tail) return 1;
	else return 0;
}

int front() {
	return dat[head];
}

int back() {
	return dat[tail-1];
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int cnt;
	cin >> cnt;

	while (cnt--) {
		string order;
		cin >> order;

		if (order == "push") {
			int value;
			cin >> value;
			push(value);
		}
		else if (order == "pop") {
			if (head == tail)
				cout << -1 << "\n";
			else {
				cout << front() << "\n";
				pop();
			}
		}
		else if (order == "size") {
			cout << size() << "\n";
		}
		else if (order == "empty") {
			cout << empty() << "\n";
		}
		else if (order == "front") {
			if (head == tail) cout << -1 << "\n";
			else cout << front() << "\n";
		}
		else if (order == "back") {
			if (head == tail) cout << -1 << "\n";
			else cout << back() << "\n";
		}
	}
}
