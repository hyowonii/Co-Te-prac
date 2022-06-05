/*
	프로그래머스 [네트워크]
	https://programmers.co.kr/learn/courses/30/lessons/43162
	dfs
*/

#include <string>
#include <vector>

using namespace std;

bool dfs(vector<vector<int>>& computers, int n) {
    
    if (!computers[n][n])   //이미 순회한 노드라면 리턴(재귀함수 탈출조건)
        return false;
    
    computers[n][n] = 0;    //순회했다고 변경하기
    
    for (int i = 0; i < computers.size(); i++) {
        
        if (computers[n][i])    //연결된 노드가 있다면 재귀
            dfs(computers, i);
    }

    return true;
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;

    for (int i = 0; i < n; i++) {
        
        if (computers[i][i] && dfs(computers, i))   //순회하지 않은 노드라면 dfs탐색후 answer증가
            answer++;
    }
    return answer;
}