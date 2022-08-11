/*
  프로그래머스 [2 x n 타일링]
  https://school.programmers.co.kr/learn/courses/30/lessons/12900
  피보나치 수열
*/

#include <string>
#include <vector>
#define MOD 1000000007

using namespace std;

int solution(int n) {
    int answer = 0;
    
    // 피보나치 수열 활용
    int pibo[60002] = {0};
    pibo[1] = 1;
    pibo[2] = 2;
    
    for(int i=3; i<=n; i++) {
        pibo[i] = (pibo[i-1]+pibo[i-2]) % MOD;
    }
    answer = pibo[n] % MOD;
    
    return answer;
}