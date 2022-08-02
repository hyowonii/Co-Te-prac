/*
	���α׷��ӽ� [�������� ���� ����]
	https://school.programmers.co.kr/learn/courses/30/lessons/42576
	�ؽ�
*/

#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>    // �ؽø� ���

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

    // 2. �ؽ�
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