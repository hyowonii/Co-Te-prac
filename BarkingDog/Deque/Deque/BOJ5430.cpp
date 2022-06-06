#include <iostream>
using namespace std;
#include <deque>
#include <algorithm>




void parse(string& s, deque<int>& DQ) {
	int cur = 0;
	for (int i = 1; i < s.size() - 1; i++) {
		if (s[i] == ',') {
			DQ.push_back(cur);
			cur = 0;
		}
		else {
			cur = 10 * cur + (s[i] - '0');
		}
	}
	if (cur != 0) DQ.push_back(cur);
}

void print(deque<int>& DQ) {
	/*cout << '[';
	while (DQ.size() > 1) {
		cout << DQ.front() << ',';
		DQ.pop_front();
	}
	cout << DQ.front() << "]\n";*/	//DQ가 []일 때 오류
	cout << '[';
	for (int i = 0; i < DQ.size(); i++)
	{
		cout << DQ[i];
		if (i + 1 != DQ.size())
			cout << ',';
	}
	cout << "]\n";
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T;
	cin >> T;

	while (T--) {

		deque<int> DQ;

		// 수행 함수
		string p;
		cin >> p;
		// 배열 개수
		int n;
		cin >> n;
		// 배열
		string s;
		cin >> s;
		parse(s, DQ);

		int rev = 0;	// 0: no reverse / 1: reverse
		bool isWrong = false;
		for (char c : p) {
			if (c == 'R') {
				rev = 1 - rev;
			}
			else {
				if (DQ.empty()) {
					isWrong = true;
					break;
				}
				if (!rev) DQ.pop_front();
				else DQ.pop_back();
			}
		}
		if (isWrong) cout << "error\n";
		else {
			if(rev) reverse(DQ.begin(), DQ.end());
			print(DQ);
		}
	}
	
}