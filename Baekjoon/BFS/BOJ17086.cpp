/*
	���� [�Ʊ� ���2]
	https://www.acmicpc.net/problem/17086
	���Ʈ����
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
int safe[52][52];	// �����Ÿ� ����
vector<pair<int, int>> shark;	// ��� ��ġ

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
			if (find(shark.begin(), shark.end(), p) != shark.end()) {	// ���
				safe[i][j] = -1;
				continue;	
			}

			int sf = 1e9;	// �����Ÿ�
			for (auto s : shark) {

				int dis = 1e9;	// ������ �Ÿ�

				int mn;	// �밢�� �̵� Ƚ��
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