/*
�ڵ� ��ó
https://velog.io/@minsang96/%ED%94%84%EB%A1%9C%EA%B7%B8%EB%9E%98%EB%A8%B8%EC%8A%A4-%EB%B3%B4%EC%84%9D-%EC%87%BC%ED%95%91-C
**�����ϱ�**
*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

map<string, int> m;

vector<int> solution(vector<string> gems) {
    vector<int> answer = { 1, (int)gems.size() }; // �ε����� ���� �����Ͽ� ���� �����ϱ� ���� �ʱⰪ�� ����  
    int s = 0; //start 
    int e = 0; //end
    int distance = gems.size() - 1; // end-start�� ������ ���� ���� ������ ���ϱ� ���� ����
    map<string, int> m;
    int total;
    for (string i : gems) {
        m[i] += 1;
    }

    total = m.size(); // ������ ������ ���� ��
    m.clear(); // �� �ʱ�ȭ

    while (true) {
        if (m.size() == total) { // ��� ������ �� ���� ���
            if (e - s < distance) {
                distance = e - s;
                answer[0] = s + 1;
                answer[1] = e;  // e�� �ϳ� �����ƾ���
            }

            if (m[gems[s]] == 1) { // ������ ������ 1�� �� ��
                m.erase(gems[s]);
                s++;
            }
            else { // ������ ������ 1�� �̻��� ��
                m[gems[s]]--;
                s++;
            }
        }
        else if (e == gems.size()) // ������ Ž���� ��������
            break;
        else { // ��� ������ ���� ã�� ������ ���
            m[gems[e]]++;
            e++;
        }

    }

    return answer;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<string> gems;
    gems.push_back("DIA");
    gems.push_back("RUBY");
    gems.push_back("RUBY");
    gems.push_back("SAPPHIRE");
    //gems.push_back("EMERARD");
    gems.push_back("DIA");
    gems.push_back("RUBY");
    gems.push_back("SAPPHIRE");
    gems.push_back("DIA");

    vector<int> result = solution(gems);

    cout << result[0] << ", " << result[1];
}