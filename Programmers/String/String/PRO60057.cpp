/*
	���α׷��ӽ� [���ڿ� ����]
	https://programmers.co.kr/learn/courses/30/lessons/60057
	���ڿ�
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 0;
    answer = s.length();

    for (int n = 1; n <= s.length() / 2; n++) { // �ܾ� ���� ����(����)
        int i = 0;  // �ε���
        int cnt = 1;
        string result = "";
        string part1;
        string part2;
        while (i < s.length() && i + 2 * n <= s.length()) {
            part1 = s.substr(i, n); // i��°���� ���� n��ŭ ����
            part2 = s.substr(i + n, n);
            if (part1 == part2) {
                cnt++;
                i += n;
            }
            else {
                if (cnt > 1) result += to_string(cnt);
                result += part1;
                i += n;
                cnt = 1;
            }
        }

        if (cnt > 1) result += to_string(cnt);
        result += s.substr(i, s.length() - i);
      
        if (result.length() < answer) answer = result.length();
        //cout << "n: " << n << ", result: " << result << "\n";

    }

    return answer;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s;
    cin >> s;
    int answer = solution(s);
    cout << answer;
}