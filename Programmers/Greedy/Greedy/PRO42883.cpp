/*
    ���α׷��ӽ� [ū �� �����]
    https://programmers.co.kr/learn/courses/30/lessons/42883?language=cpp
    greedy
*/

#include <string>
#include <vector>

using namespace std;

string solution(string number, int k) {
    string answer = "";

    int n = number.length() - k;    // ������ �ϴ� �ڸ���

    for (int i = 0, idx = -1; i < n; i++) {
        char max = '0';
        for (int j = idx + 1; j <= k + i; j++) {  // k+j������ ���� �� �ִ� �ּ� �ڸ�
            if (max < number[j]) {
                max = number[j];
                idx = j;
            }
        }
        answer += max;
    }

    return answer;
}