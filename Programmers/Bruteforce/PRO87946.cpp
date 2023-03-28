/*
  프로그래머스 [피로도]
  https://school.programmers.co.kr/learn/courses/30/lessons/87946
  부르트포스
*/

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(int k, vector<vector<int>> dungeons) {
    int answer = -1;
    
    vector<int> v;
    for(int i=0; i<dungeons.size(); i++)
        v.push_back(i);
    
    do{
        int cnt = 0;
        int ph = k;
        for(int i=0; i<v.size(); i++){
            int idx = v[i];
            if(ph >= dungeons[idx][0]){   // 최소 피로도만큼 있음
                cnt++;
                ph -= dungeons[idx][1];
            }
        }
        answer = max(answer, cnt);
        
    }while(next_permutation(v.begin(), v.end()));
    
    return answer;
}