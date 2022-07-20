/*
	백준 [빈도 정렬]
	https://www.acmicpc.net/problem/2910
	정렬
*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;
typedef long long ll;

vector<pair<int, int>> cnt;

bool comp(const pair<ll, ll>& a, const pair<ll, ll>& b) {
	return a.first > b.first;
}

void printfunc(int key, int value) {
	for (int j = 0; j < value; j++) {
		cout << key << " ";
	}
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, c;
	cin >> n >> c;
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		bool chk = false;
		for (auto& a : cnt) {
			if (a.second == num) {
				chk = true;
				a.first++;
				break;
			}
		}
		if (!chk) cnt.push_back({ 1,num });
	}

	stable_sort(cnt.begin(), cnt.end(), comp);

	for (auto el : cnt) {
		while (el.first--) cout << el.second << " ";
	}
}