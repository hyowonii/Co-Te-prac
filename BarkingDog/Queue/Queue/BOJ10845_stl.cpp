#include <iostream>
#include <queue>
using namespace std;

int main(void) 
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	queue<int> Q;
	int cnt;
	cin >> cnt;

	while (cnt--) {
		string order;
		cin >> order;

		if (order == "push") {
			int value;
			cin >> value;
			Q.push(value);
		}
		else if (order == "pop") {
			if (Q.empty())
				cout << -1 << "\n";
			else {
				cout << Q.front() << "\n";
				Q.pop();
			}
		}
		else if (order == "size") {
			cout << Q.size() << "\n";
		}
		else if (order == "empty") {
			cout << Q.empty() << "\n";
		}
		else if (order == "front") {
			if (Q.empty()) cout << -1 << "\n";
			else cout << Q.front() << "\n";
		}
		else if (order == "back") {
			if (Q.empty()) cout << -1 << "\n";
			else cout << Q.back() << "\n";
		}
	}
}