/*
  프로그래머스 [최소직사각형]
  https://school.programmers.co.kr/learn/courses/30/lessons/86491
  브루트포스
*/

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int answer = 0;
    int mxOfmx=0, mxOfmn=0; // 큰 값 중 가장 큰 값, 작은 값 중 가장 큰 값을 구하기 !!
    for(auto c : sizes){
        sort(c.begin(), c.end());
        if(c[0] > mxOfmn) mxOfmn = c[0];
        if(c[1] > mxOfmx) mxOfmx = c[1];
    }
    answer = mxOfmx * mxOfmn;
    
    return answer;
}