#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

vector<int> solution(int m, int n, vector<vector<int>> picture) {
    int number_of_area = 0;
    int max_size_of_one_area = 0;

    bool vis[100][100];
    int dx[4] = { 0, -1, 0 ,1 };
    int dy[4] = { -1, 0, 1, 0 };

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (picture[i][j] == 0 || vis[i][j]) continue;
            int color = picture[i][j];
            number_of_area++;
            vis[i][j] = 1;
            queue<pair<int, int>> Q;

            //bfs
            Q.push({ i,j });
            int area = 0;
            while (!Q.empty()) {
                pair<int, int> cur = Q.front(); Q.pop();
                area++;
                for (int k = 0; k < 4; k++) {
                    int nx = cur.first + dx[k];
                    int ny = cur.second + dy[k];
                    if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
                    if (picture[nx][ny] != color || vis[nx][ny]) continue;
                    vis[nx][ny] = 1;
                    Q.push({ nx, ny });
                }
            }
            max_size_of_one_area = max(max_size_of_one_area, area);
        }
    }

    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    return answer;
}

int main(void) {
    int m, n;
    cin >> m >> n;
    vector<vector<int>> picture(m, vector<int>(n));
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            cin >> picture[i][j];
    auto answer = solution(m, n, picture);
    cout << answer[0] << " " << answer[1];
    return 0;
}