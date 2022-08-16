/*
  프로그래머스 [다음 큰 숫자]
  https://school.programmers.co.kr/learn/courses/30/lessons/12911
  구현
*/

#include <string>
#include <vector>

using namespace std;

// 10진수 -> 2진수 변환
string getBinary(int n) {
    string result = "";
    while(n > 0) {
        int r = n % 2;
        result = to_string(r) + result;
        n /= 2;
    }
    
    return result;
}

// 1의 개수 세기
int countOnes(string &str) {
    int cnt = 0;
    for(int i=0; i<str.length(); i++) {
        if(str[i] == '1') cnt++;
    }
    
    return cnt;
}

int solution(int n) {
    int answer = 0;
    
    string str = getBinary(n);  // 이진수로 변환
    int ones = countOnes(str);  // 이진수에서 1의 개수
    
    for(int num=n+1; ; num++) {
        string newBin = getBinary(num);
        if(ones == countOnes(newBin)) {
            answer = num;
            break;
        }
    }
    
    return answer;
}