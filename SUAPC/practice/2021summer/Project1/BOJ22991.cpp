#include <iostream>
using namespace std;
#include <algorithm>
#include <vector>
#include <map>

int N, M;
vector<pair<long, long>> v, b;
map<long, long> m;
int result = 0;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		long a, b;
		cin >> a >> b;
		v.push_back({ a, b });
	}
	for (int i = 0; i < M; i++) {
		long c, d;
		cin >> c >> d;
		b.push_back({ c,d });
	}

	sort(v.begin(), v.end(), greater<>());
	sort(b.begin(), b.end(), greater<>());

	int p1 = 0;
	int p2 = 0;
	for (int p1 = 0; p1 < N; p1++) {
		for (int p2 = 0; p2 < M; p2++) {
			if ((v[p1].first <= b[p2].first) && (v[p1].second >= b[p2].second)) {
				m.insert(b[p2]);				
			}
		}
	}
	cout << m.size();
}

// 요청 (7, 4) (4, 3)
// 버스 (8, 3) (5, 2)