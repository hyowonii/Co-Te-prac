#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

typedef pair<int, int> pi;

int N, M;
vector<pi> house;
vector<pi> chicken;
vector<vector<pi>> selected;
int result = 1e9;

vector<pi> one_pack;
void Combination(int k) {

	if (one_pack.size() == M) {
		selected.push_back(one_pack);
	}
	else if (k == chicken.size()) {  }
	else {
		one_pack.push_back(chicken[k]);
		Combination(k + 1);
		one_pack.pop_back();
		Combination(k + 1);
	}
}

int Distance(pi h, vector<pi> pack) {
	int minDis = 1e9;
	
	for (auto p : pack) {
		int dis = abs(h.first - p.first) + abs(h.second - p.second);
		minDis = min(minDis, dis);
	}

	return minDis;
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	// ют╥б
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int num;
			cin >> num;
			if (num == 1) house.push_back({ i, j });
			if (num == 2) chicken.push_back({ i, j });
		}
	}
	// 

	Combination(0);

	for (auto pack : selected) {
		int disSum = 0;

		for (auto h : house) {
			disSum += Distance(h, pack);
		}

		result = min(result, disSum);
	}

	cout << result;
}