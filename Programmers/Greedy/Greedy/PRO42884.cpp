/*
	프로그래머스 [단속카메라]
	https://programmers.co.kr/learn/courses/30/lessons/42884
	greedy
*/

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> routes) {
    int answer = 1;
    
    sort(routes.begin(), routes.end());
    int temp = routes[0][1];    // 엘리베이터 설치 위치 저장 변수
    
    for(int i=1; i<routes.size(); i++){
        if(temp < routes[i][0]){
            answer++;
            temp = routes[i][1];    
        }
        if(temp >= routes[i][1])
            temp = routes[i][1];
    }
    
    return answer;
}