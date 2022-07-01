/*
	���α׷��ӽ� [�Ա��ɻ�]
	https://programmers.co.kr/learn/courses/30/lessons/43238
	����Ž��
	����ũ) https://0xd00d00.github.io/2021/06/29/programmers_entry_test.html
*/

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(int n, vector<int> times) {
    long long answer = 0;
    sort(times.begin(), times.end());

    long long st = 1;
    long long en = n * (long long)times.back(); // �ִ� �ذ� �ð�

    // ����Ž��
    while (st <= en) {
        long long tmp = 0;
        long long mid = (st + en) / 2;
        for (auto p : times) {
            tmp += mid / (long long)p;
        }
        if (tmp >= n) {
            en = mid - 1;
            answer = mid;   // �ð�
        }
        else {
            st = mid + 1;
        }

    }

    return answer;
}