#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <cmath>

using namespace std;

set<int> s;

bool isPrime(int n) {
    if (n == 0 || n == 1) return false;  // 0,1�� �Ҽ��� �ƴ�

    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) return false;
    }

    return true;
}

int solution(string numbers) {
    int answer = 0;

    sort(numbers.begin(), numbers.end());

    do {
        for (int i = 1; i <= numbers.size(); i++) {   // ���� ����
            for (int j = 0; j <= numbers.size() - i; j++) {    // �κй��ڿ� ���� ��ġ
                string ss = numbers.substr(j, i);
                int num = stoi(ss);
                cout << num << "\n";
                if (isPrime(num)) s.insert(num);

            }
        }
    } while (next_permutation(numbers.begin(), numbers.end()));



    answer = s.size();
    return answer;
}