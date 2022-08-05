/*
	프로그래머스 [프린터]
	https://school.programmers.co.kr/learn/courses/30/lessons/42587
	queue
*/

#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0, cnt = 0;

    queue<pair<int, int>> q;
    priority_queue<int> pq;

    for (int i = 0; i < priorities.size(); i++) {
        q.push(make_pair(i, priorities[i]));
        pq.push(priorities[i]);
    }

    while (!q.empty()) {
        int index = q.front().first;
        int value = q.front().second;
        q.pop();
        if (pq.top() == value) {
            pq.pop();
            cnt++;
            if (index == location) {
                answer = cnt;
                break;
            }
        }
        else {
            q.push(make_pair(index, value));    // 맨 뒤에 삽입
        }
    }

    return answer;
}