/*
    프로그래머스 [소수 찾기]
    https://programmers.co.kr/learn/courses/30/lessons/42839
    순열, 완전탐색
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <cmath>

using namespace std;

set<int> s;

bool isPrime(int n) {
    if (n == 0 || n == 1) return false;  // 0,1은 소수가 아님

    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) return false;
    }

    return true;
}

int solution(string numbers) {
    int answer = 0;

    sort(numbers.begin(), numbers.end());

    do {
        for (int i = 1; i <= numbers.size(); i++) {   // 문자 개수
            for (int j = 0; j <= numbers.size() - i; j++) {    // 부분문자열 시작 위치
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
