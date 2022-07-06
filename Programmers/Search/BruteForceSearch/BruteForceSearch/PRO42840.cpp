/*
	프로그래머스 [모의고사]
	https://school.programmers.co.kr/learn/courses/30/lessons/42840
	완전탐색
*/

#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

queue<int> Q1;
queue<int> Q2;
queue<int> Q3;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    int ans1 = 0, ans2 = 0, ans3 = 0;

    for (int i = 1; i <= 5; i++) {
        Q1.push(i);
        if (i == 2) continue;
        Q2.push(2);
        Q2.push(i);
    }
    Q3.push(3); Q3.push(3);
    Q3.push(1); Q3.push(1);
    Q3.push(2); Q3.push(2);
    Q3.push(4); Q3.push(4);
    Q3.push(5); Q3.push(5);

    for (auto a : answers) {
        int num1 = Q1.front(); Q1.pop();
        int num2 = Q2.front(); Q2.pop();
        int num3 = Q3.front(); Q3.pop();
        if (num1 == a) ans1++;
        if (num2 == a) ans2++;
        if (num3 == a) ans3++;
        Q1.push(num1);
        Q2.push(num2);
        Q3.push(num3);
    }

    int max = ((ans1 >= ans2) && (ans1 >= ans3)) ? ans1 : ((ans2 >= ans1) && (ans2 >= ans3)) ? ans2 : ans3;

    if (max == ans1) answer.push_back(1);
    if (max == ans2) answer.push_back(2);
    if (max == ans3) answer.push_back(3);


    return answer;
}