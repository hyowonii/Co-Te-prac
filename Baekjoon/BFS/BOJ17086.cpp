/*
	백준 [아기 상어2]
	https://www.acmicpc.net/problem/17086
	브루트포스
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
int safe[52][52];	// 안전거리 저장
vector<pair<int, int>> shark;	// 상어 위치

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			int p;
			cin >> p;
			if (p == 1) shark.push_back({ i,j });
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			pair<int, int> p = make_pair(i, j);	
			if (find(shark.begin(), shark.end(), p) != shark.end()) {	// 상어
				safe[i][j] = -1;
				continue;	
			}

			int sf = 1e9;	// 안전거리
			for (auto s : shark) {

				int dis = 1e9;	// 상어와의 거리

				int mn;	// 대각선 이동 횟수
				if (abs(i - s.first) < abs(j - s.second)) {
					mn = abs(i - s.first);
					dis = mn + abs(j - s.second) - mn;
				}
				else {
					mn = abs(j - s.second);
					dis = mn + abs(i - s.first) - mn;
				}

				sf = min(sf, dis);
			}

			safe[i][j] = sf;
		}
	}

	int result = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			result = max(result, safe[i][j]);
		}
	}

	cout << result;
}