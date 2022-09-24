/*
  프로그래머스 [양과 늑대]
  https://school.programmers.co.kr/learn/courses/30/lessons/92343
  dfs
*/

#include <string>
#include <vector>

using namespace std;

int dfs(int now, int sheep, int wolf, vector<int> nextNode, int count, vector<int> info, vector<vector<int>> &tree) {
    
    if(info[now] == 0) sheep++;
    else wolf++;
    count = max(count, sheep);
    if(wolf >= sheep) return count;
    
    // 현재 방문 가능한 노드들을 순차적으로 방문
    for(int i=0; i<nextNode.size(); i++) {
        
        // 현재 방문한 노드에서 방문할 수 있는 다음 노드들 (다시 돌아갈 수도 있음)
        vector<int> next = nextNode;
        next.erase(next.begin()+i);
        for(int j=0; j<tree[nextNode[i]].size(); j++) {
            next.push_back(tree[nextNode[i]][j]);
        }
        
        count = dfs(nextNode[i], sheep, wolf, next, count, info, tree);
    }
    
    return count;   // 현재 방문가능한 노드들을 모두 방문하면 리턴
}

int solution(vector<int> info, vector<vector<int>> edges) {
    int answer = 0;
    
    // 간선 트리 만들기
    vector<vector<int>> tree(info.size());
    for(int i=0; i<edges.size(); i++) {
        tree[edges[i][0]].push_back(edges[i][1]);
    }
    
    // 다음에 방문 가능한 노드들
    vector<int> nextNode;
    // 루트 노드(0)부터 시작
    for(int i=0; i<tree[0].size(); i++) {
        nextNode.push_back(tree[0][i]);
    }
    
    answer = dfs(0, 0, 0, nextNode, answer, info, tree);
    
    
    return answer;
}