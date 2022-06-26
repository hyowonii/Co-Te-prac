/*
	���α׷��ӽ� [����Ʈ�ٹ�]
	https://programmers.co.kr/learn/courses/30/lessons/42579
	�ؽ�
*/

#include <string>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;

    int len = genres.size();    // ��ü ����

    // �帣 ���Ƚ�� ����
    map<string, int> m1;
    string max_played;
    for (int i = 0; i < len; i++) {
        m1[genres[i]] += plays[i];
    }
    map<int, string, greater<int>> m2;
    for (auto m : m1) {
        m2.insert({ m.second, m.first });
    }
    queue<string> q;
    for (auto m : m2) q.push(m.second);

    // �帣���� ���鼭
    while (!q.empty()) {
        vector<pair<int, int>> v;
        string genre = q.front(); q.pop();
        for (int i = 0; i < len; i++) {
            if (genres[i] == genre) {
                v.push_back({ plays[i], i });
            }
        }
        sort(v.rbegin(), v.rend());

        if (v.size() == 1) {
            answer.push_back(v[0].second);
            continue;
        }

        if (v[0].first == v[1].first) {
            answer.push_back(min(v[0].second, v[1].second));
            answer.push_back(max(v[0].second, v[1].second));
        }
        else {
            answer.push_back(v[0].second);
            answer.push_back(v[1].second);
        }
    }


    return answer;
}