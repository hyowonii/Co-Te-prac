/*
	프로그래머스 [단체사진 찍기]
	https://programmers.co.kr/learn/courses/30/lessons/1835
	순열
*/

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int n, vector<string> data) {
    int answer = 0;
    string friends = "ACFJMNRT";

    do {
        bool flag = true;
        for (int i = 0; i < n; i++) {
            int idx1 = 0, idx2 = 0;

            for (int j = 0; j < friends.size(); j++) {
                if (data[i][0] == friends[j]) idx1 = j;
                if (data[i][2] == friends[j]) idx2 = j;
            }

            int gap = data[i][4] - '0';
            int len = abs(idx1 - idx2) - 1;

            if (data[i][3] == '=') {
                if (len == gap) continue;
                else {
                    flag = false;
                    break;
                }
            }
            else if (data[i][3] == '>') {
                if (len > gap) continue;
                else {
                    flag = false;
                    break;
                }
            }
            else {
                if (len < gap) continue;
                else {
                    flag = false;
                    break;
                }
            }
        }

        if (flag == true) answer++;

    } while (next_permutation(friends.begin(), friends.end()));

    return answer;
}