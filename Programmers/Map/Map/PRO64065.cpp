/*
	프로그래머스 [튜플]
	https://school.programmers.co.kr/learn/courses/30/lessons/64065
	map
*/

#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer;

    map<int, vector<int>> m;
    // string -> 벡터로
    string num = "";
    vector<int> temp;
    for (auto c : s) {
        if (c == '{') continue;
        else if (c == ',') {
            if (num == "") continue;
            temp.push_back(stoi(num));
            num = "";
        }
        else if (c == '}') {
            if (num == "") continue;
            temp.push_back(stoi(num));
            m[temp.size()] = temp;
            // m.insert({temp.size(), temp});
            num = "";
            temp.clear();
        }
        else num += c;
    }

    for (int i = 1; i <= m.size(); i++) {
        for (auto i : m[i]) {
            if (find(answer.begin(), answer.end(), i) != answer.end()) continue; // 이미 원소가 있으면
            answer.push_back(i);
        }
    }



    return answer;
}