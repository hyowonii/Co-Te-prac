#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef pair<int, int> pi;

int N;
vector<pi> v;
int mx[25];

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++) {
		int a, b;
		cin >> a >> b;
		v.push_back({ a, b });
	}
	///////////

	for (int i = 0; i < N; i++) {

		mx[i + v[i].first] = max(mx[i + v[i].first], mx[i] + v[i].second);
		mx[i + 1] = max(mx[i], mx[i + 1]);
		//cout << "mx[" << i + v[i].first << "]: " << mx[i + v[i].first] << "\n";
	}

	cout << mx[N];
}