#include <iostream>
using namespace std;
#include <algorithm>
#include <vector>
#include <map>

int L, C;
char s[20];

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> L >> C;
	for (int i = 0; i < C; i++) {
		cin >> s[i];
	}
	sort(s, s + C);
	
	vector<int> v(C);
	for (int i = L; i < C; i++) v[i] = 1;
	
	do {

		string ans;
		int aeiou = 0;
		for (int i = 0; i < C; i++) {
			if (v[i] == 0) {
				ans += s[i];
				if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') aeiou++;
			}
		}

		if (aeiou < 1 || L - aeiou < 2) continue;
		
		cout << ans << "\n";
		

	} while (next_permutation(v.begin(), v.end()));
}



