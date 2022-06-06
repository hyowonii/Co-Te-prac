#include <iostream>
using namespace std;
#include <deque>

deque<int> DQ;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;

	while (N--) {
		string order;
		cin >> order;

		if (order == "push_front") {
			int val;
			cin >> val;
			DQ.push_front(val);
		}
		else if (order == "push_back") {
			int val;
			cin >> val;
			DQ.push_back(val);
		}
		else if (order == "pop_front") {
			if (DQ.size() == 0) cout << -1 << "\n";
			else {
				cout << DQ.front() << "\n";
				DQ.pop_front();
			}
		}
		else if (order == "pop_back") {
			if (DQ.size() == 0) cout << -1 << "\n";
			else {
				cout << DQ.back() << "\n";
				DQ.pop_back();
			}
		}
		else if (order == "size") {
			cout << DQ.size() << "\n";
		}
		else if (order == "empty") {
			if (DQ.empty()) cout << 1 << "\n";
			else cout << 0 << "\n";
		}
		else if (order == "front") {
			if (DQ.size() == 0) cout << -1 << "\n";
			else cout << DQ.front() << "\n";
		}
		else if (order == "back") {
			if (DQ.size() == 0) cout << -1 << "\n";
			else cout << DQ.back() << "\n";
		}
	}
}