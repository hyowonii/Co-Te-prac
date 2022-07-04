/*
	프로그래머스 [가장 먼 노드]
	https://programmers.co.kr/learn/courses/30/lessons/49189
	그래프
*/

#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;

    bool check[20001][20001] = { false, };
    bool visited[20001] = { false, };
    int dist[20001] = { 0, };

    sort(edge.begin(), edge.end());

    for (int i = 0; i < edge.size(); i++) {
        check[edge[i][0]][edge[i][1]] = true;
        check[edge[i][1]][edge[i][0]] = true;
    }

    int mx = 0;    // 최종 최대값 갖는 노드의 개수 => answer

    queue<int> Q;
    Q.push(1);
    visited[1] = true;
    while (!Q.empty()) {
        int head = Q.front(); Q.pop();
        for (int i = 2; i <= n; i++) {
            if (check[head][i] == true && !visited[i]) {
                Q.push(i);
                visited[i] = true;
                dist[i] = dist[head] + 1;

                mx = max(mx, dist[i]);
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        if (dist[i] == mx) answer++;
    }


    return answer;
}