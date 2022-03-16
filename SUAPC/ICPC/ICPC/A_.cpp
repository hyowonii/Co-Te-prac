#include <iostream>
using namespace std;
#include <algorithm>

#define MAX 200000

int N, M;
int g[MAX][2];

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;

	for (int i = 0 < i < M; i++) {
		int from, to;
		cin >> from >> to;

		g[i][0] = from;
		g[i][1] = to;
	}
	sort(g, g + M);


}