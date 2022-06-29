/*
	백준 [잃어버린 괄호]
	https://www.acmicpc.net/problem/1541
	그리디
*/

#include <iostream>
#include <vector>

using namespace std;

int tmp, ans;
int sign = 1;
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string input;
    cin >> input;
    for (char c : input) {
        if (c == '+' || c == '-') {
            ans += tmp * sign;
            if (c == '-') sign = -1;    // 마이너스가 나온 후로는 모두 뺄 수 있음
            tmp = 0;
        }
        else {
            tmp *= 10;
            tmp += c - '0';
        }
    }
    ans += tmp * sign;
    cout << ans;
}