#include <iostream>
using namespace std;
#include <list>

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	list<char> List;
	
	string str;
	cin >> str;	// 문자열
	for (auto c : str) List.push_back(c);
	auto cursor = List.end();

	int M;
	cin >> M;	// 명령어 개수

	while (M--) {
		char order;
		cin >> order;

		if (order == 'L') {
			if (cursor != List.begin()) cursor--;
		}
		else if (order == 'D') {
			if (cursor != List.end()) cursor++;
		}
		else if (order == 'B') {
			if (cursor != List.begin()) {
				cursor--;
				cursor = List.erase(cursor);
			}
		}
		else {
			char val;
			cin >> val;
			List.insert(cursor, val);
		}
	}

	for (auto c : List) cout << c;

}