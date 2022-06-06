#include <iostream>
using namespace std;
#include <stack>

stack<char> st;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T;
	cin >> T;
	while (T--) {

		string s;
		cin >> s;

		for (int i = 0; i < s.size(); i++) {
			
			if (s[i] == '(') st.push(s[i]);
			else if (s[i] == ')') {
				if (st.empty()) {
					st.push('f');
					break;
				}
				else
					st.pop();
			}
			else continue;
		}

		if (st.empty()) cout << "YES" << "\n";
		else cout << "NO" << "\n";

		while(!st.empty()) st.pop();
	}
}