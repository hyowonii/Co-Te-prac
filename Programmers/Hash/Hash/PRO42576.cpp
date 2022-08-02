/*
	프로그래머스 [완주하지 못한 선수]
	https://school.programmers.co.kr/learn/courses/30/lessons/42576
	해시
*/

#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>    // 해시맵 사용

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";

    // 1.
    sort(participant.begin(), participant.end());
    sort(completion.begin(), completion.end());

    for (int i = 0; i < participant.size(); i++) {
        if (participant[i] != completion[i]) {
            answer = participant[i];
            break;
        }
    }

    // 2. 해시
    unordered_map<string, int> temp;
    for (string name : participant) {
        temp[name]++;
    }
    for (string name : completion) {
        temp[name]--;
    }

    for (auto pair : temp) {
        if (pair.second > 0) {
            answer = pair.first;
            break;
        }
    }


    return answer;
}