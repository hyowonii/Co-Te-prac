#include <iostream>
#include <stack>
#include <map>
#include <set>
using namespace std;

//괄호의 짝을 저장할 맵
map<char, char> bracket;

//괄호가 균형을 이루었는지 확인하는 함수
bool isBalanced(string input) {
    stack<char> s;

    for (int i = 0; i < input.size(); i++) {
        switch (input[i]) {
        case '(': case '[': //왼쪽 괄호
            s.push(input[i]);
            break;
        case ')': case ']': //오른쪽 괄호
            if (s.empty() || s.top() != bracket[input[i]])
                return false;
            s.pop();
            break;
        }

    }

    return s.empty();
}

int main() {
    string input;
    bracket[')'] = '(';
    bracket[']'] = '[';
    int result = 0;
    cin >> input;

    for (int i = 0; i < input.length(); i++) {
        string new_string = input;
        new_string = new_string.erase(i, 1);

        //cout << new_string<<"\n";

        if (isBalanced(new_string)) {

            result++;
        }


    }

    cout << result;

}