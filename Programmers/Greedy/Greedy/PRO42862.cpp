/*
  프로그래머스 [체육복]
  https://school.programmers.co.kr/learn/courses/30/lessons/42862
  greedy
*/

#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    
    // ! 학생마다 가지고 있는 체육복의 개수를 배열에 나타내기
    
    vector<int> clothes(n+2, 1);
    
    for(auto c : lost) {    // 체육복 잃어버림
        clothes[c]--;
    }
    for(auto c : reserve) {     // 체육복 여분 가짐
        clothes[c]++;
    }
    
    for(int i=1; i<=n; i++) {
        
        // 체육복 있으면
        if(clothes[i]) continue;    
        
        // 체육복 없으면
        if(clothes[i-1] == 2) {     // 앞사람이 여분 체육복 있으면
            clothes[i-1]--;
            clothes[i]++;
        }
        else if(clothes[i+1] == 2) {    // 뒷사람이 여분 체육복 있으면
            clothes[i+1]--;
            clothes[i]++;
        }
    }
    
    // 체육복 1개 이상인 학생 수 세기 (clothes 개수를 n+2로 잡았으므로 auto로 받아와서 개수 세면 틀림)
    for(int i=1; i<=n; i++) {
        if(clothes[i]) answer++;
    }
    
    
    return answer;
}