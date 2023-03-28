/*
  프로그래머스 [전력망을 둘로 나누기]
  https://school.programmers.co.kr/learn/courses/30/lessons/86971
  부르트포스
*/

#include <string>
#include <vector>

using namespace std;

vector<int> m[101];

int bfs(int togo, int cur, int cnt){
    for(int i=0; i<m[cur].size(); i++){
        if(m[cur][i] != togo){
            cnt = bfs(cur, m[cur][i], cnt+1);
        }
    }
    return cnt;
}

int solution(int n, vector<vector<int>> wires) {
    int answer = 1000;
    
    for(auto w : wires){
        m[w[0]].push_back(w[1]);
        m[w[1]].push_back(w[0]);
    }
    
    for(auto w : wires){
        int sum = bfs(w[0], w[1], 1);
        int sub = n - (2 * sum);
        answer = min(answer, abs(sub));
    }
    
    return answer;
}