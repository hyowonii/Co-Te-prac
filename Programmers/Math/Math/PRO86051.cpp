/*
	프로그래머스 [없는 숫자 더하기]
	https://school.programmers.co.kr/learn/courses/30/lessons/86051

*/

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> numbers) {
    int answer = 0;

    sort(numbers.begin(), numbers.end());

    for (int i = 0, j = 0; i <= 9; i++) {
        if (i == numbers[j]) {
            j++;
            continue;
        }
        answer += i;

    }

    return answer;
}