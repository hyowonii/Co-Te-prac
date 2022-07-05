/*
	프로그래머스 [K번째수]
	https://school.programmers.co.kr/learn/courses/30/lessons/42748
	정렬
*/

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;

    for (auto c : commands) {
        int s = c[0];
        int e = c[1];
        int n = c[2];
        vector<int> newArr;
        for (int i = s - 1; i < e; i++) newArr.push_back(array[i]);
        sort(newArr.begin(), newArr.end());
        answer.push_back(newArr[n - 1]);
    }

    return answer;
}