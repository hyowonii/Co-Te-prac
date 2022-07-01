/*
	프로그래머스 [입국심사]
	https://programmers.co.kr/learn/courses/30/lessons/43238
	이진탐색
	참고링크) https://0xd00d00.github.io/2021/06/29/programmers_entry_test.html
*/

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(int n, vector<int> times) {
    long long answer = 0;
    sort(times.begin(), times.end());

    long long st = 1;
    long long en = n * (long long)times.back(); // 최대 해결 시간

    // 이진탐색
    while (st <= en) {
        long long tmp = 0;
        long long mid = (st + en) / 2;
        for (auto p : times) {
            tmp += mid / (long long)p;
        }
        if (tmp >= n) {
            en = mid - 1;
            answer = mid;   // 시간
        }
        else {
            st = mid + 1;
        }

    }

    return answer;
}