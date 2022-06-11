/*
    프로그래머스 [등굣길]
    https://programmers.co.kr/learn/courses/30/lessons/42898
    dp
*/

#include <string>
#include <vector>

using namespace std;

int dp[105][105];

int solution(int m, int n, vector<vector<int>> puddles) {
    // int answer = 0;

    dp[1][1] = 1;

    for (int i = 0; i < puddles.size(); i++) {    // 물웅덩이
        dp[puddles[i][0]][puddles[i][1]] = -1;
    }

    // 예전에 확통 문제 중 최단거리 문제 풀 때 한자리 갈 때마다 1씩 더하면서 최종값 냈던 것처럼
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            int a = 0, b = 0;

            if (dp[i][j] == -1) continue;   // 물웅덩이 패스
            if (dp[i - 1][j] != -1) a = dp[i - 1][j];
            if (dp[i][j - 1] != -1) b = dp[i][j - 1];

            dp[i][j] += (a + b) % 1000000007;
        }
    }

    return dp[m][n];
}