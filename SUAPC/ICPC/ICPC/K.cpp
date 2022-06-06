#include <iostream>
#include <stack>
#include <map>
#include <set>
using namespace std;

//��ȣ�� ¦�� ������ ��
map<char, char> bracket;

//��ȣ�� ������ �̷������ Ȯ���ϴ� �Լ�
bool isBalanced(string input) {
    stack<char> s;

    for (int i = 0; i < input.size(); i++) {
        switch (input[i]) {
        case '(': case '[': //���� ��ȣ
            s.push(input[i]);
            break;
        case ')': case ']': //������ ��ȣ
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