#include <iostream>
#include <string>
#include <vector>

using namespace std;

string num[10] = { "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };
string check = "0123456789";

int solution(string s) {
    int answer = 0;
    string ans_s = "";

    string letter = "";
    for (int i = 0; i < s.size(); i++) {
        cout << "ans_s: " << ans_s << "\n";
        letter += s[i];
        cout << letter << "\n";
        if (isdigit(s[i])) {
            ans_s += letter[0];
            letter = "";
            continue;
        }
        for (int j = 0; j < 10; j++) {
            if (letter == num[j]) {
                ans_s += (char)(j + 48);
                letter = "";
            }
        }
    }
    answer = stoi(ans_s);

    return answer;
}

int main(void) {
    string s;
    cin >> s;

    int answer = solution(s);

    cout << answer;
}