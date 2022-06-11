/*
    ���α׷��ӽ� [���]
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

    for (int i = 0; i < puddles.size(); i++) {    // ��������
        dp[puddles[i][0]][puddles[i][1]] = -1;
    }

    // ������ Ȯ�� ���� �� �ִܰŸ� ���� Ǯ �� ���ڸ� �� ������ 1�� ���ϸ鼭 ������ �´� ��ó��
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            int a = 0, b = 0;

            if (dp[i][j] == -1) continue;   // �������� �н�
            if (dp[i - 1][j] != -1) a = dp[i - 1][j];
            if (dp[i][j - 1] != -1) b = dp[i][j - 1];

            dp[i][j] += (a + b) % 1000000007;
        }
    }

    return dp[m][n];
}