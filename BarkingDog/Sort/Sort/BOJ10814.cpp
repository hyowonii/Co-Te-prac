/*
	백준 [나이순 정렬]
	https://www.acmicpc.net/problem/10814
	정렬
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<int, int>> v;
string member[100002];

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T;
	cin >> T;
	for (int i = 0; i < T; i++) {
		int age;
		string name;
		cin >> age >> name;
		v.push_back({ age, i });
		member[i] = name;
	}

	sort(v.begin(), v.end());

	for (int i = 0; i < v.size(); i++) {
		cout << v[i].first << " " << member[v[i].second] <<"\n";
	}
}