/*
	프로그래머스 [소수 만들기]
	https://school.programmers.co.kr/learn/courses/30/lessons/12977
	배열
*/

#include <vector>
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

bool isPrime(int num) {
    if (num < 2) return false;

    for (int i = 2; i <= sqrt(num); i++) {
        if (num % i == 0) return false;
    }

    return true;
}

int solution(vector<int> nums) {
    int answer = 0;


    for (int i = 0; i < nums.size(); i++) {
        for (int j = i + 1; j < nums.size(); j++) {
            for (int k = j + 1; k < nums.size(); k++) {
                int num = nums[i] + nums[j] + nums[k];
                if (isPrime(num)) answer++;
            }
        }
    }

    return answer;
}