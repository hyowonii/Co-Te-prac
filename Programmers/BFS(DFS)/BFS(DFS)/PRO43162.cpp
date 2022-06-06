/*
	���α׷��ӽ� [��Ʈ��ũ]
	https://programmers.co.kr/learn/courses/30/lessons/43162
	dfs
*/

#include <string>
#include <vector>

using namespace std;

bool dfs(vector<vector<int>>& computers, int n) {
    
    if (!computers[n][n])   //�̹� ��ȸ�� ����� ����(����Լ� Ż������)
        return false;
    
    computers[n][n] = 0;    //��ȸ�ߴٰ� �����ϱ�
    
    for (int i = 0; i < computers.size(); i++) {
        
        if (computers[n][i])    //����� ��尡 �ִٸ� ���
            dfs(computers, i);
    }

    return true;
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;

    for (int i = 0; i < n; i++) {
        
        if (computers[i][i] && dfs(computers, i))   //��ȸ���� ���� ����� dfsŽ���� answer����
            answer++;
    }
    return answer;
}