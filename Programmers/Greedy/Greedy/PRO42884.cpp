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
    int answer = 0;

    sort(routes.begin(), routes.end()); // *정렬*

    bool checked[10005] = { 0 };

    for (int i = 0; i < routes.size(); i++) {
        if (checked[i] == true) continue;
        int cura = routes[i][0];
        int curb = routes[i][1];
        for (int j = i + 1; j < routes.size(); j++) {
            if (checked[j] == true) continue;
            int newa = routes[j][0];
            int newb = routes[j][1];
            if ((cura <= newa && newa <= curb) || (cura <= newb && newb <= curb)) {   // 범위 겹치면
                cura = max(cura, newa);
                curb = min(curb, newb);
                checked[i] = true;
                checked[j] = true;
            }
        }
        checked[i] = true;
        answer++;
    }

    return answer;
}


// 더 간단한 풀이

int solution2(vector<vector<int>> routes) {
    //기본 카메라 1대
    int answer = 1;
    //들어온 리스트 정렬
    sort(routes.begin(), routes.end());
    //비교를 위해 처음차가 나가는 부분 체크
    int temp = routes[0][1];
    //리스트 순회하기
    for (auto a : routes) {
        //현재 차가 나가는 부분보다 뒤에 차가 들어온다면
        if (temp < a[0]) {
            //카메라 설치
            answer++;
            //나가는 부분 정정
            temp = a[1];
        }
        //현재 차보다 뒤차가 먼저나가면 
        if (temp >= a[1])    temp = a[1];// 나가는 부분을 뒷차로 수정
    }
    return answer;
}