/*
	���α׷��ӽ� [����ä�ù�]
	https://school.programmers.co.kr/learn/courses/30/lessons/42888
	���ڿ�
*/

#include <string>
#include <vector>
#include <sstream>
#include <map>

using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;

    map<string, string> id_name;

    vector<vector<string>> all;
    for (auto p : record) {
        stringstream ss(p);
        ss.str(p);
        vector<string> list;
        string word;
        while (ss >> word) {
            list.push_back(word);
        }

        string state = list[0];

        if (state == "Enter" || state == "Change")
            id_name[list[1]] = list[2];

        if (state == "Enter" || state == "Leave")
            all.push_back(list);
    }

    for (auto list : all) {

        string result = "";
        if (list[0] == "Enter") {
            result = id_name[list[1]] + "���� ���Խ��ϴ�.";
        }
        else if (list[0] == "Leave") {
            result = id_name[list[1]] + "���� �������ϴ�.";
        }
        answer.push_back(result);
    }

    return answer;
}