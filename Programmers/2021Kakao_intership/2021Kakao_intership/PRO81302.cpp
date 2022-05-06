#include <string>
#include <vector>
#include <queue>

using namespace std;

int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,-1,0,1 };

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;

    for (auto place : places) {
        int ans = 1;    // 거리두기 지키고 있는지

        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                if (place[i][j] != 'P') continue;
                queue<pair<int, int>> Q;
                int vis[5][5] = { 0 };
                Q.push({ i,j });  // P
                vis[i][j] = 1;
                int cnt = 0;
                while (!Q.empty()) {
                    auto cur = Q.front(); Q.pop();
                    for (int k = 0; k < 4; k++) {
                        int nx = cur.first + dx[k];
                        int ny = cur.second + dy[k];
                        if (abs(i - nx) + abs(j - ny) > 2) break;
                        if (nx < 0 || nx >= 5 || ny < 0 || ny >= 5 || vis[nx][ny]) continue;
                        if (place[nx][ny] == 'X') continue;
                        if (place[nx][ny] == 'P') ans = 0;
                        Q.push({ nx,ny });
                        vis[nx][ny] = 1;
                    }
                    if (ans == 0) break;
                }
            }
        }
        answer.push_back(ans);
    }

    return answer;
}