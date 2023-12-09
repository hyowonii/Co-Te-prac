/*
	���� [���ڿ� ��ȯ]
	https://www.acmicpc.net/problem/1522
	����, ���ڿ�
*/

#include <iostream>
#include <algorithm>

using namespace std;

string s;

int solve(string& s, int x, int len) {
	int ret = 0;
	for (int i = x; i < x + len; i++) {
		if (s[(i + 1) % s.length()] == 'a') ret++;
	}

	return ret;
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> s;

	// �߻��� �� �ִ� ��� ��� Ȯ��

	int cnt = 0;
	int ans = (int)1e9;

	for (int i = 0; i < s.length(); i++)
		if (s[i] == 'b') cnt++;

	for (int i = 0; i < s.length(); i++)
		ans = min(ans, solve(s, i, cnt));

	cout << ans;


	///// �ٸ� �ڵ�

	int a = 0;	// a ����
	int ans = s.size();

	for (auto c : s)
		if (c == 'a') a++;

	for (int i = 0; i < s.size(); i++) {
		int cnt = a;
		int temp = 0;
		for (int j = i; j < i + s.size(); j++) {
			if (cnt == 0) break;	// ��� a�� �������� ����
			if (s[j % s.size()] == 'b') {
				temp++;
				cnt--;
			}
			else cnt--;
		}

		ans = min(ans, temp);
	}

	cout << ans << "\n";
}

