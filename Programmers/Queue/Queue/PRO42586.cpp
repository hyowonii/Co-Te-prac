/*
	프로그래머스 [기능개발]
	https://school.programmers.co.kr/learn/courses/30/lessons/42586
	큐
*/

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;

    queue<int> Q;
    for (int i = 0; i < progresses.size(); i++) {
        int date = 0;
        int left = 100 - progresses[i];
        date = ceil((double)left / (double)speeds[i]);  // double!!
        Q.push(date);
    }

    int publish = Q.front(); Q.pop();
    answer.push_back(1);
    while (!Q.empty()) {
        int nxt = Q.front(); Q.pop();
        if (nxt <= publish) answer.back()++;
        else {
            answer.push_back(1);
            publish = nxt;
        }
    }

    return answer;
}