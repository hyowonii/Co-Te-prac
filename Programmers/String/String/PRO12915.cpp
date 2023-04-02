/*
  프로그래머스 [문자열 내 마음대로 정렬하기]
  https://school.programmers.co.kr/learn/courses/30/lessons/12915
  문자열
*/

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int N;

bool comp(string a, string b){
    if(a[N] == b[N]) return a < b;
    else return a[N] < b[N];
}

vector<string> solution(vector<string> strings, int n) {

    N = n;
    sort(strings.begin(), strings.end(), comp);
    
    return strings;
}