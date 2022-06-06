#include <iostream>
using namespace std;

int N;
string s;
int result = 0;


int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	cin >> s;

	char ch[4] = { 'T', 'G', 'F', 'P' };
	for (int i = 0; i < 4; i++) {
		char c = ch[i];
		char c1 = s.find(c);
		char c2 = s.find(c, c1 + 1);
		char c3 = s.find(c, c2 + 1);

		if (c1 != NULL && c2 != NULL && c3 != NULL) {
			if ((c2 - c1) != (c3 - c2)) continue;

			int d = c2 - c1;
			if (s.substr(c1, d) == s.substr(c2, d) && s.substr(c1, d) == s.substr(c3, d)) result++;
		}

		
	}

	cout << result;
}