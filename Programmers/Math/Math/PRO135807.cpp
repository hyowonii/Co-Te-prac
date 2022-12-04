/*
  프로그래머스 [숫자 카드 나누기]
  https://school.programmers.co.kr/learn/courses/30/lessons/135807?language=cpp

*/

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int gcd(int a, int h) {
    while(h!=0) {
        int c = a % h;
        a = h;
        h = c;
    }
    return a;
}

int solution(vector<int> arrayA, vector<int> arrayB) {
    int answer = 0;
    
    sort(arrayA.begin(), arrayA.end());
    sort(arrayB.begin(), arrayB.end());
    int ans1=0, ans2=0;
    
    int r;
    if(arrayA.size() == 1) r = arrayA[0];
    else {
        r = gcd(arrayA[1], arrayA[0]);
        for(int i=2; i<arrayA.size(); i++) {
            r = gcd(arrayA[i], r);
        }
    }
    if(r != 1) {
        ans1 = r;
        for(int i=0; i<arrayB.size(); i++) {
            if(arrayB[i] % r == 0) {
                ans1 = 0;
                break;
            }
        }
    }
    
    int rr;
    if(arrayB.size() == 1) rr = arrayB[0];
    else {
        rr = gcd(arrayB[1], arrayB[0]);
        for(int i=2; i<arrayB.size(); i++) {
            rr = gcd(arrayB[i], rr);
        }
    }
    if(rr != 1) {
        ans2 = rr;
        for(int i=0; i<arrayA.size(); i++) {
            if(arrayA[i] % rr == 0) {
                ans2 = 0;
                break;
            }
        }
    }
    
    
    answer = max(ans1, ans2);
    
    return answer;
}