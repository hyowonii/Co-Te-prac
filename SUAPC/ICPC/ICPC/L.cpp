#include <iostream>
using namespace std;
#include <string>

#define MAX 1001

int T;
long long stoneNum[MAX];

int maxPalindrom(long long n) {

	while (n--) {
		string s = to_string(n);
		int j = s.length();
		for (int i = 0; i < s.length() / 2; i++, j--) {
			if (s[i] != s[j]) break;
		}
	}
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> stoneNum[i];
	}


}