/*
	���α׷��ӽ� [�ܼ�ī�޶�]
	https://programmers.co.kr/learn/courses/30/lessons/42884
	greedy
*/

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> routes) {
    int answer = 0;

    sort(routes.begin(), routes.end()); // *����*

    bool checked[10005] = { 0 };

    for (int i = 0; i < routes.size(); i++) {
        if (checked[i] == true) continue;
        int cura = routes[i][0];
        int curb = routes[i][1];
        for (int j = i + 1; j < routes.size(); j++) {
            if (checked[j] == true) continue;
            int newa = routes[j][0];
            int newb = routes[j][1];
            if ((cura <= newa && newa <= curb) || (cura <= newb && newb <= curb)) {   // ���� ��ġ��
                cura = max(cura, newa);
                curb = min(curb, newb);
                checked[i] = true;
                checked[j] = true;
            }
        }
        checked[i] = true;
        answer++;
    }

    return answer;
}


// �� ������ Ǯ��

int solution2(vector<vector<int>> routes) {
    //�⺻ ī�޶� 1��
    int answer = 1;
    //���� ����Ʈ ����
    sort(routes.begin(), routes.end());
    //�񱳸� ���� ó������ ������ �κ� üũ
    int temp = routes[0][1];
    //����Ʈ ��ȸ�ϱ�
    for (auto a : routes) {
        //���� ���� ������ �κк��� �ڿ� ���� ���´ٸ�
        if (temp < a[0]) {
            //ī�޶� ��ġ
            answer++;
            //������ �κ� ����
            temp = a[1];
        }
        //���� ������ ������ ���������� 
        if (temp >= a[1])    temp = a[1];// ������ �κ��� ������ ����
    }
    return answer;
}