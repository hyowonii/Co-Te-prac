#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

#define INF 1e6
int board[201][201];

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    int answer = 0;

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            board[i][j] = INF;

    for (int i = 1; i <= n; i++) board[i][i] = 0;

    for (auto v : fares) {
        board[v[0]][v[1]] = v[2];
        board[v[1]][v[0]] = v[2];
    }

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            for (int k = 1; k <= n; k++)
                board[j][k] = min(board[j][k], board[j][i] + board[i][k]);

    answer = 1e9;
    for (int i = 1; i <= n; i++) {
        answer = min(answer, board[s][i] + board[i][a] + board[i][b]);
    }

    return answer;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int i;
    cout << "fares За: ";
    cin >> i;

    int n, s, a, b, u, v, w;
    cin >> n >> s >> a >> b;

    vector<vector<int>> fares;
    while (i--) {
        cin >> u >> v >> w;
        fares.push_back({ u,v,w });
    }

    int ans = solution(n, s, a, b, fares);
    cout << ans;
}